#include <stdio.h>
#include <stdlib.h>
#include "read_input.h"
#include "process_input.h"

int getNum(int *i, char *input, int *num) {
    int k = 0;
    char numStr[10];
    

    while (input[*i] >= '0' && input[*i] <= '9') {
        numStr[k] = input[*i];
        (*i)++;
        k++;
    }

    numStr[k] = '\0'; // null terminate the string

    if (k > 0) {
        *num = atoi(numStr);
        return 1;
        }
    else {
        *num = 0;
        return 0;
    }
}

void processInput(char *input, int typeOfProblem) {
    int sum = 0;
    int i = 0;
    int switchNum = 1; // mul operation is allowed at the beginning
    while (input[i] != '\0') {
        int sumOfMul = 0;
        // find the mul(int,int) when switchNum is 1, multiply the two numbers and add to sum
        if (input[i] == 'm' && switchNum == 1) {
            i++;
            if (input[i] == 'u') {
                i++;
                if (input[i] == 'l') {
                    i++;
                    if (input[i] == '(') {
                        i++;
                        int firstNum = 0;
                        int secondNum = 0;
                        if (getNum(&i, input, &firstNum)) {
                            if (input[i] == ',') {
                                i++;
                                if(getNum(&i, input, &secondNum)) {
                                    if (input[i] == ')') {
                                        i++;
                                        //printf("firstNum: %d, secondNum: %d\n", firstNum, secondNum);
                                        sumOfMul = firstNum * secondNum * switchNum;
                                        sum += sumOfMul;
                                    }
                                }
                            }
                        }
                        
                    }
                }
            }
        }
        else if (typeOfProblem == 2) {
            // find the do() and set switchNum to 1
            if (input[i] == 'd') {
                i++;
                if (input[i] == 'o') {
                    i++;
                    if (input[i] == '(') {
                        i++;
                        if (input[i] == ')') {
                            i++;
                            switchNum = 1;
                        }
                    }
                    // find the don't() and set switchNum to 0
                    else if (input[i] == 'n') {
                        i++;
                        if (input[i] == 39) {// ' = 39 
                            i++;
                            if (input[i] == 't') {
                                i++;
                                if (input[i] == '(') {
                                    i++;
                                    if (input[i] == ')') {
                                        i++;
                                        switchNum = 0;
                                        //printf("switchNum: %d\n", switchNum);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else {
                i++;
            }
        }
        else {       
            i++;
        }
    }
    printf("%d\n", sum);
}