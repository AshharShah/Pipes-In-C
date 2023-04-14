#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <wait.h>

#define noOfChilds 3

int main(int argc, char* argv[]){

    for(int i = 0; i < noOfChilds; i++){
        int cpid = fork();

        if(cpid == -1){
            printf("Failed to fork\n");
            exit(1);
        }

        if(cpid == 0){
            sleep(rand() % 4);
            printf("PID of Child: %d, PID of Parent %d\n", getpid(), getppid());
            exit(0);
        }
        else{
            continue;
        }
    }

    for(int i = 0; i < noOfChilds; i++){
        int cpid = wait(NULL);
        printf("PID of Exited Child: %d\n", cpid);
    }

    return 0;
}