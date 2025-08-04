#include "allergies.h"
bool is_allergic_to(allergen_t allergen, int num) {
  allergen_list_t allergens = get_allergens(num);
  if (allergens.allergens[allergen] == true) {
    return true;
  }
  return false;
}

allergen_list_t get_allergens(int num) {
  int count = 0;
  allergen_list_t list;

  list.count = 0;
  for (int i = 0; i < ALLERGEN_COUNT; i++) {
    list.allergens[i] = false;
  }

  num = num & 0xFF;

  if (num >= 128) {
    num -= 128;
    list.allergens[ALLERGEN_CATS] = true;
    count++;
  }
  if (num >= 64) {
    num -= 64;
    list.allergens[ALLERGEN_POLLEN] = true;
    count++;
  }
  if (num >= 32) {
    num -= 32;
    list.allergens[ALLERGEN_CHOCOLATE] = true;
    count++;
  }
  if (num >= 16) {
    num -= 16;
    list.allergens[ALLERGEN_TOMATOES] = true;
    count++;
  }
  if (num >= 8) {
    num -= 8;
    list.allergens[ALLERGEN_STRAWBERRIES] = true;
    count++;
  }
  if (num >= 4) {
    num -= 4;
    list.allergens[ALLERGEN_SHELLFISH] = true;
    count++;
  }
  if (num >= 2) {
    num -= 2;
    list.allergens[ALLERGEN_PEANUTS] = true;
    count++;
  }
  if (num >= 1) {
    num -= 1;
    list.allergens[ALLERGEN_EGGS] = true;
    count++;
  }
  list.count = count;
  return list;
}
