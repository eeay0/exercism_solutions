#include "binary_search.h"
#include <stddef.h>

const int *binary_search(int value, const int *arr, size_t length) {
  if (length == 0) {
    return NULL;
  }

  int left = 0;
  int right = length - 1;
  int middle = (left + right) / 2;

  while (left <= right) {
    middle = (left + right) / 2;
    if (arr[middle] == value) {
      return &arr[middle];
    }
    if (value < arr[middle]) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }
  return NULL;
}
