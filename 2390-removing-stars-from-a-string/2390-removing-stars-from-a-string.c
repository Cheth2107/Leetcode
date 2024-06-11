char* removeStars(char* s) {
    int length = strlen(s);
    char* stack = (char*)malloc(length + 1); // allocate space for the stack
    int top = -1; // stack pointer
    
    for (int i = 0; i < length; i++) {
        if (s[i] == '*') {
            if (top >= 0) {
                top--; // pop the top character if we encounter a star
            }
        } else {
            top++;
            stack[top] = s[i]; // push the character onto the stack
        }
    }
    
    stack[top + 1] = '\0'; // null-terminate the resulting string
    
    // Optionally, resize the stack to the exact size of the resulting string
    stack = (char*)realloc(stack, top + 2);
    
    return stack;
}