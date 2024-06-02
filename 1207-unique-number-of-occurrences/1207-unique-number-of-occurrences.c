#define MAX_NUM 1000
bool uniqueOccurrences(int* arr, int arrSize) {
    int counts[2001] = {0}; // To store counts of each number, assuming -1000 <= arr[i] <= 1000

    // Count the occurrences of each number in the array
    for (int i = 0; i < arrSize; i++) {
        counts[arr[i] + MAX_NUM]++;
    }

    bool occurrenceSet[2001] = {false}; // To track unique occurrences

    // Check for unique occurrences
    for (int i = 0; i < 2001; i++) {
        if (counts[i] > 0) {
            if (occurrenceSet[counts[i]]) {
                return false; // Duplicate occurrence found
            }
            occurrenceSet[counts[i]] = true;
        }
    }

    return true;
}