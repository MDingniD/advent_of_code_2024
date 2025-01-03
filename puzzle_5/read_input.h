#ifndef READ_INPUT_H_
#define READ_INPUT_H_

#define MAX_INPUT_SIZE 1048576 // 1MB
#define MAX_LINE_SIZE 2048 // 2KB
#define MAX_NUMBER_OF_LINES 2048 // 2K
#define PERMS 0x1FF
#define MODE_R 0x0
#define SIZE_OF_INT 2


extern int myLength;



/*
readInput:
@param filename: the name of the file to read(file that contains the edge list)
@param data: the 2D array to store the list of Strings(edges)
readInput reads the file and stores the data in the 2D array

- the 2D array is allocated memory in the function and defined in the caller function
- the caller function is responsible for freeing the memory allocated for the 2D array
*/
void readInput(const char *filename, char ***data);

/*
readOperationInput:
@param filename: the name of the file to read(file that contains the operation list)
@param data: the 2D array to store the list of Strings(operations)
*/
void readOperationInput (const char *filename, int ***data);

void freeDoubleArray(void **array, void (*freeElement)(void *));

void freeString(void *string);

void freeInt(void *integer);

void freeEdge(void *e);

void freeVertex(void *g);

int getPointerSize(void **array);

#endif