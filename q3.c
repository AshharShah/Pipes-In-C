#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    fork();
    fork(); fprintf(stderr,"A\n");
    fork(); fprintf(stderr,"B\n");
}