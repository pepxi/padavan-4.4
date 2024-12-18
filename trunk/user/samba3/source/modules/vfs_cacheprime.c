/*
 * Copyright (c) James Peach 2005-2006
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "includes.h"

/* Cache priming module.
 *
 * The purpose of this module is to do RAID stripe width reads to prime the
 * buffer cache to do zero-copy I/O for subsequent sendfile calls. The idea is
 * to do a single large read at the start of the file to make sure that most or
 * all of the file is pulled into the buffer cache. Subsequent I/Os have
 * reduced latency.
 *
 * Tunables.
 *
 *      cacheprime:rsize    Amount of readahead in bytes. This should be a
 *                          multiple of the RAID stripe width.
 *      cacheprime:debug    Debug level at which to emit messages.
 */

#define READAHEAD_MIN       (128 * 1024)        /* min is 128 KiB */
#define READAHEAD_MAX       (100 * 1024 * 1024) /* max is 100 MiB */

#define MODULE "cacheprime"

static int module_debug;
static ssize_t g_readsz = 0;
static void * g_readbuf = NULL;

/* Prime the kernel buffer cache with data from the specified file. We use
 * per-fsp data to make sure we only ever do this once. If pread is being
 * emulated by seek/read/seek, when this will suck quite a lot.
 */
static BOOL prime_cache(
            struct vfs_handle_struct *  handle,
			files_struct *		        fsp,
			int			                fd,
			SMB_OFF_T		            offset,
			size_t			            count)
{
        SMB_OFF_T * last;
        ssize_t nread;

        last = VFS_ADD_FSP_EXTENSION(handle, fsp, SMB_OFF_T);
        if (!last) {
                return False;
        }

        if (*last == -1) {
            /* Readahead disabled. */
            return False;
        }

        if ((*last + g_readsz) > (offset + count)) {
            /* Skip readahead ... we've already been here. */
            return False;
        }

        DEBUG(module_debug,
            ("%s: doing readahead of %lld bytes at %lld for %s\n",
            MODULE, (long long)g_readsz, (long long)*last,
            fsp->fsp_name));

        nread = sys_pread(fd, g_readbuf, g_readsz, *last);
        if (nread < 0) {
            *last = -1;
            return False;
        }

        *last += nread;
        return True;
}

static int cprime_connect(
                struct vfs_handle_struct *  handle,
                const char *                service,
                const char *                user)
{
        module_debug = lp_parm_int(SNUM(handle->conn), MODULE, "debug", 100);
        if (g_readbuf) {
                /* Only allocate g_readbuf once. If the config changes and
                 * another client multiplexes onto this smbd, we don't want
                 * to risk memory corruption.
                 */
                return SMB_VFS_NEXT_CONNECT(handle, service, user);
        }

        g_readsz = conv_str_size(lp_parm_const_string(SNUM(handle->conn),
                                        MODULE, "rsize", NULL));

        if (g_readsz < READAHEAD_MIN) {
                DEBUG(module_debug, ("%s: %ld bytes of readahead "
                            "requested, using minimum of %u\n",
                            MODULE, (long)g_readsz, READAHEAD_MIN));
                g_readsz = READAHEAD_MIN;
        } else if (g_readsz > READAHEAD_MAX) {
                DEBUG(module_debug, ("%s: %ld bytes of readahead "
                            "requested, using maximum of %u\n",
                            MODULE, (long)g_readsz, READAHEAD_MAX));
                g_readsz = READAHEAD_MAX;
        }

        if ((g_readbuf = SMB_MALLOC(g_readsz)) == NULL) {
                /* Turn off readahead if we can't get a buffer. */
                g_readsz = 0;
        }

        return SMB_VFS_NEXT_CONNECT(handle, service, user);
}

static ssize_t cprime_sendfile(
                struct vfs_handle_struct *  handle,
                int                         tofd,
                files_struct *              fsp,
                int                         fromfd,
                const DATA_BLOB *           header,
                SMB_OFF_T                   offset,
                size_t                      count)
{
        if (g_readbuf && offset == 0) {
                prime_cache(handle, fsp, fromfd, offset, count);
        }

        return SMB_VFS_NEXT_SENDFILE(handle, tofd, fsp, fromfd,
                                     header, offset, count);
}

static ssize_t cprime_read(
                vfs_handle_struct * handle,
                files_struct *      fsp,
                int                 fd,
                void *              data,
                size_t              count)
{
        SMB_OFF_T offset;

        offset = SMB_VFS_LSEEK(fsp, fd, 0, SEEK_CUR);
        if (offset >= 0 && g_readbuf)  {
                prime_cache(handle, fsp, fd, offset, count);
                SMB_VFS_LSEEK(fsp, fd, offset, SEEK_SET);
        }

        return SMB_VFS_NEXT_READ(handle, fsp, fd, data, count);
}

static ssize_t cprime_pread(
                vfs_handle_struct * handle,
                files_struct *      fsp,
                int                 fd,
                void *              data,
		        size_t              count,
                SMB_OFF_T           offset)
{
        if (g_readbuf) {
                prime_cache(handle, fsp, fd, offset, count);
        }

        return SMB_VFS_NEXT_PREAD(handle, fsp, fd, data, count, offset);
}

static vfs_op_tuple cprime_ops [] =
{
        {SMB_VFS_OP(cprime_sendfile),
                SMB_VFS_OP_SENDFILE, SMB_VFS_LAYER_TRANSPARENT},
        {SMB_VFS_OP(cprime_pread),
                SMB_VFS_OP_PREAD, SMB_VFS_LAYER_TRANSPARENT},
        {SMB_VFS_OP(cprime_read),
                SMB_VFS_OP_READ, SMB_VFS_LAYER_TRANSPARENT},
        {SMB_VFS_OP(cprime_connect),
                SMB_VFS_OP_CONNECT,  SMB_VFS_LAYER_TRANSPARENT},

        {SMB_VFS_OP(NULL), SMB_VFS_OP_NOOP, SMB_VFS_LAYER_NOOP}
};

/* -------------------------------------------------------------------------
 * Samba module initialisation entry point.
 * -------------------------------------------------------------------------
 */

NTSTATUS vfs_cacheprime_init(void);
NTSTATUS vfs_cacheprime_init(void)
{
    return smb_register_vfs(SMB_VFS_INTERFACE_VERSION, MODULE, cprime_ops);
}

/* vim: set sw=4 ts=4 tw=79 et: */
