#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>

void int_handler();
void quit_handler();
void term_handler();

int main()
{
int ret;
ret=fork();
if(ret<0)
{
perror("fork");
exit(1);
}
else if(ret==0)
{
printf("I'm chld process\n");
signal(SIGINT,int_handler);
signal(SIGQUIT,quit_handler);
signal(SIGTERM,term_handler);
while(1);
}
else
{
kill(ret,SIGINT);
sleep(3);
kill(ret,SIGQUIT);
sleep(2);
kill(ret,SIGTERM);
}
return 0;
}

void int_handler()
{
signal(SIGINT,int_handler);
printf("Child : I have received sigint");
}

void quit_handler()
{
signal(SIGQUIT,quit_handler);
printf("Child : I have received sigquit");
}

void term_handler()
{
signal(SIGTERM,term_handler);
printf("Child : I have received sigterm");
}
