#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>
#include "shipping.h"

// /*
// sem
// */

#define NUM_WORKERS 40 /* 4 by 10 */
#define NUM_PACKAGES 80

const char *team_color_n[] = {"Blue", "Red", "Green", "Yellow"};
const char *steps_n[] = {"Weighing", "Barcoding", "Xraying", "Jostiling"};

sem_t stat_sems[4];
sem_t team_sems[4];

pthread_t workers[NUM_WORKERS];
struct package *ppp;
struct package *delivery_truck;

void print_worker(struct worker *w)
{
    printf("Worker %d ", w->id);
    printf("Team: %s ", team_color_n[w->color]);
    printf("Name: %s \n ", w->name);
}

void print_package(struct package *p)
{
    printf("Package %d \n ", p->id);
    printf("Content: %s \n ", p->content);
    for (int i = 0; i < p->numSteps; i++)
    {
        printf("%d ~ %s \n ", i, steps_n[p->order[i]]);
    }
    if (p->isFragile)
    {
        printf("FRAGILE \n ");
    }
    printf("\n ");
}

void *do_work(void *arg)
{
    struct worker *me = ((struct worker *)arg);

    sem_wait(&team_sems[me->color]);
    if(ppp == NULL) {
        sem_post(&(team_sems[me->color]));
        return 0;
    }
    me->currentPackage = ppp;
    ppp = ppp->last;

    // print_worker(&me);
    printf("%s picked up package %d \n ", me->name, me->currentPackage->id);
    // print_package(me->currentPackage);

    int stat_visit = 0;
    int current_station;
    do
    {   
        current_station = me->currentPackage->order[stat_visit];
        sem_wait(&stat_sems[current_station]);
        printf("%s with %d @ %s \n ", me->name, me->currentPackage->id, steps_n[current_station]);
        sleep(2);
        stat_visit++;
        sem_post(&stat_sems[current_station]);
    } while (me->currentPackage->numSteps != stat_visit);

    // print_worker(&me);
    printf("%s finished loading package %d on the truck \n ", me->name, me->currentPackage->id);
    // print_package(me->currentPackage);

    sem_post(&(team_sems[me->color]));
    sleep(1);
}

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

struct worker *create_worker(int id, int team, char *name)
{
    struct worker *temp = malloc(sizeof(struct worker));
    temp->name = name;
    temp->id = id;
    temp->color = team;

    return temp;
}

int run_shipping()
{

    srand(12345);

    printf("\nStart of problem number 2\n\n");
    int i = 0;
    int error;

    for (i = 0; i < 4; i++)
    {
        sem_init(&(stat_sems[i]), 0, 1);
        sem_init(&(team_sems[i]), 0, 1);
    }

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
        struct package *temp = create_package(i, buff);
        if (ppp != NULL)
        {
            temp->last = ppp;
        }
        ppp = temp;
        // print_package(temp);
    }
    fclose(fp);

    fp = fopen("names.txt", "r");
    for (i = 0; i < NUM_WORKERS; i++)
    {
        getline(&buff, &len, fp);
        buff[strlen(buff) - 1] = '\0';
        struct worker *temp = malloc(sizeof(struct worker));
        temp->name = buff;
        temp->id = i+1;
        temp->color = i/10;

        error = pthread_create(&(workers[i]), NULL, &do_work, temp);

        if(error != 0) {
            printf("error in thread creation\n");
        }
    }
    fclose(fp);

    for(int i = 0; i < NUM_WORKERS; i++) {
        pthread_join(workers[i], NULL);
    }

    for (i = 0; i < 4; i++)
    {
        sem_destroy(&(stat_sems[i]));
        sem_destroy(&(team_sems[i]));
    }
    return 0;
}