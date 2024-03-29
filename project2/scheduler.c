#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct job
{
    int id;           /* ID number for each job */
    int length;       /* length of time units it will take to do job */
    int response;     /* response time of job */
    int turnaround;   /* turnaround time of job */
    int wait;         /* wait time of job */
    int last_ran;     /* total execution time last time job was run */
    struct job *next; /* pointer to next job */
};

struct job *get_jobs(char *file);
void round_robin_scheduler(struct job *start, int time_slice);
void fifo_scheduler(struct job *start);
void sjf_scheduler(struct job *start);
struct job* swap(int pos, struct job *start);
void first_to_last(struct job* start, char* job_name);

/*
 * function returns the minimum value between x and y
 */
int min(int x, int y)
{
    if (x > y)
    {
        return y;
    }
    else
    {
        return x;
    }
}

int main(int argc, char **argv)
{
    struct job *start;

    //check for correct parameter count
    if (argc != 4)
    {
        printf("Incorrect number of parameters!\n");
        return -1;
    }

    //parse input
    char *file = argv[2];
    start = get_jobs(file);

    char *mode = argv[1];
    if (!strcmp(mode, "FIFO"))
    {
        fifo_scheduler(start);
    }
    else if (!strcmp(mode, "SJF"))
    {
        sjf_scheduler(start);
    }
    else if (!strcmp(mode, "RR"))
    {
        int time_slice = atoi(argv[3]);
        round_robin_scheduler(start, time_slice);
    }

    return 0;
}

/*
 * will go through all the jobs in order
 */
void fifo_scheduler(struct job *start)
{
    first_to_last(start, "FIFO");
}

/*
 * sort the jobs and then do the shortest job first, all to way to longest
 */
void sjf_scheduler(struct job *list_start)
{
    struct job* start = list_start;
    int changed = 1;

    //run until are jobs are sorted (bubble sort)
    while(changed > 0){
        changed = 0;
        int jobs_ran = 0;
        struct job *temp = start;
        while (temp != NULL && temp->next != NULL) {
            //condition to swap adjacent elements
           if(temp->length > temp->next->length || (temp->length == temp->next->length && temp->id > temp->next->id)){
               start = swap(jobs_ran, start);
               changed++;
           }

           temp = temp->next;
           jobs_ran ++;
        }
    }

    first_to_last(start, "SJF");
}

/*
 * rearranges the linked list at a specific location
 */
struct job* swap(int pos, struct job *start){
    struct job *crnt = start;
    struct job *past = NULL;
    struct job *futr = crnt->next;

    //find index to switch
    for(int i = 0; i < pos; i++){
        past = crnt;
        crnt = futr;
        if(futr->next != NULL){
            futr = futr->next;
        }else{
            futr = NULL;
        }
    }

    //preform switch
    if(past != NULL){
        if(futr != NULL) {
            past->next = futr;
            crnt->next = futr->next;
            futr->next = crnt;
        }

        //start was not changed
        return start;
    }

    crnt->next = futr->next;
    futr->next = crnt;

    //start was changed, assign new start
    return futr;
}

/*
 * goes through the jobs linked list and simulates running the jobs in the given order
 */ 
void first_to_last(struct job* start, char* job_name){
    int total_time = 0;

    printf("Execution trace with %s:\n", job_name);

    struct job *temp = start;
    /* while loop that runs though the linked list of jobs once */
    while (temp != NULL)
    {
        temp->wait += (total_time - temp->last_ran);
        int run_time = temp->length;
        printf("Job %d ran for: %d\n", temp->id, run_time);
        if (temp->response < 0) //response is initialized to -1
        {
            temp->response = total_time;
        }
        total_time += run_time;
        temp->turnaround = total_time;
        temp->last_ran = total_time;

        temp = temp->next;
    }
    printf("End of execution with %s.\n", job_name);

    printf("Begin analyzing %s:\n", job_name);
    temp = start;
    int avg_response = 0;
    int avg_turnaround = 0;
    int avg_wait = 0;
    double total_jobs = 0.0;

    //loop through each element of the linked list
    while (temp != NULL)
    {
        printf("Job %d -- Response time: %d  Turnaround: %d  Wait: %d\n", temp->id, temp->response, temp->turnaround, temp->wait);
        avg_response += temp->response;
        avg_turnaround += temp->turnaround;
        avg_wait += temp->wait;
        total_jobs++;
        temp = temp->next;
    }
    printf("Average -- Response: %.2f  Turnaround %.2f  Wait %.2f\n", (double)avg_response / total_jobs, (double)avg_turnaround / total_jobs, (double)avg_wait / total_jobs);
    printf("End analyzing %s.\n", job_name);
}

/*
 * simulates jobs with a round robin (RR) policy
 */ 
void round_robin_scheduler(struct job *start, int time_slice)
{
    int total_time = 0;

    printf("Execution trace with RR:\n");

    /* while loop that runs while there are still jobs to do */
    int jobs_ran = 1;
    while (jobs_ran > 0)
    {
        jobs_ran = 0;
        struct job *temp = start;
        /* while loop that runs though the linked list of jobs once */
        while (temp != NULL)
        {
            /* job is already done */
            if (temp->length == 0)
            {
                temp = temp->next;
                continue;
            }
            temp->wait += (total_time - temp->last_ran);
            int run_time = min(temp->length, time_slice);
            printf("Job %d ran for: %d\n", temp->id, run_time);
            temp->length -= run_time;
            if (temp->response < 0) //response is initialized to -1
            {
                temp->response = total_time;
            }
            total_time += run_time;
            if (temp->length == 0) //job is now done
            {
                temp->turnaround = total_time;
            }
            temp->last_ran = total_time;

            temp = temp->next;
            jobs_ran++;
        }
    }
    printf("End of execution with RR.\n");

    printf("Begin analyzing RR:\n");
    struct job *temp = start;
    int avg_response = 0;
    int avg_turnaround = 0;
    int avg_wait = 0;
    double total_jobs = 0.0;

    //loop through each element of the linked list
    while (temp != NULL)
    {
        printf("Job %d -- Response time: %d  Turnaround: %d  Wait: %d\n", temp->id, temp->response, temp->turnaround, temp->wait);
        avg_response += temp->response;
        avg_turnaround += temp->turnaround;
        avg_wait += temp->wait;
        total_jobs++;
        temp = temp->next;
    }
    printf("Average -- Response: %.2f  Turnaround %.2f  Wait %.2f\n", (double)avg_response / total_jobs, (double)avg_turnaround / total_jobs, (double)avg_wait / total_jobs);
    printf("End analyzing RR.\n");
}

/*
 * function reads the given file
 */
struct job *get_jobs(char *f)
{
    FILE *fp;
    char *buff;
    size_t read;
    size_t len = 0;
    int line;

    fp = fopen(f, "r");
    line = 0;
    struct job *last;
    struct job *first;

    //for each line initialize a new job and add it to the linked list
    while ((read = getline(&buff, &len, fp)) != -1)
    {
        struct job *temp = malloc(sizeof(struct job));
        temp->id = line;
        temp->length = atoi(buff);
        temp->response = -1;
        temp->turnaround = 0;
        temp->wait = 0;
        temp->last_ran = 0;
        if (line != 0)
        {
            last->next = temp;
        }
        else
        {
            first = temp;
        }
        last = temp;
        line++;
    }
    fclose(fp);

    return first;
}