#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include "summer.h"

/* NOTES
15 Flamenco dancers
8 torch jugglers
2 soloists

Stage can hold up to 4 performers at a time
Each of the 4 stage position can hold 1 performer

Students must synchronize the stage under these constraints
Students may assume that conflicts only occur on stage, so performers may congregate off-stage without issues

Students must implement code that creates the requisite number of Flamenco dancers, torch jugglers,
and soloist threads. They must use either semaphores or the combination of mutexes and condition variables
to properly synchronize the stage. Each dancer, juggler, and soloist thread should identify itself (by name or
number) and which stage position (e.g., 1, 2, 3, or 4) it is using when it enters or leaves the stage.

Students should simulate a dancer, juggler, or soloist’s performance using the sleep() call with a random wait time.
Students should explain how their solution avoids depriving the different performer types of the stage in a
text file, problem1 explanation.txt, that will be submitted along with the source code.

4 dancers or 4 jugglers at a time on the stage max, 1 soloist at a time
no groups can mix
*/

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

/*
cond
*/
#define NUM_DANCERS 15
#define NUM_JUGGLERS 8
#define NUM_SOLOISTS 2

pthread_t dancers[NUM_DANCERS];
pthread_t jugglers[NUM_JUGGLERS];
pthread_t soloists[NUM_SOLOISTS];
pthread_mutex_t lock;
pthread_cond_t spot_open;
int seats[] = {0, 0, 0, 0};
int numPosLeft = 4;
int numConcurrent = 0;
int nextGroup = 0; // 1 = Dancer, 2 = Juggler, 3 = Soloist
int numDancers = 0;
int numJugglers = 0;
int numSoloists = 0;
int dancersRun = 0;
int jugglersRun = 0;
int soloRun = 0;
int debug = 0;

void set_next_group()
{
    int numGroups;
    int dancerOdds = (NUM_DANCERS - dancersRun) * (numJugglers + numSoloists + 1);
    int jugglerOdds = (NUM_JUGGLERS - jugglersRun) * (numDancers + numSoloists + 1);
    int soloOdds = (NUM_SOLOISTS - soloRun) * (numDancers + numJugglers + 5);
    int totalOdds = dancerOdds + jugglerOdds + soloOdds + 1;

    int res = rand() % totalOdds;
    if(debug) {
        printf("Dancers[%d] = %d/%d | Jugglers[%d] = %d/%d | Soloists[%d] = %d/%d\n", (NUM_DANCERS - dancersRun),  dancerOdds , totalOdds -1,
                                                                         (NUM_JUGGLERS - jugglersRun), jugglerOdds , totalOdds -1,
                                                                         (NUM_SOLOISTS - soloRun), soloOdds , totalOdds -1);
    }
    if (res <= dancerOdds)
    {
        nextGroup = 1;
    }
    else if (res <= jugglerOdds + dancerOdds)
    {
        nextGroup = 2;
    }
    else
    {
        nextGroup = 3;
    }
}

int place(int id)
{
    for (int i = 0; i < 4; i++)
    {
        if (seats[i] == 0)
        {
            seats[i] = id;
            return i + 1;
        }
    }
    return -1;
}

void leave_pos(int id)
{
    for (int i = 0; i < 4; i++)
    {
        if (seats[i] == id)
        {
            seats[i] = 0;
        }
    }
}

void *dancer(void *arg)
{
    pthread_mutex_lock(&lock);
    int id = *((int *)arg);
    while (!(numPosLeft > 0 && nextGroup == 1 && numJugglers == 0 && numSoloists == 0))
    {
        // printf("dancer %d %d\n", id, !(numPosLeft > 0 && nextGroup == 1));
        pthread_cond_wait(&spot_open, &lock);
    }
    numPosLeft--;
    numDancers++;
    dancersRun++;
    if(numPosLeft == 0 || dancersRun == NUM_DANCERS) {
        set_next_group();
    }
    int pos = place(id);
    printf("Dancer %d entering the stage at position %d\n", id, pos);
    int performance_time = (rand() % 3) + 1;
    pthread_mutex_unlock(&lock);
    sleep(performance_time);
    numPosLeft++;
    printf("Dancer %d now exiting the stage at position %d after performing for %d minutes\n", id, pos, performance_time);
    leave_pos(id);
    numDancers--;
    pthread_cond_broadcast(&spot_open);
    free(arg);
}

