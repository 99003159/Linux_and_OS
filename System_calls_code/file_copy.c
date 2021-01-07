#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int file1,file2,nbytes_read,nbytes_written;
	file1=open("read.txt",O_RDONLY);
	file2=open("write.txt",O_WRONLY|O_CREAT, 0666);
	if(file1<0 || file2<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=128;
	char buf[maxlen];
	nbytes_read=read(file1,buf,maxlen);
	if(nbytes_read<0)
	{
		perror("read");
		exit(2);
	}
	nbytes_written = write(file2,buf,nbytes_read);
	if(nbytes_written<0)
	{
		perror("write");
		exit(2);
	}
	close(file1);
	close(file2);
	return 0;
}
