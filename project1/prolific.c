#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {
    printf("[Parent] pid %d\n", getpid());
    
    int childPid;
    
    for(int i = 0; i < 3; i++) {
        if(childPid = fork() == 0) {
            printf( "\t[Child] pid %d from pid %d\n", getpid(), getppid());
            printf( "\t[Child] pid %d exiting with status code %d\n", getpid(), i);
            sleep(3);
            exit(i);
        } else {
            // wait(NULL);
            waitpid(childPid);
            printf("[Parent] Child exited with status code %d\n", i);
        }
    }

    return 0;
}