void *juggler(void *arg)
{
    pthread_mutex_lock(&lock);
    int id = *((int *)arg);
    while (!(numPosLeft > 0 && nextGroup == 2 && numDancers == 0 && numSoloists == 0))
    {
        pthread_cond_wait(&spot_open, &lock);
    }
    numPosLeft--;
    numJugglers++;
    jugglersRun++;
    if(numPosLeft == 0 || jugglersRun == NUM_JUGGLERS) {
        set_next_group();
    }
    int pos = place(id);
    printf("Juggler %d entering the stage at position %d\n", id, pos);
    int performance_time = (rand() % 3) + 1;
    pthread_mutex_unlock(&lock);
    sleep(performance_time);
    numPosLeft++;
    printf("Juggler %d now exiting the stage at position %d after performing for %d minutes\n", id, pos, performance_time);
    leave_pos(id);
    numJugglers--;
    pthread_cond_broadcast(&spot_open);
    free(arg);
}

void *soloist(void *arg)
{
    pthread_mutex_lock(&lock);
    int id = *((int *)arg);
    while (!(numPosLeft > 0 && nextGroup == 3 && numDancers == 0 && numJugglers == 0))
    {
        pthread_cond_wait(&spot_open, &lock);
    }
    numPosLeft -= 4;
    numSoloists++;
    soloRun++;
    if(numPosLeft == 0 || soloRun == NUM_SOLOISTS) {
        set_next_group();
    }
    int pos = place(id);
    printf("Soloist %d entering the stage at position %d\n", id, pos);
    int performance_time = (rand() % 3) + 1;
    pthread_mutex_unlock(&lock);
    sleep(performance_time);
    numPosLeft += 4;
    printf("Soloist %d now exiting the stage at position %d after performing for %d minutes\n", id, pos, performance_time);
    leave_pos(id);
    numSoloists--;
    pthread_cond_broadcast(&spot_open);
    free(arg);
}

int run_summer(int arg)
{
    debug = arg;
    srand(time(NULL));
    printf("\nStart of problem number 1\n\n");
    int i = 0;
    int error;

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("mutex init failed \n");
        return 1;
    }

    if (pthread_cond_init(&spot_open, NULL) != 0)
    {
        printf("cond init failed\n");
        return 1;
    }

    set_next_group();

    while (i < NUM_DANCERS)
    {
        int *val = malloc(sizeof(int));
        *val = i + 1;
        error = pthread_create(&(dancers[i]), NULL, &dancer, val);

        if (error != 0)
        {
            printf("error in thread creation\n");
        }
        i++;
    }

    i = 0;

    while (i < NUM_JUGGLERS)
    {
        int *val = malloc(sizeof(int));
        *val = i + 1;
        error = pthread_create(&(jugglers[i]), NULL, &juggler, val);

        if (error != 0)
        {
            printf("error in thread creation\n");
        }
        i++;
    }

    i = 0;

    while (i < NUM_SOLOISTS)
    {
        int *val = malloc(sizeof(int));
        *val = i + 1;
        error = pthread_create(&(soloists[i]), NULL, &soloist, val);

        if (error != 0)
        {
            printf("error in thread creation\n");
        }
        i++;
    }

    for (i = 0; i < NUM_DANCERS; i++)
    {
        pthread_join(dancers[i], NULL);
    }
    for (i = 0; i < NUM_JUGGLERS; i++)
    {
        pthread_join(jugglers[i], NULL);
    }
    for (i = 0; i < NUM_SOLOISTS; i++)
    {
        pthread_join(soloists[i], NULL);
    }
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&spot_open);

    return 0;
}