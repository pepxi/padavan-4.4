/* parser auto-generated by pidl */

#include "includes.h"
#include "librpc/gen_ndr/ndr_notify.h"

_PUBLIC_ NTSTATUS ndr_push_notify_entry(struct ndr_push *ndr, int ndr_flags, const struct notify_entry *r)
{
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_push_align(ndr, 8));
		NDR_CHECK(ndr_push_server_id(ndr, NDR_SCALARS, &r->server));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->filter));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->subdir_filter));
		{
			uint32_t _flags_save_string = ndr->flags;
			ndr_set_flags(&ndr->flags, LIBNDR_FLAG_STR_UTF8|LIBNDR_FLAG_STR_NULLTERM);
			NDR_CHECK(ndr_push_string(ndr, NDR_SCALARS, r->path));
			ndr->flags = _flags_save_string;
		}
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->path_len));
		NDR_CHECK(ndr_push_pointer(ndr, NDR_SCALARS, r->private_data));
	}
	if (ndr_flags & NDR_BUFFERS) {
		NDR_CHECK(ndr_push_server_id(ndr, NDR_BUFFERS, &r->server));
	}
	return NT_STATUS_OK;
}

_PUBLIC_ NTSTATUS ndr_pull_notify_entry(struct ndr_pull *ndr, int ndr_flags, struct notify_entry *r)
{
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_pull_align(ndr, 8));
		NDR_CHECK(ndr_pull_server_id(ndr, NDR_SCALARS, &r->server));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->filter));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->subdir_filter));
		{
			uint32_t _flags_save_string = ndr->flags;
			ndr_set_flags(&ndr->flags, LIBNDR_FLAG_STR_UTF8|LIBNDR_FLAG_STR_NULLTERM);
			NDR_CHECK(ndr_pull_string(ndr, NDR_SCALARS, &r->path));
			ndr->flags = _flags_save_string;
		}
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->path_len));
		NDR_CHECK(ndr_pull_pointer(ndr, NDR_SCALARS, &r->private_data));
	}
	if (ndr_flags & NDR_BUFFERS) {
		NDR_CHECK(ndr_pull_server_id(ndr, NDR_BUFFERS, &r->server));
	}
	return NT_STATUS_OK;
}

_PUBLIC_ void ndr_print_notify_entry(struct ndr_print *ndr, const char *name, const struct notify_entry *r)
{
	ndr_print_struct(ndr, name, "notify_entry");
	ndr->depth++;
	ndr_print_server_id(ndr, "server", &r->server);
	ndr_print_uint32(ndr, "filter", r->filter);
	ndr_print_uint32(ndr, "subdir_filter", r->subdir_filter);
	ndr_print_string(ndr, "path", r->path);
	ndr_print_uint32(ndr, "path_len", r->path_len);
	ndr_print_pointer(ndr, "private_data", r->private_data);
	ndr->depth--;
}

NTSTATUS ndr_push_notify_depth(struct ndr_push *ndr, int ndr_flags, const struct notify_depth *r)
{
	uint32_t cntr_entries_0;
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_push_align(ndr, 8));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->max_mask));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->max_mask_subdir));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->num_entries));
		for (cntr_entries_0 = 0; cntr_entries_0 < r->num_entries; cntr_entries_0++) {
			NDR_CHECK(ndr_push_notify_entry(ndr, NDR_SCALARS, &r->entries[cntr_entries_0]));
		}
	}
	if (ndr_flags & NDR_BUFFERS) {
		for (cntr_entries_0 = 0; cntr_entries_0 < r->num_entries; cntr_entries_0++) {
			NDR_CHECK(ndr_push_notify_entry(ndr, NDR_BUFFERS, &r->entries[cntr_entries_0]));
		}
	}
	return NT_STATUS_OK;
}

NTSTATUS ndr_pull_notify_depth(struct ndr_pull *ndr, int ndr_flags, struct notify_depth *r)
{
	uint32_t cntr_entries_0;
	TALLOC_CTX *_mem_save_entries_0;
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_pull_align(ndr, 8));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->max_mask));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->max_mask_subdir));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->num_entries));
		NDR_PULL_ALLOC_N(ndr, r->entries, r->num_entries);
		_mem_save_entries_0 = NDR_PULL_GET_MEM_CTX(ndr);
		NDR_PULL_SET_MEM_CTX(ndr, r->entries, 0);
		for (cntr_entries_0 = 0; cntr_entries_0 < r->num_entries; cntr_entries_0++) {
			NDR_CHECK(ndr_pull_notify_entry(ndr, NDR_SCALARS, &r->entries[cntr_entries_0]));
		}
		NDR_PULL_SET_MEM_CTX(ndr, _mem_save_entries_0, 0);
	}
	if (ndr_flags & NDR_BUFFERS) {
		_mem_save_entries_0 = NDR_PULL_GET_MEM_CTX(ndr);
		NDR_PULL_SET_MEM_CTX(ndr, r->entries, 0);
		for (cntr_entries_0 = 0; cntr_entries_0 < r->num_entries; cntr_entries_0++) {
			NDR_CHECK(ndr_pull_notify_entry(ndr, NDR_BUFFERS, &r->entries[cntr_entries_0]));
		}
		NDR_PULL_SET_MEM_CTX(ndr, _mem_save_entries_0, 0);
	}
	return NT_STATUS_OK;
}

