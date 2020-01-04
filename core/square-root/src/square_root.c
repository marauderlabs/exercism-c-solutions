#include "square_root.h"

float squareRoot(float n) {
    float sqrt = 1;
    float tmp = 0;
    while (fabsf(tmp - sqrt) > 0.01) {
        tmp = sqrt;
        sqrt = (sqrt + n/sqrt)/2;
    }
    return sqrt;
}
