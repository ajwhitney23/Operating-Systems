#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include "shipping.h"

/*
sem
*/

#define NUM_THREADS 5

sem_t semaphore;
pthread_t tid[NUM_THREADS];

void* testp(void* arg) {
    sem_wait(&semaphore);
    int count = *(int *) arg;

    printf("job [%d] has started\n", count);
    sleep(1);
    printf("job [%d] has finsihed\n", count);
    sleep(1);

    sem_post(&semaphore);
    free(arg);
}

int run_shipping() {
    printf("\nStart of problem number 2\n\n");
    int i = 0;
    int error;

    sem_init(&semaphore, 0, 1);


    while (i < NUM_THREADS) {
        int *val = malloc(sizeof(int));
        *val = i;
        error = pthread_create(&(tid[i]), NULL, &testp, val);

        if(error != 0) {
            printf("error in thread creation\n");
        }
        i++;
    }

    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(tid[i], NULL);
    }
    sem_destroy(&semaphore);
    return 0;
}