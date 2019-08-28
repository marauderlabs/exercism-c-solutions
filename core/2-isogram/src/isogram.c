#include "isogram.h"

bool 
is_isogram(const char phrase[])
{
    bool dict[CHARS] = {false}; //dict for lowercase chars. 

    //memset(dict, 0, sizeof(bool)*CHARS);

    if (!phrase) {
        return false;
    }

    for (const char *p = &phrase[0]; '\0' != *p; p++)
    {
        char c = *p;

        // make everything lowercase.
        if (isupper(c)) {
            c = tolower(c);
        }

        if (isalpha(c)) {
            if (dict[c - 'a']) {
                return false;
            }
            // if char is of interest, do some book keeping in our dict/hashtable
            dict[c - 'a'] = true;
        }
    }

    return true;
}
