#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include "summer.h"

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
int isFirst = 0;
int nextGroup = 0; // 1 = Dancer, 2 = Juggler, 3 = Soloist
int numDancers = 0;
int numJugglers = 0;
int numSoloists = 0;
int dancersRun = 0;
int jugglersRun = 0;
int soloRun = 0;
int summer_debug = 0;

void set_next_group()
{
    int numGroups;
    int dancerOdds = (NUM_DANCERS - dancersRun) * (numJugglers + numSoloists + 1);
    int jugglerOdds = (NUM_JUGGLERS - jugglersRun) * (numDancers + numSoloists + 1);
    int soloOdds = (NUM_SOLOISTS - soloRun) * (numDancers + numJugglers + 5);
    int totalOdds = dancerOdds + jugglerOdds + soloOdds + 1;

    int res = rand() % totalOdds;
    if (summer_debug)
    {
        printf("Dancers[%d] = %d/%d | Jugglers[%d] = %d/%d | Soloists[%d] = %d/%d\n", (NUM_DANCERS - dancersRun), dancerOdds, totalOdds - 1,
               (NUM_JUGGLERS - jugglersRun), jugglerOdds, totalOdds - 1,
               (NUM_SOLOISTS - soloRun), soloOdds, totalOdds - 1);
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
    if(isFirst == 0) {
        set_next_group();
        isFirst = 1;
    }
    pthread_mutex_lock(&lock);
    int id = *((int *)arg);
    while (!(numPosLeft > 0 && nextGroup == 1 && numJugglers == 0 && numSoloists == 0))
    {
        pthread_cond_wait(&spot_open, &lock);
    }
    numPosLeft--;
    numDancers++;
    dancersRun++;
    if (numPosLeft == 0 || dancersRun == NUM_DANCERS)
    {
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
    if (numPosLeft == 0 || jugglersRun == NUM_JUGGLERS)
    {
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
    if (numPosLeft == 0 || soloRun == NUM_SOLOISTS)
    {
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
    summer_debug = arg;
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