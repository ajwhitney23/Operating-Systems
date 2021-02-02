#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

char* readFile();

int main(int argc, char** argv) {
    int forkResult;     /* int to keep track of the fork result*/
    int numChildren;    /* number of children to create */
    int childStatus;    /* catpure child exit status */
    char* readSeed;     /* seed read from seed.txt */
    int seed;           /* seed converted to int */
    int childPID;       /* PID of current child */

    readSeed = readFile();

    seed = atoi(readSeed);

    printf("Read seed value: %s\n", readSeed);
    printf("Read seed value (converted to integer): %d\n", seed);

    srand(seed);
    numChildren = (rand()%6) + 10;
    printf("Random Child Count: %d\n", numChildren);

    /*
     * Generate random number for each child
     */
    int randNumbers[numChildren];
    for(int i = 0; i < numChildren; i++) {
        randNumbers[i] = rand();
    }

    printf("I'm feeling prolific!\n");
    printf("[Parent] pid %d\n", getpid());

    /*
     * Creates random number of children
     */
    for(int i = 0; i < numChildren; i++) {
        forkResult = fork();
        if(forkResult == 0) {
            int exitCode = (randNumbers[i]%50) + 1;
            int waitTime = (randNumbers[i]%3) + 1;
            printf("\t[Child, PID: %d]: I am the child and I will wait %d seconds and exit with code %d\n", getpid(), waitTime, exitCode);
            sleep(waitTime);
            printf("\t[Child, PID: %d]: Now exiting... \n", getpid());
            exit(exitCode);
        } else if(forkResult == -1) {
            perror("fork() failed");
        } else {
            printf("[Parent]: I am waiting for PID %d to finish.\n", forkResult);
	        waitpid(forkResult, &childStatus, 0);
        }
        if(WIFEXITED(childStatus)) {
            const int exit = WEXITSTATUS(childStatus);
            printf("[Parent]: Child %d exited with status code %d. Onward!\n", forkResult, exit);
        }
    }

    return 0;
}

/*
 * function reads the seed.txt file and retuns the string as a char*
 */
char* readFile() {
    FILE *fp;
    char buff[255];
    char* resultString;

    fp = fopen("seed.txt", "r");
    fgets(buff, 255, (FILE*)fp);
    fclose(fp);

    resultString = buff;

    return resultString;
}
