#include "MutexCircular.h"

#define MaxNo 5 // Maximum items a producer can produce or a consumer can consume
#define BuffSize 5 // Size of the buffer

int input = 0;
int output = 0;
int buffer[BuffSize];
pthread_mutex_t mutex;

void *producer(void *prodno)
{   
    int item;
    for(int i = 0; i < MaxNo; i++) {
        item = rand(); // Produce a random item
        /* wait for space in buffer */
        while (((input + 1) % BuffSize) == output) sched_yield();
        /* put value item into the buffer */
 	 pthread_mutex_lock(&mutex);//critical section
         buffer[input] = item;
         printf("Producer %d: Insert Item %d at %d\n", *((int *)prodno),buffer[input],input);
         input = (input + 1) % BuffSize;   
         pthread_mutex_unlock(&mutex);
    }
}
void *consumer(void *consno)
{   
    int item=0;
    for(int i = 0; i < MaxNo; i++) {
        /* wait for buffer to fill */
        while (input == output) sched_yield();
        /* take one unit of data from the buffer */

	pthread_mutex_lock(&mutex);//critical section
        item = buffer[output];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)consno),item, output); 
        output = (output + 1) % BuffSize;     
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{   

    pthread_t prod[5],cons[5];
    pthread_mutex_init(&mutex, NULL);

    int arr[5] = {1,2,3,4,5}; //Just used for numbering the producer and consumer

    for(int i = 0; i < 5; i++) {
        pthread_create(&prod[i], NULL, (void *)producer, (void *)&arr[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&cons[i], NULL, (void *)consumer, (void *)&arr[i]);
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(prod[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(cons[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}
