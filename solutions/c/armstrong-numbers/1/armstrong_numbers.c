#include "armstrong_numbers.h"
#include <math.h>
bool is_armstrong_number(int candidate) {
  if (candidate == 0) {
    return true;
  }
  int sum = 0;
  int count = 0;
  int tmp_candidate = candidate;

  int digit_c = (int)floorf(log10(candidate)) + 1;

  while (count < digit_c) {
    sum += pow(tmp_candidate % 10, digit_c);
    tmp_candidate /= 10;
    count++;
  }
  if (sum == candidate) {
    return true;
  } else {
    return false;
  }
}
