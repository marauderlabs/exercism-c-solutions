#include "pangram.h"

bool is_pangram(const char *s)
{
    bool found[CHARS] = { false, };
    uint8_t unique = 0;

    if (NULL == s) {
        return false;
    }
    
    for (uint8_t i = 0, l = strlen(s); i < l; i++) {
        if (!isalpha(s[i])) {
           continue; 
        } 
        uint8_t idx = tolower(s[i]) - 'a';

        if (false == found[idx]) {
            // found a new char that's not been seen already
            found[idx] = true;
            unique++;
        }

        // found 26 unique chars
        if (CHARS == unique) {
            return true;
        }
    }

    return false;
}
