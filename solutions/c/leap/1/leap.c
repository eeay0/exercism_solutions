#include "leap.h"

bool leap_year(int year) {
  if (year % 4 == 0 && year % 200 == 0) {
    return 1;
  } else {
    return 0;
  }
}
