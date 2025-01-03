#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "process_input.h"
#include "read_input.h"

int main(int argc, const char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input file>\n", argv[0]);
        exit(1);
    }

    readInput(argv[1]);

    int problem = atoi(argv[2]);

    if (problem == 1) {
        findAllXmas(myInput);
    } else if (problem == 2) {
        findAllRealXmas(myInput);
    } else {
        printf("Invalid problem number\n");
        exit(1);
    }
   
    free(myInput);

    return 0;
}