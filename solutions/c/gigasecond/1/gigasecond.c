#include "gigasecond.h"
void gigasecond(time_t input, char *output, size_t size) {
  time_t result = input + 1000000000;

  struct tm *time_info = gmtime(&result);

  strftime(output, size, "%Y-%m-%d %H:%M:%S", time_info);
}
