#include "hamming.h"

int
compute(const char *lhs, const char *rhs)
{
    if (!lhs || !rhs) {
        return INVALID_LEN;
    }

    int i;
    int diff = 0;

    for (i = 0; lhs[i] != '\0' && rhs[i] != '\0'; i++) {
        if (lhs[i] != rhs[i]) {
            diff++;
        }
    }

    if (lhs[i] != rhs[i]) { // are both NUL chars? ie, equal len
        return INVALID_LEN;
    }

    return diff;
}
