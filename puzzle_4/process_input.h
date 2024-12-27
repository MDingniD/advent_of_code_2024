#ifndef PROCESS_INPUT_H_
#define PROCESS_INPUT_H_

int xmasUp(int i, const char* input, int lengthOfLine);

int xmasDown(int i, const char* input, int lengthOfLine);

int xmasLeft(int i, const char* input, int lengthOfLine);

int xmasRight(int i, const char* input, int lengthOfLine);

int xmasUpLeft(int i, const char* input, int lengthOfLine);

int xmasUpRight(int i, const char* input, int lengthOfLine);

int xmasDownLeft(int i, const char* input, int lengthOfLine);

int xmasDownRight(int i, const char* input, int lengthOfLine);

void findAllXmas(const char* input);

void findAllRealXmas(const char* input);

#endif