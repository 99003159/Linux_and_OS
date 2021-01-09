#include"header.h"


int main()
{
	int ret,nbytes,prio;
	struct mq_attr attr;
	struct stat prop;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqd_t mqid;
	mqid=mq_open("/mque",O_RDWR|O_CREAT,0666,&attr);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}
	char buf[8192];
	int maxlen=256;
	nbytes=mq_receive(mqid,buf,maxlen,&prio);
	if(nbytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buf[nbytes]='\0';
	printf("The client has sent the filename: %s",buf);
        lstat(buf, &prop);
	ret = mq_send(mqid,(const char *)&prop,sizeof(prop),0);
  
    if(ret<0)
    {
    perror("mq_send");
    exit(2);
    }

	//write(1,buf,nbytes);
	mq_close(mqid);
	mq_unlink("/mque");
	return 0;
}

