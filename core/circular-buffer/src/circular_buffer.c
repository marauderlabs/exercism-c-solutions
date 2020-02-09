#include "circular_buffer.h"
#include <stdlib.h>
#include <errno.h>


circular_buffer_t*
new_circular_buffer (size_t cap) {
    circular_buffer_t *cbuf = calloc(1, sizeof(circular_buffer_t));
    if (!cbuf) {
        errno = ENOMEM;
        return NULL;
    }

    cbuf->buffer = calloc(cap, sizeof(buffer_value_t));
    if (!cbuf->buffer) {
        free(cbuf);
        errno = ENOMEM;
        return NULL;
    }

    cbuf->max_cap = cbuf->free_cap = cap;
    return cbuf;
}

status_t
write (circular_buffer_t *cbuf, const buffer_value_t value) {
    if (!cbuf->free_cap) {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }

    cbuf->buffer[cbuf->tail] = value;
    cbuf->tail = (cbuf->tail+1) % cbuf->max_cap;
    cbuf->free_cap--;

    return EXIT_SUCCESS;
}

status_t
read (circular_buffer_t *cbuf, buffer_value_t *value) {
    if (cbuf->max_cap  == cbuf->free_cap) {
        errno = ENODATA;
        return EXIT_FAILURE;
    }
    *value = cbuf->buffer[cbuf->head];
    cbuf->head = (cbuf->head+1) % cbuf->max_cap;
    cbuf->free_cap++;
    if (cbuf->max_cap  == cbuf->free_cap) {
        clear_buffer(cbuf);
    }
    return EXIT_SUCCESS;
}

status_t
overwrite (circular_buffer_t *cbuf, const buffer_value_t value) {
    if (!cbuf->free_cap) {
        cbuf->head = (cbuf->head+1) % cbuf->max_cap;
        cbuf->free_cap++;
    }
    write(cbuf, value);
    return EXIT_SUCCESS;
}

void
delete_buffer (circular_buffer_t *cbuf) {
    if (!cbuf) {
        return;
    }
    if (cbuf->buffer) {
        free(cbuf->buffer);
        cbuf->buffer = NULL;
    }
    free(cbuf);
}

void
clear_buffer(circular_buffer_t *cbuf) {
    cbuf->head = cbuf->tail = 0;
    cbuf->free_cap = cbuf->max_cap;
}
