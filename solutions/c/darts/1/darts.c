#include "darts.h"
#include <math.h>
#include <stdint.h>

uint8_t score(coordinate_t landing_position)
{
    float x = (float) fabsf(landing_position.x);
    float y = (float) fabsf(landing_position.y);
    float length = sqrtf((x * x) + (y * y));

    if (length > 10) {
        return 0;
    }

    if ((length >= 0) && (length <= 1)) {
        return 10;
    } else if ((length > 1) && (length <= 5)) {
        return 5;
    } else {
        return 1;
    }
}
