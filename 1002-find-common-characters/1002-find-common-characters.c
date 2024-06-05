/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** words, int wordsSize, int* returnSize){
    // Edge case: if there are no words, return an empty array
    if (wordsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Initialize min frequency array to a large number
    int minFreq[26];
    for (int i = 0; i < 26; ++i) {
        minFreq[i] = INT_MAX;
    }

    // Process each word
    for (int i = 0; i < wordsSize; ++i) {
        int wordFreq[26] = {0};
        char* word = words[i];
        
        // Count frequencies of each character in the current word
        for (int j = 0; word[j] != '\0'; ++j) {
            wordFreq[word[j] - 'a']++;
        }

        // Update the min frequency array
        for (int j = 0; j < 26; ++j) {
            if (wordFreq[j] < minFreq[j]) {
                minFreq[j] = wordFreq[j];
            }
        }
    }

    // Collect the common characters
    char** result = (char**)malloc(wordsSize * 26 * sizeof(char*));
    int index = 0;
    
    for (int i = 0; i < 26; ++i) {
        while (minFreq[i] > 0) {
            result[index] = (char*)malloc(2 * sizeof(char)); // Allocate space for one character and the null terminator
            result[index][0] = 'a' + i;
            result[index][1] = '\0';
            index++;
            minFreq[i]--;
        }
    }

    *returnSize = index;
    return result;
}