bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int max = 0;

    // Find maximum number of candies
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] > max)
            max = candies[i];
    }

    // Allocate memory for the result array
    bool* res = (bool*)malloc(candiesSize * sizeof(bool));
    if (res == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // Check if each kid can have the greatest number of candies
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] + extraCandies >= max) {
            res[i] = true;
        } else {
            res[i] = false;
        }
    }

    // Set returnSize
    *returnSize = candiesSize;

    return res;
}
