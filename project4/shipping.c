#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include "shipping.h"

/*
sem
*/

sem_t mutex;
pthread_t tid[50];

void* testp(void* arg) {
    sem_wait(&mutex);
    int count = *((int *) arg);

    printf("job [%d] has started\n", count);
    sleep(1);
    printf("job [%d] has finsihed\n", count);

    sem_post(&mutex);
}

int run_shipping() {
    int i = 0;
    int error;

    sem_init(&mutex, 0, 9);


    while (i < 10) {
        int val = i;
        error = pthread_create(&(tid[i]), NULL, &testp, (void *)&val);

        if(error != 0) {
            printf("error in thread creation\n");
        }
        i++;
    }

    for(int i = 0; i < 50; i++) {
        pthread_join(tid[i], NULL);
    }
    return 0;
}