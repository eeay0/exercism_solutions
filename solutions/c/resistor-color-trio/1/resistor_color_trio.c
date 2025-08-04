#include "resistor_color_trio.h"
#include <math.h>
#include <stdint.h>
resistor_value_t color_code(resistor_band_t colors[]) {
  resistor_value_t result;
  result.value = colors[0] * 10 + colors[1];
  long unsigned int res = result.value * pow(10, colors[2]);

  if (res >= 1000 && res < 1000000) {
    result.unit = KILOOHMS;
    result.value = res / 1000;
  } else if (res >= 1000000 && res < 1000000000) {
    result.unit = MEGAOHMS;
    result.value = res / 1000000;
  } else if (res >= 1000000000) {
    result.unit = GIGAOHMS;
    result.value = res / 1000000000;
  } else {
    result.unit = OHMS;
    result.value = res;
  }

  return result;
}
