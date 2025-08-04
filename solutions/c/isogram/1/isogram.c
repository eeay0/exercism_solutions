#include "isogram.h"
#include <ctype.h>
#include <string.h>
bool is_isogram(const char phrase[]) {
  if (phrase == NULL) {
    return false;
  }
  int len = strlen(phrase);
  for (int i = 0; i < len; i++) {
    if (isalpha(phrase[i])) {
      for (int y = 0; y < len; y++) {
        if (i == y) {
          continue;
        }
        if (tolower(phrase[i]) == tolower(phrase[y])) {
          return false;
        }
      }
    }
  }
  return true;
}
