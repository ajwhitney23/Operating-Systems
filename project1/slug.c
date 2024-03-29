#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main( int argc, char *argv[] ) {

    //make sure the right number of args is entered
    if(argc != 2){return 0;}

    //create seed file name
    char* filename = malloc(16);
    strcat(filename, "seed_slug_");
    strcat(filename, argv[1]);
    strcat(filename, ".txt");

    //read file
    char* buffer = malloc(20);
    FILE *fp = fopen(filename, "r");
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);
    printf("[Slug PID: %d]: Read seed value: %s\n",getpid(), buffer);

    int seed_int = atoi(buffer);
    //set seed and make random numbers
    srand(seed_int);

    printf("[Slug PID: %d]: Read seed value (converted to integer): %d\n",getpid(), seed_int);

    int wait_time = rand() % 4 + 1;
    int coin_flip = rand() % 2;

    //delay
    printf("[Slug PID: %d]: Delay time is %d seconds. Coin flip: %d\n", getpid(), wait_time, coin_flip);
    printf("[Slug PID: %d]: I'll get the job done. Eventually...\n", getpid());
    sleep(wait_time);
    printf("[Slug PID: %d]: Break time is over! I am running the '", getpid());

    //create args for exec
    char *args_0[]={"last", "-d", "--fulltimes", NULL};
    char *args_1[]={"id", "-u", NULL};

    //call exec based on coin flip
    if(coin_flip == 0){
        printf("last -d --fulltimes' command.\n");
        execvp(args_0[0], args_0);
    }else{
        printf("id -u' command.\n");
        execvp(args_1[0], args_1);
    }

    return 0;
}
