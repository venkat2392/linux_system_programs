#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
 
pthread_t tid[2];
pthread_mutex_t mutex;
int counter;
 
void* trythis(void *arg)
{
    pthread_mutex_lock(&mutex);
    counter += 1;
    printf("\n Job %d has started\n", counter);
    sleep(1);
    printf("\n Job %d has finished\n", counter);
    pthread_mutex_unlock(&mutex);
 
    return NULL;
}
 
int main(void)
{
    int i = 0;
    while(i < 2)
    {
        pthread_create(&(tid[i]), NULL, &trythis, NULL);
        i++;
    }
 
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
 
    return 0;
}
