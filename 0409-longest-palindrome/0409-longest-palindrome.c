int longestPalindrome(char* s) {
    int charCount[128] = {0};  // Array to count frequencies of each character (ASCII values)
    int length = 0;            // Length of the longest palindrome
    int oddCount = 0;          // Count of characters that have an odd frequency
    
    // Count the frequency of each character in the string
    for (int i = 0; s[i] != '\0'; i++) {
        charCount[(int)s[i]]++;
    }
    
    // Calculate the length of the longest palindrome
    for (int i = 0; i < 128; i++) {
        if (charCount[i] % 2 == 0) {
            length += charCount[i];
        } else {
            length += charCount[i] - 1;  // Use the largest even number less than the odd count
            oddCount = 1;  // At least one odd character can be placed in the center
        }
    }
    
    // If there is at least one character with an odd frequency, add one to the length
    // This is to account for the center character
    if (oddCount) {
        length++;
    }
    
    return length;

}