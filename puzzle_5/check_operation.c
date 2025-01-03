#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "read_input.h"
#include "data_structure.h"
#include "check_operation.h"


/*
Allocate memory in function createVertexList
Caller is responsible for freeing memory(main)
*/



void goThroughOperationList(const char * filename) {

    int **operations = NULL;

    readOperationInput(filename, &operations);

    int i = 0;
    int sumOfMidNum = 0;

    while (*(operations + i) != NULL) {
        int length = 0;
        int validList = 1; //Assume the list is valid
        while (*(*(operations + i) + length) != '\0') {
            int storeLength = length; //checking the current vertix
            int to = *(*(operations + i) + storeLength);
            while (*(*(operations + i) + length + 1) != '\0') {
                length++;
                // if any vertices after the current vertix directs to the current vertix
                // the list is invalid, otherwise it is valid
                int from = *(*(operations + i) + length);
                //TODO: check if the vertex is in the graph
                if (myGraph[from]->adjacencyList[to] != NULL) { // to is the current vertix, from is the other vertix we are going to check.
                    validList = 0;
                    #ifdef DEBUG
                        printf("Invalid list %d: %d, %d\n",i, to, from);
                    #endif
                    break;
                }
            }
            if (validList == 0) {
                break;
            }
            length = storeLength;
            length++;
        }
        int midNum = 0;
        if (validList == 1) {
            midNum = *(*(operations + i) + (length - 1 )/2);
            sumOfMidNum += midNum;
            #ifdef DEBUG
                printf("Valid list: %d\n", midNum);
            #endif
        }
        i++;
    }

    printf("Sum of mid numbers: %d\n", sumOfMidNum);
    freeDoubleArray((void **)operations, (void (*)(void *))freeInt);
}

void goThroughOperationListUpgrade(const char * filename) {

    int **operations = NULL;

    readOperationInput(filename, &operations);

    int i = 0;
    int sumOfMidNum = 0;

    while (*(operations + i) != NULL) {
        int length = 0;
        int validList = 1; //Assume the list is valid
        while (*(*(operations + i) + length) != '\0') {
            int storeLength = length; //checking the current vertix
            int to = *(*(operations + i) + storeLength);
            while (*(*(operations + i) + length + 1) != '\0') {
                length++;
                // if any vertices after the current vertix directs to the current vertix
                // the list is invalid, otherwise it is valid
                int from = *(*(operations + i) + length);
                //TODO: check if the vertex is in the graph
                //O(n^2) complexity, bad sorting algorithm, but it works
                if (myGraph[from]->adjacencyList[to] != NULL) { // to is the current vertix, from is the other vertix we are going to check.
                    validList = 0;
                    int temp = from;
                    if (length - storeLength > 1) {
                        for (int j = length; j > storeLength; j--){
                            *(*(operations + i) + j) = *(*(operations + i) + j - 1);
                        }
                    } else {
                        *(*(operations + i) + length) = to;
                    }
                    *(*(operations + i) + storeLength) = temp;
                    to = temp; //update new "to"
                    #ifdef DEBUG
                        printf("Invalid list %d: %d, %d\n",i, to, from);
                        for (int j = 0; *(*(operations + i) + j) != '\0'; j++) {
                            printf("%d ", *(*(operations + i) + j));
                        }
                        printf("\n");
                    #endif
                }
            }
            length = storeLength;
            length++;
        }
        int midNum = 0;
        if (validList == 0) {
            midNum = *(*(operations + i) + (length - 1 )/2);
            sumOfMidNum += midNum;
            #ifdef DEBUG
                printf("Valid list: %d\n", midNum);
                //for (int j = 0; *(*(operations + i) + j) != '\0'; j++) {
                //    printf("%d, ", *(*(operations + i) + j));
                //}
                //printf("\n");
            #endif
        }
        i++;
    }

    printf("Sum of mid numbers: %d\n", sumOfMidNum);
    freeDoubleArray((void **)operations, (void (*)(void *))freeInt);
}

