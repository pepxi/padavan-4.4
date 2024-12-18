#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libsmbclient.h>

#define	MAX_BUFF_SIZE	255
char g_workgroup[MAX_BUFF_SIZE];
char g_username[MAX_BUFF_SIZE];
char g_password[MAX_BUFF_SIZE];
char g_server[MAX_BUFF_SIZE];
char g_share[MAX_BUFF_SIZE];

char g_print_user[MAX_BUFF_SIZE];
char g_print_name[MAX_BUFF_SIZE];
unsigned int g_print_id;
unsigned int g_print_priority;
unsigned int g_print_size;


void auth_fn(const char *server, const char *share, char *workgroup, int wgmaxlen, 
		char *username, int unmaxlen, char *password, int pwmaxlen)
{

	strncpy(workgroup, g_workgroup, wgmaxlen - 1);

	strncpy(username, g_username, unmaxlen - 1);

	strncpy(password, g_password, pwmaxlen - 1);

	strcpy(g_server, server);
	strcpy(g_share, share);

}

void print_list_fn(struct print_job_info *pji)
{

	g_print_id = pji->id;
	g_print_priority = pji->priority;
	g_print_size = pji->size;
	strcpy(g_print_user,pji->user);
	strcpy(g_print_name,pji->name);

	/* fprintf(stdout, "Print job: ID: %u, Prio: %u, Size: %u, User: %s, Name: %s\n",
			          pji->id, pji->priority, pji->size, pji->user, pji->name); */
	
}

int main(int argc, char** argv)
{
	int err = -1;
	int fd = 0;
	int msg_len = 0;
	char url[MAX_BUFF_SIZE];
	char* message;

	bzero(g_workgroup,MAX_BUFF_SIZE);
	bzero(url,MAX_BUFF_SIZE);
	bzero(g_print_user,MAX_BUFF_SIZE);
	bzero(g_print_name,MAX_BUFF_SIZE);

	g_print_id = 0;
	g_print_priority = 0;
	g_print_size = 0;

	if ( argc == 7 )
	{
		
		strncpy(g_workgroup,argv[1],strlen(argv[1]));
		strncpy(g_username,argv[2],strlen(argv[2]));
		strncpy(g_password,argv[3],strlen(argv[3]));
		strncpy(url,argv[4],strlen(argv[4]));

		msg_len = strlen(argv[5])+1;
		message = malloc(msg_len);
		message[msg_len - 1] = 0;	
		strncpy(message,argv[5],msg_len);
		/* printf("Message: %s\n",message); */
		/* printf("Message len: %i\n",msg_len); */

		smbc_init(auth_fn, 0);
		smbc_unlink(url);
		fd = smbc_open(url,O_RDWR | O_CREAT, 0666);
		smbc_write(fd, message, msg_len);
		smbc_close(fd);

		free(message);
		smbc_print_file(url,argv[6]);
		smbc_list_print_jobs(argv[6],print_list_fn);

		g_print_id = -1;
		smbc_unlink_print_job(argv[6],g_print_id);

		err = errno;

	}

	return err;

}

