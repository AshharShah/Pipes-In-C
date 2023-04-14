#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int agrc, char* argv[]){
    char* filename = argv[1];
    int readfd = atoi(argv[2]);
    int writefd = atoi(argv[3]);
    int cpid = getpid();
    char cpidString[BUFSIZ];
    char seperator[2] = "-";
    sprintf(cpidString, "%d", cpid);

    char* newFileName = strcat(filename, strcat(seperator, cpidString));
    
    // using standard input to read text for file writing 
    // close(0);
    // dup(readfd);

    printf("%s", newFileName);

    //int filefd = open(strcat(filename, strcat("-", "cpidString")), O_RDWR|O_CREAT, 0777);

}
