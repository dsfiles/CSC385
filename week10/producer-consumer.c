#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

/*
This is a skeleton for the producer-consumer problem using mutex and semaphore.
*/

//#define MaxItems 5 // Maximum items a producer can produce or a consumer can consume
//#define BufferSize 5 // Size of the buffer

const int max = 5; 
const int buffer_size = 5;

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[buffer_size];
pthread_mutex_t mutex;

void *producer(void *p)
{   
    int item;
    for(int i = 0; i < max_items; i++) {
        item = rand(); // Produce an random item
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)p),buffer[in],in);
        in = (in+1)%buffer_size;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}
void *consumer(void *c)
{   
    for(int i = 0; i < max; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),item, out);
        out = (out+1)%BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main()
{   

    pthread_t producer[5],consumer[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0,buffer_size);
    sem_init(&full,0,0);

    int a[5] = {1,2,3,4,5}; //Just used for numbering the producer and consumer

    for(int i = 0; i < 5; i++) {
        pthread_create(&producer[i], NULL, (void *)producer, (void *)&a[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&consumer[i], NULL, (void *)consumer, (void *)&a[i]);
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(producer[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(consumer[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
    
}
