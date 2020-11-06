/*
This is a skeleton for the producer-consumer problem using mutex and semaphore.
*/

#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

const int max = 5; //maximum items
const int buffer_size = 5;

sem_t empty;
sem_t full;
int buffer[buffer_size];
pthread_mutex_t mutex;
int in = 0;
int out = 0;

void *producer(void *p)
{   
    for(int i = 0; i < max; i++) {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = i;
        printf("producer %d: insert item %d at\tbuffer[%d]\n", *((int *)p),buffer[in],in);
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
        printf("consumer %d: remove item %d from buffer[%d]\n",*((int *)c),item, out);
        out = (out+1)%buffer_size;
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
