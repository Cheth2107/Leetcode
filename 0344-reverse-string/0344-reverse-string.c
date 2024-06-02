void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;
    while (left < right) {
        // Swap the characters at the left and right pointers
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        
        // Move the pointers towards the center
        left++;
        right--;
    }
}
