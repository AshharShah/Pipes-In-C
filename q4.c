#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
    // check if command line arguments are correct
    if(argc < 4){
        printf("Too Few Arguments!!\n");
        printf("First Argument: File Name\n");
        printf("Second Argument: Number Of Childen\n");
        printf("Third Argument: Number Of Characters To Be Read In One Go\n");
    }

    // open the large file for reading 
    int fd = open(argv[1], O_RDONLY);
    int noOfChilds = atoi(argv[2]);
    int noOfCharacters = atoi(argv[3]);

    // spawn N number of children
    for(int i = 0; i < noOfChilds; i++){
        // create child
        int cpid = fork();
        // check for fork error
        if(cpid == -1){
            printf("Failed to fork\n");
            exit(1);
        }

        // create two pipes, one for child and one for parent
        int parentPipe[2];  // parent to child
        int childPipe[2];   // child to parent
        if(pipe(parentPipe) == -1){
            printf("Error Creating Parent Pipe!\n");
            exit(1);
        }
        else if(pipe(childPipe) == -1){
            printf("Error Creating Child Pipe!\n");
            exit(1);
        }

        // what does the child do
        if(cpid == 0){
        }
        // what does the parent do
        else{
            wait(NULL);
        }
    }


}