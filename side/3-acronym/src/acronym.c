#include "acronym.h"

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

static uint8_t countSpacesHyphens (const char* phrase);

static uint8_t
countSpacesHyphens (const char* phrase)
{
    uint8_t spaces = 0;
    for (const char *p = phrase; *p != '\0'; p++) {
        if (' ' == *p || '-' == *p) {
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
    // 2 extra = 1 for nul char and 1 for 1st letter

    char* acro = calloc(countSpacesHyphens(phrase) + 2, sizeof(char));
    char* cursor = acro;
    for (char* tok = strtok(copy, " -"); NULL != tok; tok = strtok(NULL, " -")) {
        *cursor = toupper(tok[0]);
        cursor++;
    }
    *cursor = '\0';

    // free the dup
    free(copy); copy = NULL;

    if (!strlen(acro)) {
        free(acro); acro = NULL;
    }
    return acro;
}
