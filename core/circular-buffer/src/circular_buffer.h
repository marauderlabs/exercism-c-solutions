#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>
#include <stddef.h>

typedef int buffer_value_t;
typedef int16_t status_t;

typedef struct circular_buffer_s {
    int head;
    int tail;
    buffer_value_t *buffer;
    size_t max_cap;     /* capacity */
    size_t free_cap;     /* capacity */
} circular_buffer_t;

status_t write(circular_buffer_t *buffer, const buffer_value_t value);
status_t read(circular_buffer_t *buffer, buffer_value_t *value);
status_t overwrite(circular_buffer_t *buffer, const buffer_value_t value);
circular_buffer_t* new_circular_buffer(size_t cap);
void delete_buffer(circular_buffer_t *buffer);
void clear_buffer(circular_buffer_t *buffer);

#endif /* CIRCULAR_BUFFER_H */
