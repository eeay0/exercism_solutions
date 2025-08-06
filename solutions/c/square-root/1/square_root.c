#include "square_root.h"
#include <stdint.h>
uint16_t improve_guess(uint16_t guess, uint16_t num) {
  return (guess + num / guess) / 2;
}
uint16_t square_root(uint16_t num) {
  if (num == 0 || num == 1) {
    return num;
  }

  uint16_t guess_prev = num / 2;

  if (guess_prev == 0) {
    guess_prev = 1;
  }
  uint16_t guess = improve_guess(guess_prev, num);

  while (guess != guess_prev) {
    guess_prev = guess;
    guess = improve_guess(guess_prev, num);
  }
  return guess;
}
