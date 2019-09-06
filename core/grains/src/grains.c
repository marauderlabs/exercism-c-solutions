#include "grains.h"

uint64_t
square (uint8_t index)
{
    uint64_t prod = 1;
    
    if (index == 0 || index > 64) { // invalid square
        return 0;
    }

    index--; // no shift for 1. and 1 less for others, to get power of (multiply by) 2.
    return (prod<<index);
}

uint64_t
total (void)
{
    uint64_t sum = 0;

    for (uint8_t i = 1; i <= SQUARES; i++) {
        sum += square(i);
    }

    return sum;
}
