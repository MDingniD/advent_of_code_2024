#ifndef READ_INPUT_H_
#define READ_INPUT_H_

#define MAX_INPUT_SIZE 1048576 // 1MB
#define PERMS 0x1FF
#define MODE_R 0x0

extern char *myInput;
extern int myLength;

void readInput(const char *filename);

#endif