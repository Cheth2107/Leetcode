#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Helper function to compare two arrays
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

bool closeStrings(char* word1, char* word2) {
    if (strlen(word1) != strlen(word2)) {
        return false;
    }
    
    int count1[128] = {0};
    int count2[128] = {0};
    
    // Count the frequency of each character in both strings
    for (int i = 0; word1[i] != '\0'; i++) {
        count1[(int)word1[i]]++;
        count2[(int)word2[i]]++;
    }
    
    // Check if both strings have the same set of unique characters
    for (int i = 0; i < 128; i++) {
        if ((count1[i] == 0 && count2[i] != 0) || (count1[i] != 0 && count2[i] == 0)) {
            return false;
        }
    }
    
    // Create arrays of non-zero counts
    int freq1[128], freq2[128];
    int idx1 = 0, idx2 = 0;
    for (int i = 0; i < 128; i++) {
        if (count1[i] > 0) {
            freq1[idx1++] = count1[i];
        }
        if (count2[i] > 0) {
            freq2[idx2++] = count2[i];
        }
    }
    
    // Sort the frequency arrays
    qsort(freq1, idx1, sizeof(int), compare);
    qsort(freq2, idx2, sizeof(int), compare);
    
    // Compare sorted frequencies
    for (int i = 0; i < idx1; i++) {
        if (freq1[i] != freq2[i]) {
            return false;
        }
    }
    
    return true;
}