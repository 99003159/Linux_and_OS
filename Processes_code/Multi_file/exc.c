#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
int ret,k,status;
ret=fork();//1st child
if(ret<0)
{
perror("Fork");
exit(1);
}
else if(ret==0)//1st child to compile 1st source
{
k=execlp("gcc","gcc","sum.c","-o","sum.o","-c",NULL);
if(k<0)
{
perror("execlp");
exit(1);
}
exit(0);
}
else
{
waitpid(-1,&status,0);
ret=fork();//2nd child to compile 2nd source
if(ret<0)
{
perror("Fork");
exit(1);
}
else if(ret==0)
{
k=execlp("gcc","gcc","square.c","-o","square.o","-c",NULL);
if(k<0)
{
perror("execlp");
exit(1);
}
exit(0);
}
else
{
waitpid(-1,&status,0);
ret=fork();//3rd child to Link
if(ret<0)
{
perror("Fork");
exit(1);
}
else if(ret==0)
{
k=execlp("gcc","gcc","sum.o","square.o","main.c","-o","fin.o",NULL);
if(k<0)
{
perror("execlp");
exit(1);
}
exit(0);
}
else
{
waitpid(-1,&status,0);
ret=fork();//4th child to execute
if(ret<0)
{
perror("Fork");
exit(1);
}
else if(ret==0) 
{
k=execlp("./fin.o","",NULL);
if(k<0)
{
perror("execlp");
exit(1);
}
exit(0);
}
else
{
waitpid(-1,&status,0);
printf("Completed");
}
}
}
}
}



