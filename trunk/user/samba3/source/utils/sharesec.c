/*
 *  Unix SMB/Netbios implementation.
 *  Utility for managing share permissions
 *
 *  Copyright (C) Tim Potter                    2000
 *  Copyright (C) Jeremy Allison                2000
 *  Copyright (C) Jelmer Vernooij               2003
 *  Copyright (C) Gerald (Jerry) Carter         2005.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#include "includes.h"

static TALLOC_CTX *ctx;

enum acl_mode {SMB_ACL_DELETE, SMB_ACL_MODIFY, SMB_ACL_ADD, SMB_ACL_SET, SMB_ACL_VIEW };

struct perm_value {
	const char *perm;
	uint32 mask;
};

/* These values discovered by inspection */

static const struct perm_value special_values[] = {
	{ "R", SEC_RIGHTS_FILE_READ },
	{ "W", SEC_RIGHTS_FILE_WRITE },
	{ "X", SEC_RIGHTS_FILE_EXECUTE },
	{ "D", SEC_STD_DELETE },
	{ "P", SEC_STD_WRITE_DAC },
	{ "O", SEC_STD_WRITE_OWNER },
	{ NULL, 0 },
};

#define SEC_RIGHTS_DIR_CHANGE ( SEC_RIGHTS_DIR_READ|SEC_STD_DELETE|SEC_RIGHTS_DIR_WRITE|SEC_DIR_TRAVERSE )

static const struct perm_value standard_values[] = {
	{ "READ",   SEC_RIGHTS_DIR_READ|SEC_DIR_TRAVERSE },
	{ "CHANGE", SEC_RIGHTS_DIR_CHANGE },
	{ "FULL",   SEC_RIGHTS_DIR_ALL },
	{ NULL, 0 },
};

/********************************************************************
 print an ACE on a FILE
********************************************************************/

static void print_ace(FILE *f, SEC_ACE *ace)
{
	const struct perm_value *v;
	int do_print = 0;
	uint32 got_mask;

	fprintf(f, "%s:", sid_string_static(&ace->trustee));

	/* Ace type */

	if (ace->type == SEC_ACE_TYPE_ACCESS_ALLOWED) {
		fprintf(f, "ALLOWED");
	} else if (ace->type == SEC_ACE_TYPE_ACCESS_DENIED) {
		fprintf(f, "DENIED");
	} else {
		fprintf(f, "%d", ace->type);
	}

	/* Not sure what flags can be set in a file ACL */

	fprintf(f, "/%d/", ace->flags);

	/* Standard permissions */

	for (v = standard_values; v->perm; v++) {
		if (ace->access_mask == v->mask) {
			fprintf(f, "%s", v->perm);
			return;
		}
	}

	/* Special permissions.  Print out a hex value if we have
	   leftover bits in the mask. */

	got_mask = ace->access_mask;

 again:
	for (v = special_values; v->perm; v++) {
		if ((ace->access_mask & v->mask) == v->mask) {
			if (do_print) {
				fprintf(f, "%s", v->perm);
			}
			got_mask &= ~v->mask;
		}
	}

	if (!do_print) {
		if (got_mask != 0) {
			fprintf(f, "0x%08x", ace->access_mask);
		} else {
			do_print = 1;
			goto again;
		}
	}
}

/********************************************************************
 print a ascii version of a security descriptor on a FILE handle
********************************************************************/

static void sec_desc_print(FILE *f, SEC_DESC *sd)
{
	uint32 i;

	fprintf(f, "REVISION:%d\n", sd->revision);

	/* Print owner and group sid */

	fprintf(f, "OWNER:%s\n", sid_string_static(sd->owner_sid));

	fprintf(f, "GROUP:%s\n", sid_string_static(sd->group_sid));

	/* Print aces */
	for (i = 0; sd->dacl && i < sd->dacl->num_aces; i++) {
		SEC_ACE *ace = &sd->dacl->aces[i];
		fprintf(f, "ACL:");
		print_ace(f, ace);
		fprintf(f, "\n");
	}

}

/********************************************************************
    parse an ACE in the same format as print_ace()
********************************************************************/

