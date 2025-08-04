#include "luhn.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool luhn(const char *num) {
  int len = strlen(num);

  unsigned char *tmp_num = malloc(len + 2);
  if (!tmp_num)
    return false;

  int y = 0;
  for (int i = 0; i < len; i++) {
    if (num[i] == ' ') {
      continue;
    } else if (!isdigit((unsigned char)num[i])) {
      free(tmp_num);
      return false;
    } else {
      tmp_num[y++] = num[i] - '0';
    }
  }
  len = y;

  if (len < 2) {
    free(tmp_num);
    return false;
  }
  int sum = 0;

  for (int i = len - 2; i >= 0; i -= 2) {
    if (tmp_num[i] * 2 > 9) {
      tmp_num[i] = (tmp_num[i] * 2) - 9;
    } else {
      tmp_num[i] = (tmp_num[i] * 2);
    }
  }

  for (int i = 0; i < len; i++) {
    sum += tmp_num[i];
  }

  if (sum % 10 == 0) {
    free(tmp_num);
    return true;
  }

  free(tmp_num);
  return false;
}
