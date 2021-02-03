#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

char* readFile();
void createDecendants(int n);

int main(int argc, char** argv) {
    int numDecendants;  /* number of children to create */
    char* readSeed;     /* seed read from seed.txt */
    int seed;           /* seed converted to int */

    readSeed = readFile();

    seed = atoi(readSeed);

    printf("Read seed value: %s\n", readSeed);
    printf("Read seed value (converted to integer): %d\n", seed);

    srand(seed);
    numDecendants = (rand()%4) + 7;

    printf("Random Decendant Count: %d\n", numDecendants);
    printf("Time to meet the kids/grandkids/great grandkids/...\n");

    createDecendants(numDecendants);
    
    return 0;
}

/*
 * Recursively create decendants until all of the decendants are made.
 */
void createDecendants(int n) {
    int childStatus;
    int forkResult;

    if(n == 0) { /* no more decendants to be made, exit recursion */
        exit(n);
    } else { /* keep creating decendants until there are no more to be made */
        forkResult = fork();
        if(forkResult == 0) {
            printf("\t[Child, PID: %d]: I was called with decendant count=%d. I'll have %d decendant(s).\n", getpid(), n, n-1);
            createDecendants(n-1);
        } else {
            printf("[Parent, PID: %d]: I am waiting for PID %d to finish.\n", getpid(), forkResult);
            waitpid(forkResult, &childStatus, 0);
        }
        if(WIFEXITED(childStatus)) {
            const int exitStat = WEXITSTATUS(childStatus);
            printf("[Parent, PID: %d]: Child %d finished with status code %d. It's now my turn to exit.\n", getpid(), forkResult, exitStat);
            exit(n);
        }
    }
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
