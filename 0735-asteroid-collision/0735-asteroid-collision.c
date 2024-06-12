#include <stdlib.h>

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int* stack = (int*)malloc(asteroidsSize * sizeof(int));
    int stackSize = 0;

    for (int i = 0; i < asteroidsSize; ++i) {
        int current = asteroids[i];
        int flag = 1;

        while (stackSize > 0 && current < 0 && stack[stackSize - 1] > 0) {
            if (stack[stackSize - 1] < -current) {
                stackSize--;
            } else if (stack[stackSize - 1] == -current) {
                stackSize--;
                flag = 0;
                break;
            } else {
                flag = 0;
                break;
            }
        }

        if (flag) {
            stack[stackSize++] = current;
        }
    }

    *returnSize = stackSize;
    return stack;
}
