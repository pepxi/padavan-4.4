
/* 
   Samba Unix/Linux Dynamic DNS Update
   net ads commands

   Copyright (C) Krishna Ganugapati (krishnag@centeris.com)         2006
   Copyright (C) Gerald Carter                                      2006

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  
*/

#include "includes.h"
#include "utils/net.h"
#include "dns.h"

#if defined(WITH_DNS_UPDATES)

/*********************************************************************
*********************************************************************/

DNS_ERROR DoDNSUpdate(char *pszServerName,
		      const char *pszDomainName, const char *pszHostName,
		      const struct in_addr *iplist, size_t num_addrs )
{
	DNS_ERROR err;
	struct dns_connection *conn;
	TALLOC_CTX *mem_ctx;
	OM_uint32 minor;
	struct dns_update_request *req, *resp;

	if ( (num_addrs <= 0) || !iplist ) {
		return ERROR_DNS_INVALID_PARAMETER;
	}

	if (!(mem_ctx = talloc_init("DoDNSUpdate"))) {
		return ERROR_DNS_NO_MEMORY;
	}
		
	err = dns_open_connection( pszServerName, DNS_TCP, mem_ctx, &conn );
	if (!ERR_DNS_IS_OK(err)) {
		goto error;
	}

	/*
	 * Probe if everything's fine
	 */

	err = dns_create_probe(mem_ctx, pszDomainName, pszHostName,
			       num_addrs, iplist, &req);
	if (!ERR_DNS_IS_OK(err)) goto error;

	err = dns_update_transaction(mem_ctx, conn, req, &resp);
	if (!ERR_DNS_IS_OK(err)) goto error;

	if (dns_response_code(resp->flags) == DNS_NO_ERROR) {
		TALLOC_FREE(mem_ctx);
		return ERROR_DNS_SUCCESS;
	}

	/*
	 * First try without signing
	 */

	err = dns_create_update_request(mem_ctx, pszDomainName, pszHostName,
					iplist, num_addrs, &req);
	if (!ERR_DNS_IS_OK(err)) goto error;

	err = dns_update_transaction(mem_ctx, conn, req, &resp);
	if (!ERR_DNS_IS_OK(err)) goto error;

	if (dns_response_code(resp->flags) == DNS_NO_ERROR) {
		TALLOC_FREE(mem_ctx);
		return ERROR_DNS_SUCCESS;
	}

	/*
	 * Okay, we have to try with signing
	 */
	{
		gss_ctx_id_t gss_context;
		char *keyname;

		if (!(keyname = dns_generate_keyname( mem_ctx ))) {
			err = ERROR_DNS_NO_MEMORY;
			goto error;
		}

		err = dns_negotiate_sec_ctx( pszDomainName, pszServerName,
					     keyname, &gss_context, DNS_SRV_ANY );

		/* retry using the Windows 2000 DNS hack */
		if (!ERR_DNS_IS_OK(err)) {
			err = dns_negotiate_sec_ctx( pszDomainName, pszServerName,
						     keyname, &gss_context, 
						     DNS_SRV_WIN2000 );
		}
		
		if (!ERR_DNS_IS_OK(err))
			goto error;
		

		err = dns_sign_update(req, gss_context, keyname,
				      "gss.microsoft.com", time(NULL), 3600);

		gss_delete_sec_context(&minor, &gss_context, GSS_C_NO_BUFFER);

		if (!ERR_DNS_IS_OK(err)) goto error;

		err = dns_update_transaction(mem_ctx, conn, req, &resp);
		if (!ERR_DNS_IS_OK(err)) goto error;

		err = (dns_response_code(resp->flags) == DNS_NO_ERROR) ?
			ERROR_DNS_SUCCESS : ERROR_DNS_UPDATE_FAILED;
	}


error:
	TALLOC_FREE(mem_ctx);
	return err;
}

/*********************************************************************
*********************************************************************/

int get_my_ip_address( struct in_addr **ips )
{
	struct iface_struct nics[MAX_INTERFACES];
	int i, n;
	struct in_addr loopback_ip = *interpret_addr2("127.0.0.1");
	struct in_addr *list;
	int count = 0;

	/* find the first non-loopback address from our list of interfaces */

	n = get_interfaces(nics, MAX_INTERFACES);
	
	if ( (list = SMB_MALLOC_ARRAY( struct in_addr, n )) == NULL ) {
		return -1;
	}

	for ( i=0; i<n; i++ ) {
		if ( nics[i].ip.s_addr != loopback_ip.s_addr ) {
			memcpy( &list[count++], &nics[i].ip, sizeof( struct in_addr ) );
		}
	}
	*ips = list;

	return count;
}

DNS_ERROR do_gethostbyname(const char *server, const char *host)
{
	struct dns_connection *conn;
	struct dns_request *req, *resp;
	DNS_ERROR err;

	err = dns_open_connection(server, DNS_UDP, NULL, &conn);
	if (!ERR_DNS_IS_OK(err)) goto error;

	err = dns_create_query(conn, host, QTYPE_A, DNS_CLASS_IN, &req);
	if (!ERR_DNS_IS_OK(err)) goto error;

	err = dns_transaction(conn, conn, req, &resp);

 error:
	TALLOC_FREE(conn);
	return err;
}

#endif	/* defined(WITH_DNS_UPDATES) */
