#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "summer.h"
#include "shipping.h"
#include <semaphore.h>

sem_t mutex;
pthread_t tid[2];
pthread_mutex_t lock; 
pthread_cond_t empty, full;
int one = 1;
int zero = 0;

void* test(void* arg) {
    pthread_mutex_lock(&lock);

    int count = *((int *) arg);
    printf("hello : %d \n", count);
    // if (count == 0)
    // {
    //     printf("im asleep\n");
    //     pthread_cond_wait(&empty, &lock);
    // }
    printf("Job has started from %d \n", count);

    // sleep(1);

    printf("Job has finished from %d\n", count);
    // pthread_cond_signal(&empty);
    pthread_mutex_unlock(&lock);

    return NULL;

}

void* testp(void* arg) {
    sem_wait(&mutex);

    printf("job has started\n");
    sleep(1);
    printf("job has finsihed\n");

    sem_post(&mutex);
}



int main(int argc, char** argv) {

    run_summer();
    run_shipping();

    int i = 0;
    int error;

    if(pthread_mutex_init(&lock, NULL) != 0) {
        printf("mutex init failed \n");
        return 1;
    }
    // sem_init(&mutex, 0, 1);


    while (i < 2) {
        if(i == 0) {
            error = pthread_create(&(tid[i]), NULL, &test, (void *)&zero);
        } else {
            error = pthread_create(&(tid[i]), NULL, &test, (void *)&one);
        }
        // error = pthread_create(&(tid[i]), NULL, &testp, NULL);

        if(error != 0) {
            printf("error in thread creation\n");
        }
        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock);


    return 0;
}

