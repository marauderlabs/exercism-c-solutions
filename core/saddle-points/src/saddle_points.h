#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX(A, B) (A > B ? A : B)
#define MIN(A, B) (A < B ? A : B)

typedef struct saddle_point_s {
    int row;
    int column;
} saddle_point_t;

typedef struct saddle_points_s {
    size_t count;
    saddle_point_t *points;
} saddle_points_t;

saddle_points_t* saddle_points(int row, int col, uint8_t matrix[row][col]);

void free_saddle_points (saddle_points_t* points);

#endif
