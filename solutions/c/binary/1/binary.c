#include "binary.h"
#include <string.h>

int power(int base, int pow)
{
    if (pow == 0)
        return 1;
    else
        return base * power(base, pow - 1);
}

int convert(const char* input)
{
    int decimal = 0;
    int digit = 0;
    int len = strlen(input);

    for (int i = len - 1; i >= 0; i--, digit++) {
        if (input[i] == '1' || input[i] == '0') {
            if (input[i] == '1') {
                decimal += power(2, digit);
            }
        } else {
            return INVALID;
        }
    }
    return decimal;
}
