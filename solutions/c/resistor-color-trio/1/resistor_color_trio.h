#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

#include <stdint.h>

typedef enum {
    BLACK = 0,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE
} resistor_band_t;

typedef enum { OHMS = 0, KILOOHMS, MEGAOHMS, GIGAOHMS } resistor_prefix_t;

typedef struct {
    uint16_t value;
    resistor_prefix_t unit;
} resistor_value_t;

// Function declaration
resistor_value_t color_code(resistor_band_t colors[]);

#endif
