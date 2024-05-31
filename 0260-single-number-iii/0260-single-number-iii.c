#include <stdlib.h>

int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int xor_result = 0;
    
    // Step 1: XOR all elements to get the XOR of the two unique numbers
    for (int i = 0; i < numsSize; ++i) {
        xor_result ^= nums[i];
    }
    
    // Step 2: Find any set bit in the xor_result
    unsigned int set_bit = (unsigned int)xor_result & -(unsigned int)xor_result; // Isolates the rightmost set bit
    
    int num1 = 0, num2 = 0;
    
    // Step 3: Divide the elements into two groups and XOR each group
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] & set_bit) {
            num1 ^= nums[i];
        } else {
            num2 ^= nums[i];
        }
    }
    
    // Allocate memory for the result
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = num1;
    result[1] = num2;
    
    // Set the return size
    *returnSize = 2;
    
    return result;
}
