#include "rotational_cipher.h"
#include <stdlib.h>
#include <string.h>
char *rotate(const char *text, int shift_key) {
  char base;
  int len = strlen(text);
  char *cipher = malloc(len + 1);

  int new_pos;

  for (int i = 0; i < len; i++) {

    if ('a' <= text[i] && text[i] <= 'z') {
      base = 'a';
    } else if ('A' <= text[i] && text[i] <= 'Z') {
      base = 'A';
    } else {
      cipher[i] = text[i];
      continue;
    }
    new_pos = (((text[i] - base + shift_key) % 26) + 26) % 26;
    cipher[i] = base + new_pos;
  }
  cipher[len] = '\0';
  return cipher;
}
