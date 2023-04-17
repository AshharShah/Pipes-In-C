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
    close(0);
    dup(readfd);

    int fd = open(newFileName, O_RDWR|O_CREAT, 0777);

    char bytesToWrite[BUFSIZ];

    // read the data to write to new file from pipe
    int bytesRead = read(readfd, bytesToWrite, BUFSIZ);
    // write the data to the new file
    int bytesWritten = write(fd, bytesToWrite, bytesRead);

    char writebytes[10];
    sprintf(writebytes, "%d", bytesWritten);
    // write how many characters were written to the file into the pipe
    int t = write(writefd, writebytes, strlen(writebytes));

    close(readfd);
    close(fd);
    close(writefd);
    
    exit(0);
}
