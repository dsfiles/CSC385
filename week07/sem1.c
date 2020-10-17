#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
  
sem_t sem; //define a semaphore
  
void* thread_function(void* arg) 
{ 
    //wait 
    sem_wait(&sem); 
    printf("\nEnter critical section..\n"); 
  
    //critical section 
    printf("\Now inside critical section..\n"); 
  //sleep(1); 
      
    //signal 
    printf("\nExiting...\n"); 
    sem_post(&sem); 
} 
  
  
int main() 
{ 
    sem_init(&sem, 0, 1); // initiazlize sem with a value 1
    pthread_t thread1,thread2; 
    pthread_create(&thread1,NULL,thread_function,NULL); 
    sleep(1); 
    pthread_create(&t2,NULL,thread_function,NULL); 
    pthread_join(thread1,NULL); 
    pthread_join(thread2,NULL); 
    sem_destroy(&sem); 
    return 0; 
} 
