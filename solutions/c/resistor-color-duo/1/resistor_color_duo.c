#include "resistor_color_duo.h"
uint16_t color_code(resistor_band_t resistor[])
{
    uint16_t res = resistor[0] * 10;
    res += resistor[1];

    return res;
}
