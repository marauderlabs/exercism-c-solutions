#include "list_ops.h"
#include "errno.h"
#include <string.h>

static list_t*
alloc_list(size_t length) {
    list_t *list = calloc(1, sizeof(list_t));
    if (!list) {
        errno = ENOMEM;
        return NULL;
    }
    list_value_t *values = calloc(length, sizeof(list_value_t));
    if (!values) {
        free(list);
        errno = ENOMEM;
        return NULL;
    }
    list->values = values;
    list->length = length;
    return list;
}

// constructs a new list.
/*
 * Tests expect valid non-null return even for empty lists. So return
 * non-null even on zero length
 */
list_t*
new_list(size_t length, list_value_t values[]) {
    list_t *list = alloc_list(length);
    if (!list) {
        return NULL;
    }
    if (length) {
        memcpy(list->values, values, (length * sizeof(list_value_t)));
    }
    return list;
}

// append entries to a list and return the new list
// instead of realloc of existing list, lets copy both to a new list.
list_t*
append_list(const list_t *list1, const list_t *list2) {
    list_t *new = alloc_list(list1->length + list2->length);
    if (!new) {
        return NULL;
    }

    if (list1->length) {
        memcpy(new->values, list1->values,
                (list1->length * sizeof(list_value_t)));
    }
    if (list2->length) {
        memcpy(new->values + list1->length, list2->values,
                (list2->length * sizeof(list_value_t)));
    }
    return new;
}

// filter list returning only values that satisfy the filter function
list_t*
filter_list(const list_t *list, filter_func_t filter_func) {
    list_t *new = alloc_list(list->length);
    if (!new) {
        return NULL;
    }

    size_t copied = 0;
    for (size_t i = 0; i < list->length; i++) {
        if (filter_func(list->values[i])) {
            new->values[copied++] = list->values[i];
        }
    }

    list_value_t *renew = NULL;
    if (copied == 0) {
        delete_list(new);
        return alloc_list(copied);
    } else if (copied != list->length) {
        renew = realloc(new->values, copied * sizeof(list_value_t));
        if (renew) {
            /**
             * mostly shouldn't fail but better safe than sorry!
             * no harm. Just reduce the length for the user;
             * Extra memory shall be unused but freed eventually anyway.
             */
            new->values = renew;
        }
        new->length = copied;
    }
    return new;
}

// returns the length of the list
size_t
length_list(const list_t *list) {
    return list->length;
}

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t*
map_list(list_t *list, map_func_t map_func) {
    list_t *new = alloc_list(list->length);
    if (!new) {
        return NULL;
    }
    for (size_t i = 0; i < list->length; i++) {
        new->values[i] = map_func(list->values[i]);
    }
    return new;
}

// folds (reduces) the given list from the left with a function
list_value_t
foldl_list(const list_t  *list, list_value_t initial, fold_func_t foldl_func) {
    list_value_t value = initial;
    for (size_t i = 0; i < list->length; i++) {
        value = foldl_func(list->values[i], value);
    }
    return value;
}

// folds (reduces) the given list from the right with a function
list_value_t
foldr_list(const list_t  *list, list_value_t initial, fold_func_t foldr_func) {
    list_value_t value = initial;
    if (!list->length) {
        return initial;
    }

    for (int i = list->length-1; i >= 0; i--) {
        value = foldr_func(list->values[i], value);
    }
    return value;
}

// reverse the elements of the list
list_t*
reverse_list(const list_t *list) {
    list_t *new = alloc_list(list->length);
    if (!new) {
        return NULL;
    }
    for (size_t i = 0, j = list->length-1; i < list->length; i++, j--) {
        new->values[j] = list->values[i];
    }
    return new;
}

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void
delete_list(list_t *list) {
    if (!list) {
        return;
    }
    if (list->values) {
        free(list->values);
        list->values = NULL;
    }
    free(list);
}
