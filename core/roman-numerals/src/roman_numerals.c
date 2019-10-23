#include "roman_numerals.h"

void
to_roman(const char* one, const char* five, const char* ten, unsigned int n, char* str)
{
    switch (n) {
        case 1:
        case 2:
        case 3:
            for (unsigned int i = 0; i < n; i++) {
                strcat(str, one);
            }
            break;
        case 4:
                strcat(str, one);
        case 5:
                strcat(str, five);
                break;
        case 6:
        case 7:
        case 8:
            strcat(str, five);
            for (unsigned int i = 0; i < n-5; i++) {
                strcat(str, one);
            }
            break;
        case 9:
            strcat(str, one);
            strcat(str, ten);
            break;
    }
}

char*
to_roman_numeral (unsigned int number)
{
    char *buffer = calloc(BUF_LEN, sizeof(char));

    if (number <=0 || number > 3000) {
        return NULL;
    }

    to_roman("M", "",  "",  number/1000, buffer);
    to_roman("C", "D", "M", number/100%10, buffer);
    to_roman("X", "L", "C", number/10%10, buffer);
    to_roman("I", "V", "X", number%10, buffer);

    return buffer;
}