static BOOL parse_ace(SEC_ACE *ace, const char *orig_str)
{
	char *p;
	const char *cp;
	fstring tok;
	unsigned int atype = 0;
	unsigned int aflags = 0;
	unsigned int amask = 0;
	DOM_SID sid;
	SEC_ACCESS mask;
	const struct perm_value *v;
	char *str = SMB_STRDUP(orig_str);

	if (!str) {
		return False;
	}

	ZERO_STRUCTP(ace);
	p = strchr_m(str,':');
	if (!p) {
		printf("ACE '%s': missing ':'.\n", orig_str);
		SAFE_FREE(str);
		return False;
	}
	*p = '\0';
	p++;
	/* Try to parse numeric form */

	if (sscanf(p, "%i/%i/%i", &atype, &aflags, &amask) == 3 &&
	    string_to_sid(&sid, str)) {
		goto done;
	}

	/* Try to parse text form */

	if (!string_to_sid(&sid, str)) {
		printf("ACE '%s': failed to convert '%s' to SID\n",
			orig_str, str);
		SAFE_FREE(str);
		return False;
	}

	cp = p;
	if (!next_token(&cp, tok, "/", sizeof(fstring))) {
		printf("ACE '%s': failed to find '/' character.\n",
			orig_str);
		SAFE_FREE(str);
		return False;
	}

	if (strncmp(tok, "ALLOWED", strlen("ALLOWED")) == 0) {
		atype = SEC_ACE_TYPE_ACCESS_ALLOWED;
	} else if (strncmp(tok, "DENIED", strlen("DENIED")) == 0) {
		atype = SEC_ACE_TYPE_ACCESS_DENIED;
	} else {
		printf("ACE '%s': missing 'ALLOWED' or 'DENIED' entry at '%s'\n",
			orig_str, tok);
		SAFE_FREE(str);
		return False;
	}

	/* Only numeric form accepted for flags at present */
	/* no flags on share permissions */

	if (!(next_token(&cp, tok, "/", sizeof(fstring)) &&
	      sscanf(tok, "%i", &aflags) && aflags == 0)) {
		printf("ACE '%s': bad integer flags entry at '%s'\n",
			orig_str, tok);
		SAFE_FREE(str);
		return False;
	}

	if (!next_token(&cp, tok, "/", sizeof(fstring))) {
		printf("ACE '%s': missing / at '%s'\n",
			orig_str, tok);
		SAFE_FREE(str);
		return False;
	}

	if (strncmp(tok, "0x", 2) == 0) {
		if (sscanf(tok, "%i", &amask) != 1) {
			printf("ACE '%s': bad hex number at '%s'\n",
				orig_str, tok);
			SAFE_FREE(str);
			return False;
		}
		goto done;
	}

	for (v = standard_values; v->perm; v++) {
		if (strcmp(tok, v->perm) == 0) {
			amask = v->mask;
			goto done;
		}
	}

	p = tok;

	while(*p) {
		BOOL found = False;

		for (v = special_values; v->perm; v++) {
			if (v->perm[0] == *p) {
				amask |= v->mask;
				found = True;
			}
		}

		if (!found) {
			printf("ACE '%s': bad permission value at '%s'\n",
				orig_str, p);
			SAFE_FREE(str);
		 	return False;
		}
		p++;
	}

	if (*p) {
		SAFE_FREE(str);
		return False;
	}

 done:
	mask = amask;
	init_sec_ace(ace, &sid, atype, mask, aflags);
	SAFE_FREE(str);
	return True;
}


/********************************************************************
********************************************************************/

static SEC_DESC* parse_acl_string(TALLOC_CTX *mem_ctx, const char *szACL, size_t *sd_size )
{
	SEC_DESC *sd = NULL;
	SEC_ACE *ace;
	SEC_ACL *acl;
	int num_ace;
	const char *pacl;
	int i;
	
	if ( !szACL )
		return NULL;

	pacl = szACL;
	num_ace = count_chars( pacl, ',' ) + 1;
	
	if ( !(ace = TALLOC_ZERO_ARRAY( mem_ctx, SEC_ACE, num_ace )) ) 
		return NULL;
	
	for ( i=0; i<num_ace; i++ ) {
		char *end_acl = strchr_m( pacl, ',' );
		fstring acl_string;

		strncpy( acl_string, pacl, MIN( PTR_DIFF( end_acl, pacl ), sizeof(fstring)-1) );
		acl_string[MIN( PTR_DIFF( end_acl, pacl ), sizeof(fstring)-1)] = '\0';
		
		if ( !parse_ace( &ace[i], acl_string ) )
			return NULL;

		pacl = end_acl;
		pacl++;
	}
	
	if ( !(acl = make_sec_acl( mem_ctx, NT4_ACL_REVISION, num_ace, ace )) )
		return NULL;
		
	sd = make_sec_desc( mem_ctx, SEC_DESC_REVISION, SEC_DESC_SELF_RELATIVE, 
		NULL, NULL, NULL, acl, sd_size);

	return sd;
}

