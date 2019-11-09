#include "secret_handshake.h"
#include <stdlib.h>

static const char* code[] = {
    "wink",
    "double blink",
    "close your eyes",
    "jump"
};


void
reverse(const char** a, int len)
{
    const char *tmp;
    for (int i = 0; i < len/2; i++) {
        tmp = a[i];
        a[i] = a[len-i-1];
        a[len-i-1] = tmp;
    }
}

const char **
commands (size_t number)
{
    if (number > 0x1F) { // Binary 11111
        return NULL; // error
    }

    const int size = sizeof(code)/sizeof(code[0]);

    // Tests free the result and hence require us to alloc memory.
    const char** result = calloc(size, sizeof(char*));
    if (!result) {
        return NULL; // error
    }

    size_t mask = 1;
    int    idx  = 0;

    for (size_t bit = 0; bit < size; bit++) {
        if (number & mask) {
            result[idx++] = code[bit];
        }
        mask <<= 1;
    }

    if (number & mask) {
        reverse(result, idx);
    }

    return result;
}
