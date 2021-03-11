#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "shipping.h"

// /*
// sem
// */

// #define NUM_DANCER 15
// #define NUM_JUGGLER 8
// #define NUM_SOLOIST 2

// sem_t pos_sem;
// sem_t group_sem;

// pthread_t dancers[NUM_DANCER];
// pthread_t jugglers[NUM_JUGGLER];
// pthread_t soloists[NUM_SOLOIST];

// void* dancer(void* arg) {
//     sem_wait(&pos_sem);
//     int id = *(int *) arg;
//     printf("dancer [%d] is on stage \n", id);
//     int performance_time = rand() % 10 + 1;
//     sleep(performance_time);
//     printf("dancer [%d] has left the stage after %d seconds\n", id, performance_time);
//     sem_post(&pos_sem);
//     free(arg);
// }

// void* juggler(void* arg) {
//     sem_wait(&pos_sem);
//     int id = *(int *) arg;
//     printf("jugger [%d] is on stage \n", id);
//     int performance_time = rand() % 10 + 1;
//     sleep(performance_time);
//     printf("jugger [%d] has left the stage after %d seconds\n", id, performance_time);
//     sem_post(&pos_sem);
//     free(arg);
// }

// void* soloist(void* arg) {
//     sem_wait(&pos_sem);
//     int id = *(int *) arg;
//     printf("soloist [%d] is on stage\n", id);
//     int performance_time = rand() % 10 + 1;
//     sleep(performance_time);
//     printf("soloist [%d] has left the stage after %d seconds\n", id, performance_time);
//     sem_post(&pos_sem);
//     free(arg);
// }

// int run_summer() {
//     printf("\nStart of problem number 1\n\n");
//     int i = 0;
//     int error;

//     sem_init(&pos_sem, 0, 4);
//     sem_init(&group_sem, 0, 1);

//     while (i < NUM_DANCER) {
//         int *val = malloc(sizeof(int));
//         *val = i+1;
//         error = pthread_create(&(dancers[i]), NULL, &dancer, val);

//         if(error != 0) {
//             printf("error in thread creation\n");
//         }
//         i++;
//     }
//     i = 0;
//     while (i < NUM_JUGGLER) {
//         int *val = malloc(sizeof(int));
//         *val = i+1;
//         error = pthread_create(&(jugglers[i]), NULL, &juggler, val);

//         if(error != 0) {
//             printf("error in thread creation\n");
//         }
//         i++;
//     }
//     i = 0;
//     while (i < NUM_SOLOIST) {
//         int *val = malloc(sizeof(int));
//         *val = i+1;
//         error = pthread_create(&(soloists[i]), NULL, &soloist, val);

//         if(error != 0) {
//             printf("error in thread creation\n");
//         }
//         i++;
//     }

//     for(int i = 0; i < NUM_DANCER; i++) {
//         pthread_join(dancers[i], NULL);
//     }
//     for(int i = 0; i < NUM_JUGGLER; i++) {
//         pthread_join(jugglers[i], NULL);
//     }
//     for(int i = 0; i < NUM_SOLOIST; i++) {
//         pthread_join(soloists[i], NULL);
//     }
//     sem_destroy(&pos_sem);
//     sem_destroy(&group_sem);
//     return 0;
// }