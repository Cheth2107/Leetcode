#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    int freq[1001] = {0}; // Frequency array for elements in arr1
    int idx = 0;
    
    // Count the frequency of each element in arr1
    for (int i = 0; i < arr1Size; i++) {
        freq[arr1[i]]++;
    }
    
    // Sort the elements in arr1 based on their order in arr2
    int* result = (int*)malloc(arr1Size * sizeof(int));
    for (int i = 0; i < arr2Size; i++) {
        while (freq[arr2[i]]-- > 0) {
            result[idx++] = arr2[i];
        }
    }
    
    // Sort the remaining elements that are not in arr2
    for (int i = 0; i < 1001; i++) {
        while (freq[i]-- > 0) {
            result[idx++] = i;
        }
    }
    
    *returnSize = arr1Size;
    return result;
}
