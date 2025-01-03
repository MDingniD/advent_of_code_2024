#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#include "read_input.h"
#include "data_structure.h"
#include "check_operation.h"

/*
argv[1] = input edge list
argv[2] = input operation list

Topological Orderings

2025-01-02: finished the process of input to edge list

TODO:
- create a graph list from the edge list
*/

int main(int argc, const char *argv[]) {

    if (argc != 3) {
        printf("Usage: %s <input file>\n", argv[0]);
        exit(1);
    }
    
    clock_t start, end;

    //Process input file 1 put it in a buffer
    //Create a list of string from the buffer
    //Create a list of edges from the list of strings
    //Create a graph from the edge list
    start = clock();
    edgesToVertices(argv[1]);
    //goThroughOperationList(argv[2]);
    goThroughOperationListUpgrade(argv[2]);
    freeDoubleArray((void **)myGraph, (void (*)(void *))freeVertex);
    end = clock();
    printf("Time: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    //Sum of mid numbers: 6142 (Q2)
    //Time: 0.002007
    return 0;
}