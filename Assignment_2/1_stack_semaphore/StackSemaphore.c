#include "StackSemaphore.h"

#define MaxNo 5 
/* Buffersize set to 5 */
#define BuffSize 5

sem_t empty;
sem_t full;
int input = 0;
int output = 0;
int item = 0;
int buffer[BuffSize];

void *producer(void *prodnum) {
  if (input == BuffSize - 1) {
    printf("Can't produce item because,  Producer Stack is full \n");
  } 
  else {
    for (int i = 0; i < MaxNo; i++) {
      item = rand();
      sem_wait(&empty);
      /* put value item into the buffer */
      buffer[input] = item;
      printf("Producer Number %d: I'm inserting Item %d at %d\n", *((int *)prodnum), buffer[input],
             input);
      input = (input + 1) % BuffSize;
      sem_post(&full);
    }
  }
}

void *consumer(void *consnum) {
  if (output == BuffSize - 1) {
    printf("Can't Consume items because Consumer Stack is full\n");
  } 
  else {
    int item = 0;
    for (int i = 0; i < MaxNo; i++) {
      sem_wait(&full);
      /* take one unit of data from the buffer */
      item = buffer[output];
      printf("Consumer Number %d: I'm Removing Item %d from %d\n", *((int *)consnum), item, output);
      output = (output + 1) % BuffSize;
      sem_post(&empty);
    }
  }
}

void main() {
  pthread_t prod[5], cons[5];
  sem_init(&empty, 0, BuffSize);
  sem_init(&full, 0, 0);

  int arr[5] = {1, 2, 3, 4, 5}; 

  for (int i = 0; i < 5; i++) {
    pthread_create(&prod[i], NULL, producer, (void *)&arr[i]);
  }
  for (int i = 0; i < 5; i++) {
    pthread_create(&cons[i], NULL, consumer, (void *)&arr[i]);
  }

  for (int i = 0; i < 5; i++) {
    pthread_join(prod[i], NULL);
  }
  for (int i = 0; i < 5; i++) {
    pthread_join(cons[i], NULL);
  }

  sem_destroy(&empty);
  sem_destroy(&full);
}
