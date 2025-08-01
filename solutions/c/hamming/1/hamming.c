#include "hamming.h"
#include <string.h>
int compute(const char* lhs, const char* rhs)
{
    if (strlen(lhs) != strlen(rhs)) {
        return -1;
    }
    int count = 0;
    for (int i = 0; i < (int) strlen(rhs); i++) {
        if (lhs[i] != rhs[i]) {
            count++;
        }
    }
    return count;
}
