/*
This is a skeleton for the producer-consumer problem using mutex and semaphore.
*/

#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 5
#define BUFFSIZE 5

sem_t empty;
sem_t full;
int buffer[BUFFSIZE];
pthread_mutex_t mutex;
int in = 0;
int out = 0;
int item = 0;

void *producer(void *p)
{   
    for(int i = 0; i < MAX; i++) {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        item = item +1;
        sleep(1);
        printf("producer %d: insert item %d at\tbuffer[%d]\n", *((int *)p),buffer[in],in);
        in = (in+1)%BUFFSIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void *consumer(void *c)
{   
    for(int i = 0; i < MAX; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item_removed = buffer[out];
        sleep(1);
        printf("consumer %d: remove item %d from buffer[%d]\n",*((int *)c),item_removed, out);
        printf("\t buffer is: %d %d %d %d %d", buffer[0], buffer[1],buffer[2],buffer[3],buffer[4]);
        out = (out+1)%BUFFSIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main()
{   

    pthread_t p[5],c[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, BUFFSIZE);
    sem_init(&full,0,0);

    int a[5] = {1,2,3,4,5}; //Just used for numbering the producer and consumer

    for(int i = 0; i < 5; i++) {
        pthread_create(&p[i], NULL, (void *)producer, (void *)&a[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&c[i], NULL, (void *)consumer, (void *)&a[i]);
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(p[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(c[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
    
}
