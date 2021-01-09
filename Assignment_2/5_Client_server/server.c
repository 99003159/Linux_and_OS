#include"header.h"


int main()
{
	int ret,nbytes,prio,ret_fork,ret_exec,status;
	char buf[100];
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqd_t mqid;
	mqid=mq_open("/mque",O_RDWR|O_CREAT,0666,&attr);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}
	int maxlen=256;
	nbytes=mq_receive(mqid,buf,maxlen,&prio);
	if(nbytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buf[nbytes]='\0';
        printf("Client: Going to execute %s command in child",buf);
	ret_fork=fork();
	if(ret_fork<0)
	{
	perror("fork");
	exit(2);
	}
	else if(ret_fork==0)
	{
	ret_exec=execlp(buf,buf,NULL);
	if(ret_exec<0)
	{
	perror("execlp");
	exit(2);
	}
	exit(0);
	}
	else
	{
        waitpid(-1,&status,0);
	mq_close(mqid);
	mq_unlink("/mque");
	return 0;
	}

}
