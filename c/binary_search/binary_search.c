/* Problem statement: https://exercism.org/tracks/c/exercises/binary-search */
#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length) {
    if (length < 1)
        return NULL;
    else if (length == 1)
        return *arr == value ? arr : NULL;

    int mid = (length - 1) / 2;
    if (arr[mid] == value)
        return arr + mid;
    else if (arr[mid] > value)
        return binary_search(value, arr, mid);
    return binary_search(value, arr + mid + 1, length - mid - 1);
}