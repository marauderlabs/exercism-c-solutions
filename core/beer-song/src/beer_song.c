#include "beer_song.h"

#define LINE_X "%u bottles of beer on the wall, %u bottles of beer.\n"\
               "Take one down and pass it around, %u %s of beer on the wall.\n"

#define LINE_1 "1 bottle of beer on the wall, 1 bottle of beer.\n"\
               "Take it down and pass it around, no more bottles of beer on the wall.\n"

#define LINE_0 "No more bottles of beer on the wall, no more bottles of beer.\n"\
               "Go to the store and buy some more, 99 bottles of beer on the wall.\n"

unsigned int
verse (char *buffer, unsigned int verse_number)
{
    switch (verse_number) {

        case 0:
            return sprintf(buffer, LINE_0);

        case 1:
            return sprintf(buffer, LINE_1);

        default:
        {
            const char* bottle = ((verse_number-1) == 1) ? "bottle" : "bottles";
            return sprintf(buffer, LINE_X, verse_number, verse_number, verse_number-1, bottle);
        }
    }
}

void
sing(char *buffer, unsigned int starting_verse_number,
          unsigned int ending_verse_number)
{
    unsigned int cursor = 0;    

    // simple typecast to avoid wrap around issues of ending_verse_number
    for (int i = starting_verse_number; i >= (int)ending_verse_number; i--) {

        cursor += verse(buffer + cursor, i);

        // newline only if not the last line
        if (i != (int)ending_verse_number) {
            cursor += sprintf(buffer + cursor, "\n");
        }
    }
}
