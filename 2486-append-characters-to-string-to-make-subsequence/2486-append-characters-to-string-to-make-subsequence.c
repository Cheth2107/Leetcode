int appendCharacters(char* s, char* t) {
    int i = 0; // Pointer for s
    int j = 0; // Pointer for t
    
    // Traverse through string s
    while (s[i] != '\0') {
        // If the characters match, move the pointer for t
        if (s[i] == t[j]) {
            j++;
        }
        // Move the pointer for s
        i++;
    }
    
    // The number of characters left in t to be appended
    return strlen(t) - j;
}
