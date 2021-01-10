#include"shell.h"
void shell()
{
int ret,status;
char cmd[10];
ret=fork();
if(ret<0)
{
perror("fork");
}
else if(ret==0)
{
printf("Enter the command you want to execute :");
scanf("%s",cmd);
execlp(cmd,cmd,NULL);
exit(0);
}
else
{
waitpid(-1,&status,0);
printf("The child has comleted\n");
printf("The status is %d",WEXITSTATUS(status));
}
}
