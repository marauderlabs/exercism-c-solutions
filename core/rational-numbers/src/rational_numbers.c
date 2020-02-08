#include <stdlib.h>
#include <math.h>

#include "rational_numbers.h"

static int
greatest_common_divisor(int a, int b)
{
    if (b == 0) {
        return a;
    }
    return greatest_common_divisor(b, a % b);
}

rational_t
add(rational_t r1, rational_t r2) {
    rational_t result;
    result.numerator = r1.numerator * r2.denominator +
            r2.numerator * r1.denominator;
    if (0 != result.numerator) {
        result.denominator = r1.denominator * r2.denominator;
    } else {
        result.denominator = 0;
    }
    return reduce(result);
}

rational_t
subtract(rational_t r1, rational_t r2) {
    r2.numerator *= -1;
    return add(r1, r2);
}

rational_t
multiply(rational_t r1, rational_t r2) {
    rational_t result;
    result.numerator = r1.numerator * r2.numerator;
    if (0 != result.numerator) {
        result.denominator = r1.denominator * r2.denominator;
    } else {
        result.denominator = 0;
    }
    return reduce(result);
}

rational_t
divide(rational_t r1, rational_t r2) {
    rational_t result;
    result.numerator = r1.numerator * r2.denominator;
    result.denominator = r1.denominator * r2.numerator;
    return reduce(result);
}

rational_t
absolute(rational_t r) {
    rational_t result;
    result.numerator = abs(r.numerator);
    result.denominator = abs(r.denominator);
    return reduce(result);
}

rational_t
exp_rational(rational_t r, int exponent) {
    rational_t result;
    result.numerator = pow(r.numerator, exponent);
    result.denominator = pow(r.denominator, exponent);
    return reduce(result);
}

float
exp_real(unsigned int x, rational_t exponent) {
    float result;
    if (exponent.numerator > 0) {
        result = pow(pow(x, exponent.numerator), 1.0/exponent.denominator);
    } else {
        result = 1.0/(pow(pow(x, exponent.numerator * -1),
                1.0/exponent.denominator));
    }
    return result;
}

rational_t
reduce(rational_t r) {
    rational_t result;
    if (0 != r.numerator) {
        int gcd = greatest_common_divisor(r.numerator, r.denominator);
        result.numerator = r.numerator/gcd;
        result.denominator = r.denominator/gcd;
    } else {
        result.numerator = 0;
        result.denominator = 1;
    }

    if (result.denominator < 0) {
        result.denominator *= -1;
        result.numerator *= -1;
    }
    return result;
}
