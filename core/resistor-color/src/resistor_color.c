#include "resistor_color.h"
#include <stdbool.h>

static resistor_band_t all_colors[COLORS_MAX];
static bool _init = false;

// return the value for the given color code
int
colorCode(resistor_band_t band)
{
    return (int)band;
}

// return a list of all the color codes/values
resistor_band_t*
colors()
{
    if (!_init) { // init once programmatically.
        for (resistor_band_t b = COLOR_START; b < COLORS_MAX; b++) {
            all_colors[b] = b;
        }
        _init = true;
    }
    return all_colors;
}
