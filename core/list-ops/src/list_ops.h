#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdbool.h>

/* Types */
typedef int list_value_t;

typedef struct {
   size_t length;
   list_value_t *values;
} list_t;

// callback function for folding/reducing
typedef list_value_t (*fold_func_t) (list_value_t value, list_value_t initial);

// callback function for mapping
typedef list_value_t (*map_func_t) (list_value_t value);

// callback function for filtering
typedef bool (*filter_func_t) (list_value_t value);


/* Prototypes */
// constructs a new list
list_t *new_list(size_t length, list_value_t values[]);

// append entries to a list and return the new list
list_t* append_list(const list_t *list1, const list_t *list2);

// filter list returning only values that satisfy the filter function
list_t* filter_list(const list_t *list, filter_func_t filter_func);

// returns the length of the list
size_t length_list(const list_t *list);

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t* map_list(list_t  *list, map_func_t map_func);

// folds (reduces) the given list from the left with a function
list_value_t foldl_list(const list_t  *list, list_value_t initial,
      fold_func_t foldl_func);

// folds (reduces) the given list from the right with a function
list_value_t foldr_list(const list_t  *list, list_value_t initial,
      fold_func_t foldr_func);

// reverse the elements of the list
list_t* reverse_list(const list_t *list);

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t * list);

#endif /* LINKED_LIST_H */
