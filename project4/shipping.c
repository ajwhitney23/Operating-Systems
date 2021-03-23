#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>
#include <time.h>
#include "shipping.h"

#define NUM_WORKERS 40 /* 4 by 10 */
#define NUM_PACKAGES 80

const char *team_color_n[] = {"Blue", "Red", "Green", "Yellow"};
const char *steps_n[] = {"Weighing", "Barcoding", "Xraying", "Jostiling"};

struct worker *worker_structz[NUM_WORKERS];
int proc_pack[4];

sem_t stat_sems[4];
sem_t team_sems[4];
sem_t conveyor_sem;
sem_t allocate_stat_sem;

pthread_t workers[NUM_WORKERS];
struct package *ppp;
struct package *delivery_truck;

int conc_p = 0;
int col_p[4] = {0, 0, 0, 0};
int stat_o[4] = {0, 0, 0, 0};
int belt = 0;
int shipping_debug = 0;

/*
 * prints results once all packages have been processsed
 */
void print_results() {

    int highest = 0;
    int id = 0;
    for(int i = 0; i < NUM_WORKERS; i++) {
        if(worker_structz[i]->packages_proc > highest) {
            highest = worker_structz[i]->packages_proc;
            id = i;
        }
    }

    printf("\nFinal Results: \n\n");

    for(int i = 0; i < 4; i++) {
        printf("Team [%s] processed [%d] packages\n", team_color_n[i], proc_pack[i]);
    }
    printf("%s delivered the most packages [%d]\n", worker_structz[id]->name, highest);
}

/*
 * function assigned to each thread
 * Has each worker grab a package, go through all the stages, and put the package on the delievery truck.
 * Semaphores implemented in this function to provide convistency between all threads
 * 
 */
void *do_work(void *arg)
{
    while (1)
    {
        struct worker *me = ((struct worker *)arg);
        sem_wait(&team_sems[me->color]);
        if (ppp == NULL)
        { /* done processing packages */
            sem_post(&(team_sems[me->color]));
            return 0;
        }
        me->currentPackage = ppp;
        ppp = ppp->last;
        me->currentPackage->worker = me;
        if(shipping_debug) {
            conc_p++;
            col_p[me->color]++;
            printf("Packages: %d\n", conc_p);
            printf("Workers Active: B %d | R %d | G %d | Y %d\n" ,col_p[0], col_p[1], col_p[2], col_p[3]);
        }
        printf("%s [%s][%d] picked up Package [%d] [%s] \n", me->name, team_color_n[me->color], me->id, me->currentPackage->id, me->currentPackage->content);

        int stat_visit = 0;
        int current_station;
        sem_wait(&allocate_stat_sem);
        /* aqquire all sems for stations needed */
        for(int i = 0; i < me->currentPackage->numSteps; i++) {
            sem_wait(&stat_sems[me->currentPackage->order[i]]);
        }
        sem_post(&allocate_stat_sem);
        do
        {
            current_station = me->currentPackage->order[stat_visit];
            if(shipping_debug) {
                stat_o[current_station]++;
                printf("Stations Active: W %d | B %d | X %d | J %d\n", stat_o[0], stat_o[1], stat_o[2], stat_o[3]);
            }
            int work_time = (rand() % 3) + 1;
            if(current_station == 3 && me->currentPackage->isFragile) {
                printf("%s [%s][%d] with Package [%d] at [%s] for %d minute(s) shaking the living hell out of it\n", me->name, team_color_n[me->color], me->id, me->currentPackage->id, steps_n[current_station], work_time);
            } else {
                printf("%s [%s][%d] with Package [%d] at [%s] for %d minute(s)\n", me->name, team_color_n[me->color], me->id, me->currentPackage->id, steps_n[current_station], work_time);
            }
            sleep(work_time);
            stat_visit++;
            if(shipping_debug) {
                stat_o[current_station]--;
                printf("Stations Active: W %d | B %d | X %d | J %d\n", stat_o[0], stat_o[1], stat_o[2], stat_o[3]);
            }
            sem_post(&stat_sems[current_station]); /* release station sem when finished and on next station */
        } while (me->currentPackage->numSteps != stat_visit); /* loop until all stations visited */

        printf("%s [%s][%d] finished loading Package [%d] [%s] on the delivery truck \n", me->name, team_color_n[me->color], me->id, me->currentPackage->id, me->currentPackage->content);
        me->packages_proc++;
        proc_pack[me->color]++;
        me->currentPackage->last = delivery_truck;
        delivery_truck = me->currentPackage;
        if (shipping_debug)
        {
            conc_p--;
            printf("Current number of packages: %d\n", conc_p);
            col_p[me->color]--;
            printf("Workers Active: B %d | R %d | G %d | Y %d\n", col_p[0], col_p[1], col_p[2], col_p[3]);
        }
        sem_post(&(team_sems[me->color]));
        sleep(1);
    }
}

