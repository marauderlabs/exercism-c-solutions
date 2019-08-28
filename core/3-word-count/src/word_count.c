#include "word_count.h"

// convert the string to lower case
void string_tolower(char *s)
{
    for (; *s != '\0'; s++)
    {
        *s = tolower(*s);
    }
}

// trim punctuations on both sides
void string_trim_punct(char *s)
{
    // left side
    int l = strlen(s);
    int i = 0;
    for (; s[i] != '\0' && !(isalpha(s[i]) || isnumber(s[i])); i++)
        ;

    if (i > 0)
    {
        memmove(&s[0], &s[i], l - i);
    }

    // right side
    for (; l >= 0; l--)
    {
        if (isalpha(s[l]) || isnumber(s[l]))
        {
            return;
        }
        s[l] = '\0';
    }
}

// add word to the words array and increment it's count.
// return new length of words array (the number of actual words in it. empty ones ignored)
int count(const char *word, word_count_word_t *words, int len)
{
    int i;

    if (!strlen(word))
    {
        return len;
    }

    for (i = 0; i < len; i++, words++)
    {
        if (0 == strncmp(word, words->text, MAX_WORD_LENGTH))
        {
            words->count++;
            return len; // existing word
        }
    }

    // New word
    strcpy(words->text, word);
    words->count++;
    return (len + 1);
}

int word_count(const char *input_text, word_count_word_t *words)
{
    char *input = strdup(input_text);
    int wc = 0;

    memset(words, 0, (sizeof(word_count_word_t) * MAX_WORDS));

    for (char *tok = strtok(input, DELIM); NULL != tok; tok = strtok(NULL, DELIM))
    {
        if (wc >= MAX_WORDS) // >= because we count later
        {
            FREE(input);
            return EXCESSIVE_NUMBER_OF_WORDS;
        }

        if (strlen(tok) > MAX_WORD_LENGTH)
        {
            FREE(input);
            return EXCESSIVE_LENGTH_WORD;
        }

        string_trim_punct(tok);
        string_tolower(tok);
        wc = count(tok, words, wc);
    }

    FREE(input);
    return wc;
}
