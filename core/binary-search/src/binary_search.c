#include "binary_search.h"

const int*
binary_search(int value, const int *arr, size_t length)
{
    if (length == 0) {
        return NULL;
    }
    return search_recursive(value, arr, 0, length-1);
}

const int*
search_recursive (int value, const int *arr, size_t min, size_t max)
{
    size_t mid = (min+max)/2;

    if (arr[mid] == value) {
        return &arr[mid];
    }

    if (min == max) {
        return NULL;
    }

    if (value < arr[mid]) {
        return search_recursive(value, arr, min, mid-1);
    } else {
        return search_recursive(value, arr, mid+1, max);
    }
}
