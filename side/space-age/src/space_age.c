#include "space_age.h"

double
convert_planet_age (planet_t p, time_t t)
{
    switch (p) {
        case MERCURY:
            return EARTH_AGE(t)/0.2408467;
        case VENUS:
            return EARTH_AGE(t)/0.61519726;
        case EARTH:
            return EARTH_AGE(t);
        case MARS:
            return EARTH_AGE(t)/1.8808158;
        case JUPITER:
            return EARTH_AGE(t)/11.862615;
        case SATURN:
            return EARTH_AGE(t)/29.447498;
        case URANUS:
            return EARTH_AGE(t)/84.016846;
        case NEPTUNE:
            return EARTH_AGE(t)/164.79132;
        default:
            return t;
    }
}
