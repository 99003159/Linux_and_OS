//thread.c


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

int arr[1000];

/*
for(int i=0;i<10;i++)
{
temp[i]=0;
}
*/


void * arr_sum(void * ar)
{
int num=(intptr_t)ar;
intptr_t max=0;
int j=num*100;
int k=j+100;
for(int i=j;i<k;i++)
{
if(arr[i]>max)
max=arr[i];
}
pthread_exit((void *) max);
}



int main()
{
//int arr[1000],max=0;
for(int i=0;i<1000;i++)
arr[i]=i;
pthread_t parr[10];
int temp[10],max=0;
for(int i=0;i<10;i++)
{
temp[i]=0;
}
for(int i=0;i<10;i++)
{
pthread_create(&parr[i],NULL,arr_sum,(void*)(__intptr_t)i);
}
for(int i=0;i<10;i++)
{
pthread_join(parr[i],(void*)&temp[i]);
}
for(int i=0;i<10;i++)
{
if(temp[i]>max)
max=temp[i];
}
printf("%d",max);
return 0;
}
















