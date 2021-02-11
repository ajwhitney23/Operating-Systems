#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

double get_seconds_past(struct timespec start);

int main() {

    //start clock
    struct timespec start;
    clock_gettime(CLOCK_REALTIME, &start);

    //make variables for holding slug info
    int slug_pid[4];
    struct timespec slug_time[4];
    int done_cnt = 0;

    //fork off 4 slugs
    for(int i = 1; i < 5; i++){
        int rc = fork();
        if(rc == 0){ //child only

            //create args for exec
            char number[2];
            sprintf(number, "%d", i);
            char *args[]={"./slug", number, NULL};

            //call exec
            printf("[Child PID: %d]: Executing '%s %s' command...\n", getpid(), args[0], args[1]);
            execv(args[0], args);

        }else{ //parent only

            //keep track of slug variables
            printf("[Parent]: I forked off child %d\n", rc);
            slug_pid[i - 1] = rc;
            clock_gettime(CLOCK_REALTIME, &slug_time[i - 1]);
        }
    }

    //waiting for slugs
    while(done_cnt < 4){

        //print out which slugs are still racing
        printf("The race is still going. The following children are still racing: ");
        for(int i = 0; i < 4; i++){
            if(slug_pid[i] > 0){
                printf("%d ", slug_pid[i]);
            }
        }
        printf("\n");

        //check to see if slugs are still running
        for(int i = 0; i < 4; i++){
            if(slug_pid[i] > 0){
                pid_t return_pid = waitpid(slug_pid[i], NULL, WNOHANG);
                if (return_pid == slug_pid[i]) {
                    //note slug as ended
                    printf("Child %d has crossed the finish line! It took %f seconds\n", slug_pid[i], get_seconds_past(slug_time[i]));
                    slug_pid[i] = 0;
                    done_cnt ++;
                }
            }
        }

        //pause between prints
        usleep(250000);
    }

    //race end
    printf("The race is over! It took %f seconds\n", get_seconds_past(start));
    return 0;
}

/**
 * @param start: any timespec (from time.h)
 * @return time passed since start in seconds
 */
double get_seconds_past(struct timespec start){
    struct timespec end;
    clock_gettime(CLOCK_REALTIME, &end);
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/1000000000;
}
