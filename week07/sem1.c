#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 

sem_t s; //define a semaphore used as a mutex
  
void* thread_function(void* arg) 
{ 
    sem_wait(&s); 
    printf("\nEntering...\n"); 
    //simulate a critical section 
    printf("Now inside critical section!\n"); 
    printf("Exiting...\n"); 
    sem_post(&s); 
}

int main() 
{ 
    sem_init(&s, 0, 1); // initiazlize sem with a value 1
    pthread_t thread1,thread2; 
    pthread_create(&thread1,NULL,thread_function,NULL); 
    pthread_create(&thread2,NULL,thread_function,NULL); 
    pthread_join(thread1,NULL); 
    pthread_join(thread2,NULL); 
    sem_destroy(&s); 
    return 0; 
} 
