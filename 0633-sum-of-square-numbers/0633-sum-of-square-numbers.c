#include <math.h>

bool judgeSquareSum(int c) {
    for (long a = 0; a * a <= c; ++a) {
        long b2 = c - a * a;
        long b = sqrt(b2);
        if (b * b == b2) {
            return true;
        }
    }
    return false;
}
