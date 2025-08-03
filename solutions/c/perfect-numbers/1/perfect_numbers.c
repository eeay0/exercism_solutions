#include "perfect_numbers.h"

kind classify_number(int num)
{
    if (num <= 0) {
        return ERROR;
    }

    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    if (num == sum) {
        return PERFECT_NUMBER;
    } else if (num <= sum) {
        return ABUNDANT_NUMBER;
    } else {
        return DEFICIENT_NUMBER;
    }
}
