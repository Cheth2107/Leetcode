#include <stdlib.h> // For abs function
#include <string.h> // For strlen function

int scoreOfString(char* s) {
    int score = 0;
    int length = strlen(s);

    for (int i = 0; i < length - 1; ++i) {
        score += abs(s[i] - s[i + 1]);
    }

    return score;
}
