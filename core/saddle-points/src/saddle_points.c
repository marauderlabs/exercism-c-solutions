#include "saddle_points.h"

saddle_points_t* saddle_points (int row, int col, uint8_t matrix[row][col]) {
    uint8_t row_max[row];
    uint8_t col_min[col];

    saddle_point_t points[row * col];

    memset(&row_max, 0, (sizeof(uint8_t) * row));
    memset(&col_min, UINT8_MAX, (sizeof(uint8_t) * col));

    // find the max every row and min every col
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            uint8_t val = matrix[r][c];
            row_max[r] = MAX(row_max[r], val);
            col_min[c] = MIN(col_min[c], val);
        }
    }

    // if an element is that, it's the saddle-point
    size_t count = 0;
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            uint8_t val = matrix[r][c];
            if ((val == row_max[r]) && (val == col_min[c])) {
                points[count].row = r+1;
                points[count].column = c+1;
                count++;
            }
        }
    }

    saddle_points_t *result = calloc(1, sizeof(saddle_points_t));
    result->points = calloc(count, sizeof(saddle_point_t));
    memcpy(result->points, &points, sizeof(saddle_point_t) * count);
    result->count = count;
    return result;
}

void free_saddle_points (saddle_points_t* result) {
    free(result->points);
    free(result);
}
