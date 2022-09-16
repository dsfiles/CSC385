#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

int myglobal;

void* thread_function(void* arg)
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        j = myglobal;
        j = j + 1;
        printf(".");
        fflush(stdout);
        sleep(1);
        myglobal = j;
    }
    return 0;
}

int main(void)
{
    int mythread;
    int i;
    pthread_create(&mythread, NULL, thread_function, NULL);
    
    for (i = 0; i < 10; i++)
    {
        myglobal = myglobal + 1;
        printf("o");
        fflush(stdout);
        sleep(1);
    }

    pthread_join(mythread, NULL);
    printf("\nmyglobal equals %d\n", myglobal);
    //exit(0);
}
