#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "process_input.h"
#include "read_input.h"



int xmasUp(int i, const char* input, int lengthOfLine) {
    int condition = i - 3 * lengthOfLine < 0;
    if (condition) {
        return 0;
    }
    i -= lengthOfLine;
    if (input[i] == 'M'){
        i -= lengthOfLine;
        if (input[i] == 'A'){
            i -= lengthOfLine;
            if (input[i] == 'S'){
                return 1;
            }
        }
    }
    return 0;
}

int xmasDown(int i, const char* input, int lengthOfLine) {
    int condition = i + 3 * lengthOfLine >= myLength - 1;

    if (condition) {
        return 0;
    }
    i += lengthOfLine;
    if (input[i] == 'M'){
        i += lengthOfLine;
        if (input[i] == 'A'){
            i += lengthOfLine;
            if (input[i] == 'S'){
                return 1;
            }
        }
    }
    return 0;
}

int xmasLeft(int i, const char* input, int lengthOfLine) {
    int condition = (i % lengthOfLine) - 3 < 0;

    if (condition) { // mod the length of line include the newline character '\n'
        return 0;
    }
    i--;
    if (input[i] == 'M'){
        i--;
        if (input[i] == 'A'){
            i--;
            if (input[i] == 'S'){
                return 1;
            }
        }
    }
    return 0;
}

int xmasRight(int i, const char* input, int lengthOfLine) {
    int condition = (i % lengthOfLine) + 3 >= lengthOfLine - 1;

    if (condition) { 
        return 0;
    }
    i++;
    if (input[i] == 'M'){
        i++;
        if (input[i] == 'A'){
            i++;
            if (input[i] == 'S'){
                return 1;
            }
        }
    }
    return 0;
}

int xmasUpLeft(int i, const char* input, int lengthOfLine) {
    int conditionUp     = i - 3 * lengthOfLine < 0;
    int conditionLeft   = (i % lengthOfLine) - 3 < 0;

    if (conditionUp || conditionLeft) {
        return 0;
    }
    i -= lengthOfLine;
    i--;
    if (input[i] == 'M'){
        i -= lengthOfLine;
        i--;
        if (input[i] == 'A'){
            i -= lengthOfLine;
            i--;
            if (input[i] == 'S'){
                return 1;
            }
        }
    }

    return 0;
    //TODO
}

int xmasUpRight(int i, const char* input, int lengthOfLine) {
    int conditionUp     = i - 3 * lengthOfLine < 0;
    int conditionRight  = (i % lengthOfLine) + 3 >= lengthOfLine - 1;
    if (conditionUp || conditionRight) {
        return 0;
    }
    i -= lengthOfLine;
    i++;
    if (input[i] == 'M'){
        i -= lengthOfLine;
        i++;
        if (input[i] == 'A'){
            i -= lengthOfLine;
            i++;
            if (input[i] == 'S'){
                return 1;
            }
        }
    }
    return 0;
}

int xmasDownLeft(int i, const char* input, int lengthOfLine) {
    int conditionDown   = i + 3 * lengthOfLine >= myLength - 1;
    int conditionLeft   = (i % lengthOfLine) - 3 < 0;
    if (conditionDown || conditionLeft) {
        return 0;
    }
    i += lengthOfLine;
    i--;
    if (input[i] == 'M'){
        i += lengthOfLine;
        i--;
        if (input[i] == 'A'){
            i += lengthOfLine;
            i--;
            if (input[i] == 'S'){
                return 1;
            }
        }
    }
    return 0;
}

int xmasDownRight(int i, const char* input, int lengthOfLine) {
    int conditionDown   = i + 3 * lengthOfLine >= myLength - 1;
    int conditionRight  = (i % lengthOfLine) + 3 >= lengthOfLine - 1;
    if (conditionDown || conditionRight) {
        return 0;
    }
    i += lengthOfLine;
    i++;
    if (input[i] == 'M'){
        i += lengthOfLine;
        i++;
        if (input[i] == 'A'){
            i += lengthOfLine;
            i++;
            if (input[i] == 'S'){
                return 1;
            }
        }
    }
    return 0;
}

int xmasCount(int i, const char* input, int lengthOfLine) {
    int total = 0;
    total += xmasUp(i, input, lengthOfLine);
    total += xmasDown(i, input, lengthOfLine);
    total += xmasLeft(i, input, lengthOfLine);
    total += xmasRight(i, input, lengthOfLine);
    total += xmasUpLeft(i, input, lengthOfLine);
    total += xmasUpRight(i, input, lengthOfLine);
    total += xmasDownLeft(i, input, lengthOfLine);
    total += xmasDownRight(i, input, lengthOfLine);
    return total;
}

int xmasMatrix(int i, const char* input, int lengthOfLine) {
    int total = 0;
    int conditionUp     = i - 1 * lengthOfLine < 0;
    int conditionDown   = i + 1 * lengthOfLine >= myLength - 1;
    int conditionLeft   = (i % lengthOfLine) - 1 < 0;
    int conditionRight  = (i % lengthOfLine) + 1 >= lengthOfLine - 1;
    if (conditionUp || conditionDown || conditionLeft || conditionRight) {
        return 0;
    }    
    // Start with up left corner is M
    if (input[i - lengthOfLine - 1] == 'M') {
        if (input[i - lengthOfLine + 1] == 'M') { // up right corner is M
            if (input[i + lengthOfLine - 1] == 'S') { // down left corner is S
                if (input[i + lengthOfLine + 1] == 'S') { // down right corner is S
                    return 1;
                }
            }   
        }
        if (input[i - lengthOfLine + 1] == 'S') { // up right corner is S
            if (input[i + lengthOfLine - 1] == 'M') { // down left corner is M
                if (input[i + lengthOfLine + 1] == 'S') { // down right corner is S
                    return 1;
                }
            }
        }
    }
    // Then up left corner is S
    if (input[i - lengthOfLine - 1] == 'S') {
        if (input[i - lengthOfLine + 1] == 'S') { // up right corner is M
            if (input[i + lengthOfLine - 1] == 'M') { // down left corner is S
                if (input[i + lengthOfLine + 1] == 'M') { // down right corner is S
                    return 1;
                }
            }   
        }
        if (input[i - lengthOfLine + 1] == 'M') { // up right corner is S
            if (input[i + lengthOfLine - 1] == 'S') { // down left corner is M
                if (input[i + lengthOfLine + 1] == 'M') { // down right corner is S
                    return 1;
                }
            }
        }
    }
    return 0;
}

void findAllXmas(const char* input) {
    int i = 0;
    int total = 0;
    int lengthOfLine = 0;
    for (lengthOfLine = 0; input[lengthOfLine] != '\n'; lengthOfLine++);
    lengthOfLine++; // include the newline character '\n'
    printf("Length of line: %d\n", lengthOfLine);
    while (input[i] != '\0') {
        if (input[i] == 'X') {
            total += xmasCount(i, input, lengthOfLine);
        }
        i++;
    }
    printf("Total number of XMAS: %d\n", total);
}

void findAllRealXmas(const char* input) {
    int i = 0;
    int total = 0;
    int lengthOfLine = 0;
    for (lengthOfLine = 0; input[lengthOfLine] != '\n'; lengthOfLine++);
    lengthOfLine++; // include the newline character '\n'
    printf("Length of line: %d\n", lengthOfLine);
    while (input[i] != '\0') {
        if (input[i] == 'A') {
            total += xmasMatrix(i, input, lengthOfLine);
        }
        i++;
    }
    printf("Total number of real XMAS: %d\n", total);
}