/* add an ACE to a list of ACEs in a SEC_ACL */
static BOOL add_ace(TALLOC_CTX *mem_ctx, SEC_ACL **the_acl, SEC_ACE *ace)
{
	SEC_ACL *new_ace;
	SEC_ACE *aces;
	if (! *the_acl) {
		return (((*the_acl) = make_sec_acl(mem_ctx, 3, 1, ace)) != NULL);
	}

	if (!(aces = SMB_CALLOC_ARRAY(SEC_ACE, 1+(*the_acl)->num_aces))) {
		return False;
	}
	memcpy(aces, (*the_acl)->aces, (*the_acl)->num_aces * sizeof(SEC_ACE));
	memcpy(aces+(*the_acl)->num_aces, ace, sizeof(SEC_ACE));
	new_ace = make_sec_acl(mem_ctx,(*the_acl)->revision,1+(*the_acl)->num_aces, aces);
	SAFE_FREE(aces);
	(*the_acl) = new_ace;
	return True;
}

/* The MSDN is contradictory over the ordering of ACE entries in an ACL.
   However NT4 gives a "The information may have been modified by a
   computer running Windows NT 5.0" if denied ACEs do not appear before
   allowed ACEs. */

static int ace_compare(SEC_ACE *ace1, SEC_ACE *ace2)
{
	if (sec_ace_equal(ace1, ace2)) 
		return 0;

	if (ace1->type != ace2->type) 
		return ace2->type - ace1->type;

	if (sid_compare(&ace1->trustee, &ace2->trustee)) 
		return sid_compare(&ace1->trustee, &ace2->trustee);

	if (ace1->flags != ace2->flags) 
		return ace1->flags - ace2->flags;

	if (ace1->access_mask != ace2->access_mask) 
		return ace1->access_mask - ace2->access_mask;

	if (ace1->size != ace2->size) 
		return ace1->size - ace2->size;

	return memcmp(ace1, ace2, sizeof(SEC_ACE));
}

static void sort_acl(SEC_ACL *the_acl)
{
	uint32 i;
	if (!the_acl) return;

	qsort(the_acl->aces, the_acl->num_aces, sizeof(the_acl->aces[0]), QSORT_CAST ace_compare);

	for (i=1;i<the_acl->num_aces;) {
		if (sec_ace_equal(&the_acl->aces[i-1], &the_acl->aces[i])) {
			int j;
			for (j=i; j<the_acl->num_aces-1; j++) {
				the_acl->aces[j] = the_acl->aces[j+1];
			}
			the_acl->num_aces--;
		} else {
			i++;
		}
	}
}


static int change_share_sec(TALLOC_CTX *mem_ctx, const char *sharename, char *the_acl, enum acl_mode mode)
{
	SEC_DESC *sd;
	SEC_DESC *old = NULL;
	size_t sd_size = 0;
	uint32 i, j;
	
	if (mode != SMB_ACL_SET) {
	    if (!(old = get_share_security( mem_ctx, sharename, &sd_size )) ) {
		fprintf(stderr, "Unable to retrieve permissions for share [%s]\n", sharename);
		return -1;
	    }
	}

	if ( (mode != SMB_ACL_VIEW) && !(sd = parse_acl_string(mem_ctx, the_acl, &sd_size )) ) {
		fprintf( stderr, "Failed to parse acl\n");
		return -1;
	}
	
	switch (mode) {
	case SMB_ACL_VIEW:
		sec_desc_print( stdout, old);
		return 0;
	case SMB_ACL_DELETE:
	    for (i=0;sd->dacl && i<sd->dacl->num_aces;i++) {
		BOOL found = False;

		for (j=0;old->dacl && j<old->dacl->num_aces;j++) {
		    if (sec_ace_equal(&sd->dacl->aces[i], &old->dacl->aces[j])) {
			uint32 k;
			for (k=j; k<old->dacl->num_aces-1;k++) {
			    old->dacl->aces[k] = old->dacl->aces[k+1];
			}
			old->dacl->num_aces--;
			found = True;
			break;
		    }
		}

		if (!found) {
		printf("ACL for ACE:");
		print_ace(stdout, &sd->dacl->aces[i]);
		printf(" not found\n");
		}
	    }

	    break;
	case SMB_ACL_MODIFY:
	    for (i=0;sd->dacl && i<sd->dacl->num_aces;i++) {
		BOOL found = False;

		for (j=0;old->dacl && j<old->dacl->num_aces;j++) {
		    if (sid_equal(&sd->dacl->aces[i].trustee,
			&old->dacl->aces[j].trustee)) {
			old->dacl->aces[j] = sd->dacl->aces[i];
			found = True;
		    }
		}

		if (!found) {
		    printf("ACL for SID %s not found\n", sid_string_static(&sd->dacl->aces[i].trustee));
		}
	    }

	    if (sd->owner_sid) {
		old->owner_sid = sd->owner_sid;
	    }

	    if (sd->group_sid) {
		old->group_sid = sd->group_sid;
	    }
	    break;
	case SMB_ACL_ADD:
	    for (i=0;sd->dacl && i<sd->dacl->num_aces;i++) {
		add_ace(mem_ctx, &old->dacl, &sd->dacl->aces[i]);
	    }
	    break;
	case SMB_ACL_SET:
	    old = sd;
	    break;
	}

	/* Denied ACE entries must come before allowed ones */
	sort_acl(old->dacl);

	if ( !set_share_security( sharename, old ) ) {
	    fprintf( stderr, "Failed to store acl for share [%s]\n", sharename );
	    return 2;
	}
	return 0;
}

