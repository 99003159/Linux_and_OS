
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

int arr[1000];

/*for(int i=0;i<1000;i++)
{
arr[i]=i;
}
*/

/*for(int i=0;i<10;i++)
{
temp[i]=0;
}
*/

void * arr_sum(void * ar)
{
int num=(intptr_t)ar;
intptr_t temp=0;
int j=num*100;
int k=j+100;
for(int i=j;i<k;i++)
{
temp+=arr[i];
}
pthread_exit((void *) temp);
}



int main()
{
//int arr[1000];
for(int i=0;i<1000;i++)
arr[i]=i;
pthread_t parr[10];
int temp[10],sum=0;
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
sum+=(int)temp[i];
}
printf("%d",sum);
return 0;
}




















