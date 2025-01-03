#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "read_input.h"
#include "data_structure.h"



int myLength;

void freeDoubleArray(void **array, void (*freeElement)(void *)) {
    int i = 0;
    while (*(array + i) != NULL) {
        freeElement(*(array + i));
        i++;
    }
    free(array);
}

int getPointerSize(void **array) {
    int i = 0;
    while (*(array + i) != NULL) {
        i++;
    }
    return i;
}

void freeString(void *string) {
    free((char *)string);
}

void freeInt(void *integer) {
    free((int *)integer);
}

void freeEdge(void *e) {
    free((edge *)e);
}


void freeVertex(void *v) {
    vertex *vertex = v;
    if (vertex->adjacencyList != NULL) {
        free(vertex->adjacencyList);
    }
    free(vertex);
}




void readInput(const char *filename, char ***data) {

    char *buffer;
    buffer = malloc(MAX_INPUT_SIZE * sizeof(char));

    int myDescriptor = open(filename, MODE_R, PERMS);
    if (myDescriptor == -1) {
        perror("Error opening file");
        exit(1);
    }
    myLength = read(myDescriptor, buffer, MAX_INPUT_SIZE);

    buffer[myLength] = '\0';

    int i = 0; // buffer index
    int j = 0; // data index
    int k = 0; // data pointer index

    *data = malloc(MAX_NUMBER_OF_LINES * sizeof(char*)); // allocate memory for data
    

    while (*(buffer + i) != '\0') {
        *(*data + k) = malloc(MAX_LINE_SIZE * sizeof(char)); // allocate memory for each line of String
        while (*(buffer + i) != '\n' ) {
            if (*(buffer + i) == '\0') {
                break;
            }
            *(*(*data + k) + j) = *(buffer + i); // copy the character from buffer to data line by line
            #ifdef DEBUG
                //printf("buffer + i = %c\n", *(*(*data + k) + j));
            #endif
            i++;
            j++;
        }
        *(*(*data + k) + j) = '\0';
        j = 0;
        i++;
        #ifdef DEBUG
            printf("Line %d: %s\n", k, *(*data + k));
        #endif
        k++;
    }

    #ifdef DEBUG
        //printf("k = %d\n", k);
    #endif
    *(*data + k) = NULL;
    close(myDescriptor);
    free(buffer);
}

void readOperationInput (const char *filename, int ***data) {
    char *buffer;
    buffer = malloc(MAX_INPUT_SIZE * sizeof(char));

    int myDescriptor = open(filename, MODE_R, PERMS);
    if (myDescriptor == -1) {
        perror("Error opening file");
        exit(1);
    }
    myLength = read(myDescriptor, buffer, MAX_INPUT_SIZE);

    buffer[myLength] = '\0';

    #ifdef DEBUG
        printf("buffer = %s\n", buffer);
    #endif

    int i = 0; // buffer index
    int j = 0; // data pointer index
    int k = 0; // list of integers index
    int h = 0; // temp string of integer index

    *data = malloc(MAX_NUMBER_OF_LINES * sizeof(int*)); // allocate memory for data
    char *integer = malloc(SIZE_OF_INT * sizeof(int));

    while (*(buffer + i) != '\0') {
        *(*data + j) = malloc(MAX_LINE_SIZE * sizeof(int)); // allocate memory for each line of String
        k = 0;
        while (*(buffer + i) != '\n' ) {
            h = 0;
            if (*(buffer + i) == '\0') {
                i--;
                break;
            }
            while (*(buffer + i) != ',') {
                if (*(buffer + i) == '\0' || *(buffer + i) == '\n') {
                    i--;
                    break;
                }
                integer[h] = *(buffer + i); // copy the character from buffer to data line by line
                #ifdef DEBUG
                    //printf("buffer + i = %d\n", integer[h]);
                #endif
                h++;
                i++;
            }
            integer[h] = '\0';
            h = 0;
            i++;
            *(*(*data + j) + k) = atoi(integer);
            k++;
            #ifdef DEBUG
                    //printf("data[%d][%d]= %d\n", j, k , *(*(*data + j) + k));
            #endif
        }
        #ifdef DEBUG
            for (int l = 0; l < k; l++) {
                printf("data[%d][%d]= %d\n", j, l , *(*(*data + j) + l));
            }
        #endif
        *(*(*data + j) + k) = '\0';
        j++;
        i++;
    }
    
    *(*data + j) = NULL;
    close(myDescriptor);
    free(integer);
    free(buffer);

}