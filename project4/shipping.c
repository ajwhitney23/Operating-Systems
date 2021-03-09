#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "shipping.h"

/*
cond
*/
// #define NUM_DANCERS 15
// #define NUM_JUGGLERS 8
// #define NUM_SOLOISTS 2

// pthread_t dancers[NUM_DANCERS];
// pthread_t jugglers[NUM_JUGGLERS];
// pthread_t soloists[NUM_SOLOISTS];
// pthread_t stage_t;
// pthread_mutex_t lock;
// pthread_cond_t cond;
// int numPosLeft = 4;
// int isDancers = 1;
// int isJugglers = 1;
// int isSoloist = 1;

// void *stage(void *arg)
// {
//     for (int i = 0; i < NUM_DANCERS; i++)
//     {
//         pthread_mutex_lock(&lock);
//         if(numPosLeft == 4) {
//             printf("Stage is empty, letting someone on... \n");
//             isDancers = 1;
//             isJugglers = 1;
//             isSoloist = 1;
//         } else {
//             printf("State isn't empty... %d pos left\n", numPosLeft);
//         }
//         pthread_mutex_unlock(&lock);
//         pthread_cond_signal(&cond);
//         sleep(1);
//     }
// }

// void *dancer(void *arg)
// {
//     pthread_mutex_lock(&lock);
//     int val = *((int *) arg);
//     while (numPosLeft == 0 || !isDancers)
//     {
//         pthread_cond_wait(&cond, &lock);
//     }
//     numPosLeft--;
//     isJugglers = 0;
//     isSoloist = 0;
//     printf("Dancer %d entering the stage\n", val);
//     int performance_time = rand() % 10 + 1;
//     sleep(performance_time);
//     printf("Dancer %d now exiting the stage after performing for %d seconds\n", val, performance_time);
//     numPosLeft++;
//     pthread_mutex_unlock(&lock);
// }

// // void *juggler(void *arg)
// // {
// //     pthread_mutex_lock(&lock);
// //     int val = *((int *) arg);
// //     while (isFilled < 1)
// //     {
// //         pthread_cond_wait(&cond, &lock);
// //     }
// //     printf("Juggler %d entering the stage\n", val);
// //     int performance_time = rand() % 10 + 1;
// //     sleep(performance_time);
// //     printf("Dancer %d now exiting the stage after performing for %d seconds\n", val, performance_time);
// //     isFilled = 0;
// //     pthread_mutex_unlock(&lock);
// // }

// int run_shipping()
// {
//     printf("\nStart of problem number 2\n\n");
//     int i = 0;
//     int error;

//     if (pthread_mutex_init(&lock, NULL) != 0)
//     {
//         printf("mutex init failed \n");
//         return 1;
//     }

//     if (pthread_cond_init(&cond, NULL) != 0)
//     {
//         printf("cond init failed\n");
//         return 1;
//     }

//     pthread_create(&stage_t, NULL, &stage, NULL);  

//     while (i < NUM_DANCERS)
//     {
//         int *val = malloc(sizeof(int));
//         *val = i+1;
//         error = pthread_create(&(dancers[i]), NULL, &dancer, val);

//         if (error != 0)
//         {
//             printf("error in thread creation\n");
//         }
//         i++;
//     }

//     // while (i < NUM_JUGGLERS)
//     // {
//     //     int *val = malloc(sizeof(int));
//     //     *val = i+1;
//     //     error = pthread_create(&(jugglers[i]), NULL, &juggler, val);

//     //     if (error != 0)
//     //     {
//     //         printf("error in thread creation\n");
//     //     }
//     //     i++;
//     // }

//     pthread_join(stage_t, NULL);
//     for (i = 0; i < NUM_DANCERS; i++)
//     {
//         pthread_join(dancers[i], NULL);
//     }
//     // for( i = 0; i < NUM_JUGGLERS; i++) 
//     // {
//     //     pthread_join(jugglers[i], NULL);
//     // }
//     pthread_mutex_destroy(&lock);
//     pthread_cond_destroy(&cond);

//     return 0;
// }