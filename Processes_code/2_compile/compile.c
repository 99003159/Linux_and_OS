#include"compile.h"

void compile()
{
int ret,status;
ret=fork();
if(ret<0)
{
perror("fork");
}
else if(ret==0)
{
execlp("gcc","gcc","hello.c","-o","hello",NULL);
exit(0);
}
else
{
waitpid(-1,&status,0);
printf("The child has comleted\n");
printf("The status is %d",WEXITSTATUS(status));
}
}
