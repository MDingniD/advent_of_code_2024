#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "read_input.h"
#include "process_input.h"

int main(int argc, const char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input file>\n", argv[0]);
        exit(1);
    }

    printf("Roading the input file...\n");
    readInput(argv[1]); 
    // read the input file, argv[0] is the program name, 
    // argv[1] is the input file name
    int typeOfProblem = *argv[2] - 48;
    printf("Set the Progrom to Puzzle3_Problem%d...\n", typeOfProblem);

    printf("The sum of all valid mul is: \n");
    processInput(myInput, typeOfProblem);

    free(myInput);

    return 0;
}

