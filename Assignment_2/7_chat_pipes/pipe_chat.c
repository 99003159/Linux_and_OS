#include "pipe_header.h"

void main() 
{
    int pipe1;
    pipe1 = mkfifo("pipe1",0666);
    if(pipe1<0)
        printf("\npipe1 creation failed");
    else
        printf("\npipe1 creation successful");
    int pipe2;
    pipe2 = mkfifo("pipe2",0666);
    if(pipe2<0)
        printf("\npipe2 creation failed");
    else
        printf("\npipe2 creation successful\n");
}
