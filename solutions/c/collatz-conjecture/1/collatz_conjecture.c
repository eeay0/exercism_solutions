#include "collatz_conjecture.h"
int steps(int start)
{
    if (start <= 0) {
        return ERROR_VALUE;
    }

    int steps = 0;

    while (start > 1) {
        if (start % 2 == 0) {
            start /= 2;
            steps++;
        } else if (start % 2 != 0) {
            start = (start * 3) + 1;
            steps++;
        }
    }

    return steps;
}

