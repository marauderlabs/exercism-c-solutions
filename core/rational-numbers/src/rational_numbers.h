#ifndef RATIONAL_NUMBERS
#define RATIONAL_NUMBERS

typedef struct rational_number_s {
    int numerator;
    int denominator;
} rational_t;

rational_t absolute(rational_t r);
rational_t add(rational_t r1, rational_t r2);
rational_t subtract(rational_t r1, rational_t r2);
rational_t multiply(rational_t r1, rational_t r2);
rational_t divide(rational_t r1, rational_t r2);
rational_t exp_rational(rational_t r, int exponent);
float exp_real(unsigned int x, rational_t exponent);
rational_t reduce(rational_t r);

#endif
