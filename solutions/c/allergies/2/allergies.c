#include "allergies.h"
bool is_allergic_to(allergen_t allergen, int num) {
  allergen_list_t allergens = get_allergens(num);
  if (allergens.allergens[allergen] == true) {
    return true;
  }
  return false;
}

allergen_list_t get_allergens(int num) {
  allergen_list_t list;
  list.count = 0;

  for (int i = 0; i < ALLERGEN_COUNT; i++) {
    list.allergens[i] = false;
  }

  num = num & 0xFF;

  for (int i = 0; i < ALLERGEN_COUNT; i++) {
    if (num & (1 << i)) {
      list.allergens[i] = true;
      list.count++;
    }
  }

  return list;
}