_PUBLIC_ void ndr_print_notify_depth(struct ndr_print *ndr, const char *name, const struct notify_depth *r)
{
	uint32_t cntr_entries_0;
	ndr_print_struct(ndr, name, "notify_depth");
	ndr->depth++;
	ndr_print_uint32(ndr, "max_mask", r->max_mask);
	ndr_print_uint32(ndr, "max_mask_subdir", r->max_mask_subdir);
	ndr_print_uint32(ndr, "num_entries", r->num_entries);
	ndr->print(ndr, "%s: ARRAY(%d)", "entries", r->num_entries);
	ndr->depth++;
	for (cntr_entries_0=0;cntr_entries_0<r->num_entries;cntr_entries_0++) {
		char *idx_0=NULL;
		asprintf(&idx_0, "[%d]", cntr_entries_0);
		if (idx_0) {
			ndr_print_notify_entry(ndr, "entries", &r->entries[cntr_entries_0]);
			free(idx_0);
		}
	}
	ndr->depth--;
	ndr->depth--;
}

_PUBLIC_ NTSTATUS ndr_push_notify_array(struct ndr_push *ndr, int ndr_flags, const struct notify_array *r)
{
	uint32_t cntr_depth_0;
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_push_align(ndr, 8));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->num_depths));
		for (cntr_depth_0 = 0; cntr_depth_0 < r->num_depths; cntr_depth_0++) {
			NDR_CHECK(ndr_push_notify_depth(ndr, NDR_SCALARS, &r->depth[cntr_depth_0]));
		}
	}
	if (ndr_flags & NDR_BUFFERS) {
		for (cntr_depth_0 = 0; cntr_depth_0 < r->num_depths; cntr_depth_0++) {
			NDR_CHECK(ndr_push_notify_depth(ndr, NDR_BUFFERS, &r->depth[cntr_depth_0]));
		}
	}
	return NT_STATUS_OK;
}

_PUBLIC_ NTSTATUS ndr_pull_notify_array(struct ndr_pull *ndr, int ndr_flags, struct notify_array *r)
{
	uint32_t cntr_depth_0;
	TALLOC_CTX *_mem_save_depth_0;
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_pull_align(ndr, 8));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->num_depths));
		NDR_PULL_ALLOC_N(ndr, r->depth, r->num_depths);
		_mem_save_depth_0 = NDR_PULL_GET_MEM_CTX(ndr);
		NDR_PULL_SET_MEM_CTX(ndr, r->depth, 0);
		for (cntr_depth_0 = 0; cntr_depth_0 < r->num_depths; cntr_depth_0++) {
			NDR_CHECK(ndr_pull_notify_depth(ndr, NDR_SCALARS, &r->depth[cntr_depth_0]));
		}
		NDR_PULL_SET_MEM_CTX(ndr, _mem_save_depth_0, 0);
	}
	if (ndr_flags & NDR_BUFFERS) {
		_mem_save_depth_0 = NDR_PULL_GET_MEM_CTX(ndr);
		NDR_PULL_SET_MEM_CTX(ndr, r->depth, 0);
		for (cntr_depth_0 = 0; cntr_depth_0 < r->num_depths; cntr_depth_0++) {
			NDR_CHECK(ndr_pull_notify_depth(ndr, NDR_BUFFERS, &r->depth[cntr_depth_0]));
		}
		NDR_PULL_SET_MEM_CTX(ndr, _mem_save_depth_0, 0);
	}
	return NT_STATUS_OK;
}

_PUBLIC_ void ndr_print_notify_array(struct ndr_print *ndr, const char *name, const struct notify_array *r)
{
	uint32_t cntr_depth_0;
	ndr_print_struct(ndr, name, "notify_array");
	ndr->depth++;
	ndr_print_uint32(ndr, "num_depths", r->num_depths);
	ndr->print(ndr, "%s: ARRAY(%d)", "depth", r->num_depths);
	ndr->depth++;
	for (cntr_depth_0=0;cntr_depth_0<r->num_depths;cntr_depth_0++) {
		char *idx_0=NULL;
		asprintf(&idx_0, "[%d]", cntr_depth_0);
		if (idx_0) {
			ndr_print_notify_depth(ndr, "depth", &r->depth[cntr_depth_0]);
			free(idx_0);
		}
	}
	ndr->depth--;
	ndr->depth--;
}

_PUBLIC_ NTSTATUS ndr_push_notify_event(struct ndr_push *ndr, int ndr_flags, const struct notify_event *r)
{
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_push_align(ndr, 8));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->action));
		{
			uint32_t _flags_save_string = ndr->flags;
			ndr_set_flags(&ndr->flags, LIBNDR_FLAG_STR_UTF8|LIBNDR_FLAG_STR_NULLTERM);
			NDR_CHECK(ndr_push_string(ndr, NDR_SCALARS, r->path));
			ndr->flags = _flags_save_string;
		}
		NDR_CHECK(ndr_push_pointer(ndr, NDR_SCALARS, r->private_data));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NT_STATUS_OK;
}

_PUBLIC_ NTSTATUS ndr_pull_notify_event(struct ndr_pull *ndr, int ndr_flags, struct notify_event *r)
{
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_pull_align(ndr, 8));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->action));
		{
			uint32_t _flags_save_string = ndr->flags;
			ndr_set_flags(&ndr->flags, LIBNDR_FLAG_STR_UTF8|LIBNDR_FLAG_STR_NULLTERM);
			NDR_CHECK(ndr_pull_string(ndr, NDR_SCALARS, &r->path));
			ndr->flags = _flags_save_string;
		}
		NDR_CHECK(ndr_pull_pointer(ndr, NDR_SCALARS, &r->private_data));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NT_STATUS_OK;
}

_PUBLIC_ void ndr_print_notify_event(struct ndr_print *ndr, const char *name, const struct notify_event *r)
{
	ndr_print_struct(ndr, name, "notify_event");
	ndr->depth++;
	ndr_print_uint32(ndr, "action", r->action);
	ndr_print_string(ndr, "path", r->path);
	ndr_print_pointer(ndr, "private_data", r->private_data);
	ndr->depth--;
}

