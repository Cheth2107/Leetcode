int maximumGain(char* s, int x, int y) {
    int max_points = 0;
    int n = strlen(s);
    char stack[n];
    int top = -1;

    // Process for "ab" first if x >= y, else process "ba" first
    if (x >= y) {
        // Remove "ab" first
        for (int i = 0; i < n; i++) {
            if (top >= 0 && stack[top] == 'a' && s[i] == 'b') {
                top--; // pop 'a'
                max_points += x;
            } else {
                stack[++top] = s[i]; // push current character
            }
        }

        // Process remaining stack for "ba"
        int new_top = -1;
        for (int i = 0; i <= top; i++) {
            if (new_top >= 0 && stack[new_top] == 'b' && stack[i] == 'a') {
                new_top--; // pop 'b'
                max_points += y;
            } else {
                stack[++new_top] = stack[i]; // push current character
            }
        }
    } else {
        // Remove "ba" first
        for (int i = 0; i < n; i++) {
            if (top >= 0 && stack[top] == 'b' && s[i] == 'a') {
                top--; // pop 'b'
                max_points += y;
            } else {
                stack[++top] = s[i]; // push current character
            }
        }

        // Process remaining stack for "ab"
        int new_top = -1;
        for (int i = 0; i <= top; i++) {
            if (new_top >= 0 && stack[new_top] == 'a' && stack[i] == 'b') {
                new_top--; // pop 'a'
                max_points += x;
            } else {
                stack[++new_top] = stack[i]; // push current character
            }
        }
    }

    return max_points;
}