/********************************************************************
  main program
********************************************************************/

int main(int argc, const char *argv[])
{
	int opt;
	int retval = 0;
	enum acl_mode mode = SMB_ACL_SET;
	static char *the_acl = NULL;
	fstring sharename;
	BOOL force_acl = False;
	int snum;
	poptContext pc;
	BOOL initialize_sid = False;
	struct poptOption long_options[] = {
		POPT_AUTOHELP
		{ "remove", 'r', POPT_ARG_STRING, &the_acl, 'r', "Delete an ACE", "ACL" },
		{ "modify", 'm', POPT_ARG_STRING, &the_acl, 'm', "Modify an acl", "ACL" },
		{ "add", 'a', POPT_ARG_STRING, &the_acl, 'a', "Add an ACE", "ACL" },
		{ "replace", 'R', POPT_ARG_STRING, &the_acl, 'R', "Set share mission ACL", "ACLS" },
		{ "view", 'v', POPT_ARG_NONE, NULL, 'v', "View current share permissions" },
		{ "machine-sid", 'M', POPT_ARG_NONE, NULL, 'M', "Initialize the machine SID" },
		{ "force", 'F', POPT_ARG_NONE, NULL, 'F', "Force storing the ACL", "ACLS" },
		POPT_COMMON_SAMBA
		{ NULL }
	};

	if ( !(ctx = talloc_init("main")) ) {
		fprintf( stderr, "Failed to initialize talloc context!\n");
		return -1;
	}

	/* set default debug level to 1 regardless of what smb.conf sets */
	setup_logging( "sharesec", True );
	DEBUGLEVEL_CLASS[DBGC_ALL] = 1;
	dbf = x_stderr;
	x_setbuf( x_stderr, NULL );

	pc = poptGetContext("sharesec", argc, argv, long_options, 0);
	
	poptSetOtherOptionHelp(pc, "sharename\n");

	while ((opt = poptGetNextOpt(pc)) != -1) {
		switch (opt) {
		case 'r':
			the_acl = smb_xstrdup(poptGetOptArg(pc));
			mode = SMB_ACL_DELETE;
			break;

		case 'm':
			the_acl = smb_xstrdup(poptGetOptArg(pc));
			mode = SMB_ACL_MODIFY;
			break;

		case 'a':
			the_acl = smb_xstrdup(poptGetOptArg(pc));
			mode = SMB_ACL_ADD;
			break;
		case 'R':
			the_acl = smb_xstrdup(poptGetOptArg(pc));
			mode = SMB_ACL_SET;
			break;

		case 'v':
			mode = SMB_ACL_VIEW;
			break;

		case 'F':
			force_acl = True;
			break;
			
		case 'M':
			initialize_sid = True;
			break;
		}
	}
	
	setlinebuf(stdout);

	load_case_tables();

	lp_load( dyn_CONFIGFILE, False, False, False, True );

	/* check for initializing secrets.tdb first */
	
	if ( initialize_sid ) {
		DOM_SID *sid = get_global_sam_sid();
		
		if ( !sid ) {
			fprintf( stderr, "Failed to retrieve Machine SID!\n");
			return 3;
		}
		
		printf ("%s\n", sid_string_static( sid ) );
		return 0;
	}

	if ( mode == SMB_ACL_VIEW && force_acl ) {
		fprintf( stderr, "Invalid combination of -F and -v\n");
		return -1;
	}

	/* get the sharename */

	if(!poptPeekArg(pc)) { 
		poptPrintUsage(pc, stderr, 0);	
		return -1;
	}
	
	fstrcpy(sharename, poptGetArg(pc));
	
	snum = lp_servicenumber( sharename );
	
	if ( snum == -1 && !force_acl ) {
		fprintf( stderr, "Invalid sharename: %s\n", sharename);
		return -1;
	}
		
	retval = change_share_sec(ctx, sharename, the_acl, mode);
	
	talloc_destroy(ctx);

	return retval;
}
