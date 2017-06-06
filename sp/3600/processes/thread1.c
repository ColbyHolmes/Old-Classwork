#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int main()
{
    void * update_val (void *);
    int i, *retval, val[10];
    pthread_t tid[10];

    for(i = 0; i < 10; i++) 
    {
        val[i] = i;
        pthread_create(&tid[i], NULL, update_val, val + i);
    }

    for(i = 0; i < 10; i++) 
    {
        pthread_join(tid[i], (void **) &retval);
        printf("Thread %d:  %d %d\n", i, val[i],*retval); 
    }
}

void * update_val (void *arg)
{
    int i, *count;

    count = (int *) arg;
    for(i = 0; i < 10; i++)
        *count += 1;

    pthread_exit(count); 
}
