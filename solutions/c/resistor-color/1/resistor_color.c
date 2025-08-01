#include "resistor_color.h"

const resistor_band_t color_arry[] = {BLACK, BROWN, RED,    ORANGE, YELLOW,
                                      GREEN, BLUE,  VIOLET, GREY,   WHITE};

uint16_t color_code(resistor_band_t color) { return (uint16_t)color; }

const resistor_band_t *colors(void) { return color_arry; }

