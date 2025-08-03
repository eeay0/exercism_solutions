#include "dnd_character.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

int modifier(int score)
{
    return floor((score - 10.0) / 2.0);
}

int ability(void)
{
    srand(time(NULL));
    int r1 = rand() % 7;
    int r2 = rand() % 7;
    int r3 = rand() % 7;
    int r4 = rand() % 7;

    int lowest = r1;

    if (r2 < lowest) {
        lowest = r2;
    } else if (r3 < lowest) {
        r3 = lowest;
    } else if (r4 < lowest) {
        r4 = lowest;
    }
    return r1 + r2 + r3 + r4 - lowest;
}

dnd_character_t make_dnd_character(void)
{
    dnd_character_t tmp;

    tmp.strength = ability();
    tmp.dexterity = ability();
    tmp.constitution = ability();
    tmp.intelligence = ability();
    tmp.wisdom = ability();
    tmp.charisma = ability();
    tmp.hitpoints = modifier(tmp.constitution) + 10;

    return tmp;
}
