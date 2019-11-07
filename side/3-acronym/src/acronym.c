#include "acronym.h"

uint8_t
countSpaces (const char* phrase)
{
    uint8_t spaces = 0;
    for (const char *p = phrase; *p != '\0'; p++) {
        if (*p == ' ') {
            spaces++;
        }
    }
    return spaces;
}

char*
abbreviate (const char* phrase)
{
    if (!phrase) {
        return NULL;
    }

    char* copy = strdup(phrase);

    // assume worstcase and count spaces. No harm in using extra space.
    // The prototype forces us to not free this space! Uh oh!!
    char* acro = calloc(countSpaces(phrase)+1, sizeof(char));
    char* cursor = acro;

    for (char* tok = strtok(copy, " -"); NULL != tok; tok = strtok(NULL, " -")) {
        *cursor = toupper(tok[0]);
        cursor++;
    }

    // free the dup
    free(copy); copy = NULL;

    if (!strlen(acro)) {
        free(acro); acro = NULL;
    }
    return acro;
}
