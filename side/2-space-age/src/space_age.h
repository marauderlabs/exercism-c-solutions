#ifndef __SPACE_AGE_H__
#define __SPACE_AGE_H__

#include "time.h"

typedef enum planet_e {
    MERCURY,
    VENUS,
    EARTH,
    MARS,
    JUPITER,
    SATURN,
    URANUS,
    NEPTUNE,
} planet_t;

double
convert_planet_age(planet_t, time_t);

#endif /* __SPACE_AGE_H__ */

