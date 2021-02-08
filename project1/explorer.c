#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

char* readFile();

int main(int argc, char** argv) {
    int forkResult;     /* int to keep track of the fork result*/
    int childStatus;    /* catpure child exit status */
    char* readSeed;     /* seed read from seed.txt */
    int seed;           /* seed converted to int */
    int childPID;       /* PID of current child */
    char* randDirs[6];  /* list or directories to be visited */
    char* command[] = {"ls", "-alh", NULL};                                             /* command to be run by child */
    char* dirList[6] = {"/home", "/proc", "/proc/sys", "/usr", "/usr/bin", "/bin"};     /* list of directories to choose from */

    readSeed = readFile();
    seed = atoi(readSeed);

    printf("Read seed value: %s\n", readSeed);
    printf("Read seed value (converted to integer): %d\n", seed);

    srand(seed);

    /*
     * Generate random directory for each child to visit
     */
    for(int i = 0; i < 5; i++) {
        randDirs[i] = dirList[rand() % 6];
    }

    printf("It's time to see the world/file system!\n");

    /*
     * Creates 5 children which will run a command in a random directory
     */
    for(int i = 0; i < 5; i++) {
        char cwd[256];
        if(chdir(randDirs[i]) == 0) {
            getcwd(cwd, sizeof(cwd));
            printf("Selection #%d: %s [SUCCESS]\n", i+1, cwd);
            printf("Current reported directory: %s\n", cwd);
        } else {
            perror("chdir() failed\n");
        }
        forkResult = fork();
        if(forkResult == 0) {
            printf("\t[Child, PID: %d]: Executing 'ls -alh' command...\n", getpid());
            execvp("ls", command);
            exit(0);
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
