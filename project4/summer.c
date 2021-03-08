#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
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
*/
/*
cond
*/
int num_threads = 15;
pthread_t parent;
pthread_t tid[15];
pthread_mutex_t lock;
pthread_cond_t cond;
int isFilled = 0;
int id[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

void *parent_test(void *arg)
{
    for (int i = 0; i < num_threads; i++)
    {
        pthread_mutex_lock(&lock);
        printf("Stage is empty, letting someone on... \n");
        isFilled += 1;
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&cond);
        sleep(1);
    }
}

void *test(void *arg)
{
    pthread_mutex_lock(&lock);
    int val = *((int *) arg);
    while (isFilled < 1)
    {
        pthread_cond_wait(&cond, &lock);
    }
    printf("I am now entering the stage with id : [%d] \n", val);
    sleep(2);
    printf("Now exting the stage \n");
    isFilled = 0;
    pthread_mutex_unlock(&lock);
}

int run_summer()
{
    int i = 0;
    int error;

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("mutex init failed \n");
        return 1;
    }

    if (pthread_cond_init(&cond, NULL) != 0)
    {
        printf("cond init failed\n");
        return 1;
    }

    pthread_create(&parent, NULL, &parent_test, NULL);  

    while (i < num_threads)
    {
        int val = i;
        error = pthread_create(&(tid[i]), NULL, &test, (void *)&id[i]);

        if (error != 0)
        {
            printf("error in thread creation\n");
        }
        i++;
    }

    pthread_join(parent, NULL);
    for (i = 0; i < num_threads; i++)
    {
        pthread_join(tid[i], NULL);
    }
    pthread_mutex_destroy(&lock);

    return 0;
}