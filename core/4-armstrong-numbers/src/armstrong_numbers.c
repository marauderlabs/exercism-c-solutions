#include "armstrong_numbers.h"

bool
isArmstrongNumber(int n)
{
    char buffer[MAX_DIGITS] = { '\0', };
    int orig  = n;
    int sum   = 0;
    int digit = 0;

    // a simple way to count the number of digits in the number
    int digitCount = sprintf(buffer, "%u", n);

    // get the digits and raise them to the power, digitCount and sum them
    while (n > 0) {
        digit = n % 10;
        n /= 10;
        sum += pow(digit, digitCount);
    }

    if (orig == sum) {
        return true;
    }

    return false;
}
