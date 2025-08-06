#include "sieve.h"
#include <stdbool.h>
#include <stdint.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
  if (limit < 2) {
    return 0;
  }

  bool is_prime[limit + 1];
  for (uint32_t i = 2; i <= limit; i++) {
    is_prime[i] = true;
  }

  for (uint32_t p = 2; p * p <= limit; p++) {
    if (is_prime[p]) {
      for (uint32_t multiple = p + p; multiple <= limit; multiple += p) {
        is_prime[multiple] = false;
      }
    }
  }

  uint32_t count = 0;
  for (uint32_t p = 2; p <= limit; p++) {
    if (is_prime[p] && count < max_primes) {
      primes[count++] = p;
    }
  }
  return count;
}
