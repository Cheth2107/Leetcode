#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the initial size of the stack and buffer
#define INITIAL_SIZE 1000

// Function to dynamically allocate and resize strings
char* allocateString(int size) {
    char* str = (char*)malloc(size * sizeof(char));
    str[0] = '\0';
    return str;
}

char* resizeString(char* str, int newSize) {
    str = (char*)realloc(str, newSize * sizeof(char));
    return str;
}

char* decodeString(char* s) {
    int numStack[INITIAL_SIZE];
    char* strStack[INITIAL_SIZE];
    int numTop = -1;
    int strTop = -1;

    // Initial buffer size and current size for the main string
    int bufferSize = INITIAL_SIZE;
    char* currentStr = allocateString(bufferSize);
    int currentNum = 0;

    while (*s != '\0') {
        if (isdigit(*s)) {
            // Form the number
            currentNum = currentNum * 10 + (*s - '0');
        } else if (*s == '[') {
            // Push the number and current string onto their respective stacks
            numStack[++numTop] = currentNum;
            strStack[++strTop] = currentStr;
            // Reset currentNum and allocate new string for the current segment
            currentNum = 0;
            currentStr = allocateString(bufferSize);
        } else if (*s == ']') {
            // Pop the number from numStack and the string from strStack
            int repeatTimes = numStack[numTop--];
            char* tempStr = currentStr;
            currentStr = strStack[strTop--];

            // Calculate the new size needed
            int requiredSize = strlen(currentStr) + repeatTimes * strlen(tempStr) + 1;
            if (requiredSize > bufferSize) {
                currentStr = resizeString(currentStr, requiredSize);
                bufferSize = requiredSize;
            }

            // Repeat the string and concatenate
            for (int i = 0; i < repeatTimes; i++) {
                strcat(currentStr, tempStr);
            }
            free(tempStr);
        } else {
            // Append the character to currentStr
            int len = strlen(currentStr);
            if (len + 1 >= bufferSize) {
                bufferSize *= 2;
                currentStr = resizeString(currentStr, bufferSize);
            }
            currentStr[len] = *s;
            currentStr[len + 1] = '\0';
        }
        s++;
    }

    // Return the final decoded string
    return currentStr;
}