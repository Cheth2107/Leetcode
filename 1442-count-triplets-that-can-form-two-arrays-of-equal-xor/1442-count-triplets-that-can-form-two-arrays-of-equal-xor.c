int countTriplets(int* arr, int arrSize) {
    int count = 0;

    for (int i = 0; i < arrSize - 1; i++) {
        int a = arr[i];
        for (int j = i + 1; j < arrSize; j++) {
            a ^= arr[j];
            int b = arr[j];
            for (int k = j; k < arrSize; k++) {
                b ^= arr[k];
                if (a == b) {
                    count++;
                }
            }
        }
    }

    return count;
}
