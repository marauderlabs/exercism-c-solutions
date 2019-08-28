#ifndef PANGRAM_H
#define PANGRAM_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#define CHARS ('z' - 'a' + 1)

bool is_pangram(const char *sentence);

#endif
