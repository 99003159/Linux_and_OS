#include "header.h"

#define maxlen 256

int main()
{
	int ret,prior,nbytes;
	char buf[maxlen],str[100];
	mqd_t mqid;
 	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqid=mq_open("/mque",O_RDWR|O_CREAT,0666,&attr);
	//mqid=mq_open("/mque",O_WRONLY|O_CREAT,0666,NULL);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}
	printf("Enter the command that yu want to send to the server: ");
	scanf("%s",str);
	int len=strlen(str);
	ret=mq_send(mqid,str,len+1,100);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}
	mq_close(mqid);
	mq_unlink("/mque");
        return 0;
}
