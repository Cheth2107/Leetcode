/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

bool existsInArray(int* arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {
    int* uniqueNums1 = (int*)malloc(nums1Size * sizeof(int));
    int* uniqueNums2 = (int*)malloc(nums2Size * sizeof(int));
    int uniqueNums1Size = 0;
    int uniqueNums2Size = 0;

    // Find unique elements in nums1 not in nums2
    for (int i = 0; i < nums1Size; i++) {
        if (!existsInArray(nums2, nums2Size, nums1[i]) && !existsInArray(uniqueNums1, uniqueNums1Size, nums1[i])) {
            uniqueNums1[uniqueNums1Size++] = nums1[i];
        }
    }

    // Find unique elements in nums2 not in nums1
    for (int i = 0; i < nums2Size; i++) {
        if (!existsInArray(nums1, nums1Size, nums2[i]) && !existsInArray(uniqueNums2, uniqueNums2Size, nums2[i])) {
            uniqueNums2[uniqueNums2Size++] = nums2[i];
        }
    }

    // Allocate result array
    int** result = (int**)malloc(2 * sizeof(int*));
    result[0] = (int*)malloc(uniqueNums1Size * sizeof(int));
    result[1] = (int*)malloc(uniqueNums2Size * sizeof(int));
    for (int i = 0; i < uniqueNums1Size; i++) {
        result[0][i] = uniqueNums1[i];
    }
    for (int i = 0; i < uniqueNums2Size; i++) {
        result[1][i] = uniqueNums2[i];
    }

    // Allocate returnColumnSizes array
    *returnColumnSizes = (int*)malloc(2 * sizeof(int));
    (*returnColumnSizes)[0] = uniqueNums1Size;
    (*returnColumnSizes)[1] = uniqueNums2Size;

    // Set returnSize
    *returnSize = 2;

    // Free temporary arrays
    free(uniqueNums1);
    free(uniqueNums2);

    return result;
}