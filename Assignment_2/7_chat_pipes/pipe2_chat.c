#include "pipe_header.h"

void main() 
{
    char str[256]="begin"; 
    int pipe_write,pipe_read; 
    while(strcmp(str,"end")!=0)   
    {   
        pipe_read= open("pipe1",O_RDONLY);   
        //if(pipe_write<0)     
          //  printf("\nError opening pipe to write");   
        //else     
       // {
            printf("Reply: ");     
            scanf("%s",str);     
            read(pipe_read,str,255*sizeof(char));     
            close(pipe_read);     
        //}   
        pipe_write=open("pipe2",O_WRONLY);   
        if(pipe_write<0)     
            printf("\nError opening read  pipe");   
        else     
        {     
            write(pipe_write,str,255*sizeof(char));     
            close(pipe_write);     
            printf("\n%s",str);   
        }   
    } 
}
