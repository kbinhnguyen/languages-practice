/* Problem statement: https://exercism.org/tracks/c/exercises/binary-search */
#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length) {
    if (arr >= arr + length) return NULL;

    const int *mid = arr + (length / 2);
    if (*mid == value) return mid;
    else if (*mid > value) return binary_search(value, arr, length / 2);
    return binary_search(value, (mid + 1), length % 2 == 0 ? length / 2 - 1 : length / 2);
}