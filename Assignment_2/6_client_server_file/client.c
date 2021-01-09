#include "header.h"

#define maxlen 256

int main()
{
	int ret,prior,nbytes,prio;
	struct stat prop;
	char buf[maxlen];
	mqd_t mqid;
	char file[100];
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
	printf("Enter the filename: ");
	scanf("%s",file);
	int len=strlen(file);
	ret=mq_send(mqid,file,len+1,0);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}

nbytes = mq_receive(mqid, (char *)&prop, 1024, &prio);
  if (nbytes < 0) {
    perror("mq_recv");
    exit(2);
  }

  /* Printing the file attributes*/
  printf("----------------File Attributes----------------\n");
  printf("ID of device containing file    : %ld\n", (long)prop.st_dev);
  printf("Inode number                    : %ld\n", (long)prop.st_ino);
  printf("File type                       : ");
  switch (prop.st_mode & S_IFMT) {
  case S_IFBLK:
    printf("block device\n");
    break;
  case S_IFCHR:
    printf("character device\n");
    break;
  case S_IFDIR:
    printf("directory\n");
    break;
  case S_IFIFO:
    printf("FIFO/pipe\n");
    break;
  case S_IFLNK:
    printf("symlink\n");
    break;
  case S_IFREG:
    printf("regular file\n");
    break;
  case S_IFSOCK:
    printf("socket\n");
    break;
  default:
    printf("unknown?\n");
    break;
  }
  printf("Mode                            : %lo (octal)\n", (unsigned long)prop.st_mode);
  printf("Link count                      : %ld\n", (long)prop.st_nlink);
  printf("User ID                         : %ld\n" , (long)prop.st_uid);
  printf("Group ID                        : %ld\n", (long)prop.st_gid);
  printf("Blocksize for file system I/O   : %ld bytes\n", (long)prop.st_blksize);
  printf("File size                       : %lld bytes\n", (long long)prop.st_size);
  printf("Number of 512B Blocks allocated : %lld\n", (long long)prop.st_blocks);
  printf("Last status change              : %s", ctime(&prop.st_ctime));
  printf("Last file access                : %s", ctime(&prop.st_atime));
  printf("Last file modification          : %s", ctime(&prop.st_mtime));
       // printf("\nThe server is replying back with the file properties\nThe properties are: %s",buf);

	mq_close(mqid);
	mq_unlink("/mque");
        return 0;
}