/*
 * Creates a struct package to be added to the ppp que
 */
struct package *create_package(int id, char *content)
{
    struct package *temp = malloc(sizeof(struct package));
    temp->id = id;
    temp->content = content;
    temp->isFragile = rand() % 2;
    temp->numSteps = (rand() % 4) + 1;
    temp->order = malloc(sizeof(int) * 4);
    for (int i = 0; i < 4; i++)
    {
        temp->order[i] = -1;
    }

    for (int i = 0; i < temp->numSteps; i++)
    {
        int newStep, isValid;
        do
        {
            isValid = 1;
            newStep = rand() % 4;
            for (int j = 0; j < temp->numSteps; j++)
            {
                if (newStep == temp->order[j])
                {
                    isValid = 0;
                    break;
                }
            }
        } while (!isValid);
        temp->order[i] = newStep;
    }
    return temp;
}

/*
 * creates a stuck worker to be passed in as an arg to the threads
 */ 
struct worker *create_worker(int id, char *buff)
{
    struct worker *temp = malloc(sizeof(struct worker));
    char *name = malloc(strlen(buff));
    memcpy(name, buff, strlen(buff));
    temp->name = name;
    temp->id = id + 1;
    temp->color = id / 10;
    temp->packages_proc = 0;
    worker_structz[id] = temp;
    return temp;
}

/*
 * "main" function for shipping
 */
int run_shipping(int arg)
{
    shipping_debug = arg;

    printf("\nShipping Shape Up\n");
    printf("#FedUpsWithFedOops\n\n");
    int i = 0;
    int error;

    for (i = 0; i < 4; i++)
    {
        sem_init(&(stat_sems[i]), 0, 1);
        sem_init(&(team_sems[i]), 0, 1);
    }
    sem_init(&conveyor_sem, 0, 1);
    sem_init(&allocate_stat_sem, 0, 1);

    FILE *fp;
    char *buff;
    size_t read;
    size_t len = 0;
    int line;

    fp = fopen("things.txt", "r");
    for (i = 0; i < NUM_PACKAGES; i++)
    {
        getline(&buff, &len, fp);
        buff[strlen(buff) - 1] = '\0';
        char *content = malloc(strlen(buff));
        memcpy(content, buff, strlen(buff) - 1);
        content[strlen(content)] = '\0';
        struct package *temp = create_package(i, content);
        if (ppp != NULL)
        {
            temp->last = ppp;
        }
        ppp = temp;
    }
    fclose(fp);
    fp = fopen("names.txt", "r");
    for (i = 0; i < NUM_WORKERS; i++)
    {
        getline(&buff, &len, fp);
        buff[strlen(buff) - 2] = '\0';
        struct worker *temp = create_worker(i, buff);
        error = pthread_create(&(workers[i]), NULL, &do_work, temp);

        if (error != 0)
        {
            printf("error in thread creation\n");
        }
    }
    fclose(fp);


    for (int i = 0; i < NUM_WORKERS; i++)
    {
        pthread_join(workers[i], NULL);
    }

    for (i = 0; i < 4; i++)
    {
        sem_destroy(&(stat_sems[i]));
        sem_destroy(&(team_sems[i]));
    }
    sem_destroy(&conveyor_sem);
    sem_destroy(&allocate_stat_sem);

    print_results();

    return 0;
}