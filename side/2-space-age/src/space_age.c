#include "space_age.h"

double
convert_planet_age (planet_t p, time_t t)
{
    switch (p) {
        case MERCURY:
            return t/31557600/0.2408467;
        case VENUS:
            return t/31557600/0.61519726;
        case EARTH:
            return t/31557600;
        case MARS:
            return t/31557600/1.8808158;
        case JUPITER:
            return t/31557600/11.862615;
        case SATURN:
            return t/31557600/29.447498;
        case URANUS:
            return t/31557600/84.016846;
        case NEPTUNE:
            return t/31557600/164.79132;
        default:
            return t;
    }
}
