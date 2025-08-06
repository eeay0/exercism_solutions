#include "clock.h"
#include <stdio.h>
#include <string.h>

clock_t clock_create(int hour, int minute) {
  int total_minutes = hour * 60 + minute;
  total_minutes = ((total_minutes % 1440) + 1440) % 1440;

  hour = total_minutes / 60;
  if (hour == 24) {
    hour = 0;
  }
  minute = total_minutes % 60;

  clock_t clock;
  snprintf(clock.text, MAX_STR_LEN, "%02d:%02d", hour, minute);
  return clock;
}

clock_t clock_add(clock_t clock, int minute_add) {
  int minute = 0;
  int hour = 0;
  clock_t clock_tmp;

  sscanf(clock.text, "%d:%d", &hour, &minute);

  int total_minutes = hour * 60 + minute + minute_add;
  total_minutes = ((total_minutes % 1440) + 1440) % 1440;

  hour = total_minutes / 60;
  if (hour == 24) {
    hour = 0;
  }
  minute = total_minutes % 60;
  snprintf(clock_tmp.text, MAX_STR_LEN, "%02d:%02d", hour, minute);

  return clock_tmp;
}
clock_t clock_subtract(clock_t clock, int minute_subtract) {
  int minute = 0;
  int hour = 0;
  clock_t clock_tmp;

  sscanf(clock.text, "%d:%d", &hour, &minute);

  int total_minutes = hour * 60 + minute - minute_subtract;
  total_minutes = ((total_minutes % 1440) + 1440) % 1440;

  hour = total_minutes / 60;
  if (hour == 24) {
    hour = 0;
  }
  minute = total_minutes % 60;
  snprintf(clock_tmp.text, MAX_STR_LEN, "%02d:%02d", hour, minute);

  return clock_tmp;
}
bool clock_is_equal(clock_t a, clock_t b) {
  if (strcmp(a.text, b.text) == 0) {
    return true;
  } else {
    return false;
  }
}
