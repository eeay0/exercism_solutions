#include "two_fer.h"
#include <stdio.h>
#include <string.h>
void two_fer(char* buffer, const char* name)
{
    if (name == NULL) {
        snprintf(buffer, 90, "One for you, one for me.");
    } else {
        snprintf(buffer, 90, "One for %s, one for me.", name);
    }
}
