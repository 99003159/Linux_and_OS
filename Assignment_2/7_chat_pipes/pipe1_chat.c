#include "pipe_header.h"

void main() 
{
    char str[256]="begin"; 
    int pipe_write,pipe_read; 
    while(strcmp(str,"end")!=0)   
    {   
        pipe_write= open("pipe1",O_WRONLY);   
        //if(pipe_write<0)     
          //  printf("\nError opening pipe to write");   
        //else     
       // {
            printf("chat1: ");     
            scanf("%s",str);     
            write(pipe_write,str,255*sizeof(char));     
            close(pipe_write);     
        //}   
        pipe_read=open("pipe2",O_RDONLY);   
        if(pipe_read<0)     
            printf("\nError opening read  pipe");   
        else     
        {     
            read(pipe_read,str,255*sizeof(char));     
            close(pipe_read);     
            printf("\n%s",str);   
        }   
    } 
}
