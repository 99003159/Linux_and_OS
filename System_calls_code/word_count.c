#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{

int line_cnt, char_cnt, word_cnt;
int file,n,d,i;
char ch[16384];
file=open("file.txt",O_RDONLY);
if(file<0)
{
	perror("open");
	exit(1);
}
word_cnt = 0;
line_cnt = 0;
while(n=read(file,ch,sizeof(ch)))
	{
    	for(i=0;i<n;i++)
        	{
            /* Check new line */
            	if (ch[i] == '\n')
               	line_cnt++;
            /* Check words */
            	if (ch[i] == ' ' || ch[i] == '\t' || ch[i] == '\n')
               	word_cnt++;
        	}
        char_cnt=n;
    }
    /* Close files to release resources */
    close(first);
	
  printf("The total number of lines is %d\n",line_cnt);

  printf("The total number of characters is %d\n",char_cnt);

  printf("The total number of lines is %d\n",word_cnt);

return 0;
}
