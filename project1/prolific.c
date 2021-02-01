#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {

    /* 
     * NOTE: currently fork() is a pid_t type
     * and is being automatically casted to it
     * should not be a problem
     */

    int childPid;       /* int to keep track of the children pid */
    int numChildren;    /* number of children to create */
    int childStatus;    /* catpure child exit status */

    printf("[Parent] pid %d\n", getpid());

    /*
     * Creates random number of children
     */
    for(int i = 0; i < 3; i++) {
        if(childPid = fork() == 0) {
            printf( "\t[Child] pid %d from pid %d\n", getpid(), getppid());
            printf( "\t[Child] pid %d exiting with status code %d\n", getpid(), i);
            sleep(3);
            exit(i);
        } else {
	        waitpid(childPid, &childStatus, 0);
        }
        if(WIFEXITED(childStatus)) {
            const int exit = WEXITSTATUS(childStatus);
            printf("[Parent] Child exited with status code %d\n", exit);
        }
    }

    return 0;
}
