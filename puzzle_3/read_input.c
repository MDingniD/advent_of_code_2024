#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include "read_input.h"

char *myInput;

void readInput(const char *filename) {
    myInput = malloc( MAX_INPUT_SIZE * sizeof(char));

    int myDescriptor = open(filename, MODE_R, PERMS);
    if (myDescriptor == -1) {
        perror("Error opening file");
        exit(1);
    }
    int myLength = read(myDescriptor, myInput, MAX_INPUT_SIZE);

    


}