#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct job
{
    int id;
    int length;
    int response;
    int turnaround;
    int wait;
    int last_ran;
    struct job *next;
};

struct job* read_file(char* file);
void round_robin_scheduler(struct job* start, int time_slice);
void fifo_scheduler(struct job* start);
void sjf_scheduler(struct job* start);


int min(int x, int y) {
    if(x > y) {
        return y;
    } else {
        return x;
    }
}


int main(int argc, char **argv){

    struct job *start;

    // struct job *temp = start;
    // while(temp != NULL) {
    //     printf("ID: %d, length: %d\n", temp->id, temp->length);
    //     temp = temp->next;
    // }

    if(argc != 4) {
        return -1;
    }

    char* file = argv[2];
    int time_slice = atoi(argv[3]);
    start = read_file(file);

    char* mode = argv[1];
    if(!strcmp(mode, "FIFO")) {
        printf("FIFO");
    } else if(!strcmp(mode, "SJF")) {
        printf("SJF");
    } else if(!strcmp(mode, "RR")) {
        round_robin_scheduler(start, time_slice);
        printf("RR");
    }

    return 0;

}

void round_robin_scheduler(struct job* start, int time_slice) {
    int current_job;
    int start_time = 0;
    int total_time = 0;
    int end_time;

    printf("Execution trace with RR:\n");

    int jobs_ran = 1;
    while(jobs_ran > 0) {
        jobs_ran = 0;
        struct job *temp = start;
        while (temp != NULL)
        {
            if(temp->length == 0) {
                temp = temp->next;
                continue;
            }
            temp->wait += (total_time - temp->last_ran);
            int run_time = min(temp->length, time_slice);
            printf("Job %d ran for %d\n", temp->id, run_time);
            temp->length -= run_time;
            if (temp->response < 0)
            {
                temp->response = total_time;
            }
            total_time += run_time;
            if (temp->length == 0)
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
    while(temp != NULL) {
        printf("Job %d -- Response time : %d Turnaround : %d Wait : %d\n", temp->id, temp->response, temp->turnaround, temp->wait);
        avg_response += temp->response;
        avg_turnaround += temp->turnaround;
        avg_wait += temp->wait;
        total_jobs++;
        temp = temp->next;
    }
    printf("Average -- Response : %f Turnaround %f Wait %f\n", (double)avg_response/total_jobs, (double)avg_turnaround/total_jobs, (double)avg_wait/total_jobs);

    printf("End analyzing RR.\n");


}

/*
 * function reads the given file
 */
struct job* read_file(char* f) {
    FILE *fp;
    char* buff;
    size_t read;
    size_t len = 0;
    int line;

    fp = fopen(f, "r");
    line = 0;
    struct job *last;
    struct job *first;
    while ((read = getline(&buff, &len, fp)) != -1) {
        struct job *temp = malloc(sizeof(struct job));
        temp->id = line;
        temp->length = atoi(buff);
        temp->response = -1;
        temp->turnaround = 0;
        temp->wait = 0;
        temp->last_ran = 0;
        if(line!=0) {
            last->next = temp;
        } else {
            first = temp;
        }
        last = temp;
        line++;
    }
    fclose(fp);

    return first;
}