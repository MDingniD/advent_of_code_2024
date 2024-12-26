#ifndef READ_INPUT_H_
#define READ_INPUT_H_

#define MAX_INPUT_SIZE 40960 // 4KB size of input
#define PERMS 0x1FF
#define MODE_R 0x0

extern char *myInput;

void readInput(const char *filename);




#endif // READ_INPUT_H_

