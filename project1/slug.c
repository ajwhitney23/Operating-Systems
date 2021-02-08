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
    printf("Read seed value: %s\n", buffer);

    //set seed and make random numbers
    srand(atoi(buffer));
    int wait_time = rand() % 4 + 1;
    int coin_flip = rand() % 2;

    //delay
    printf("Delay time is %d seconds. Coin flip: %d\n", wait_time, coin_flip);
    printf("I'll get the job done. Eventually...\n");
    sleep(wait_time);
    printf("Break time is over! I am running the '");

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
