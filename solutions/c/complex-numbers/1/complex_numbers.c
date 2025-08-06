#include "complex_numbers.h"
#include <math.h>

complex_t c_add(complex_t a, complex_t b) {
  complex_t result;
  result.imag = a.imag + b.imag;
  result.real = a.real + b.real;
  return result;
}

complex_t c_sub(complex_t a, complex_t b) {
  complex_t result;
  result.imag = a.imag - b.imag;
  result.real = a.real - b.real;
  return result;
}

complex_t c_mul(complex_t a, complex_t b) {
  // (a+bi)(c+di)=(ac−bd)+(ad+bc)i
  complex_t result;
  result.real = a.real * b.real - a.imag * b.imag;
  result.imag = a.real * b.imag + a.imag * b.real;
  return result;
}

complex_t c_div(complex_t a, complex_t b) {
  // (a+bi)(c-di)=(ac−bd)+(-ad+bc)i
  // (c + di)(c - di) = c^2 + d^2
  double denominator;
  complex_t result;

  result.real = a.real * b.real + a.imag * b.imag;
  result.imag = a.imag * b.real - a.real * b.imag;

  denominator = b.real * b.real + b.imag * b.imag;

  result.real /= denominator;
  result.imag /= denominator;
  return result;
}

double c_abs(complex_t x) { return sqrt(pow(x.real, 2) + pow(x.imag, 2)); }

complex_t c_conjugate(complex_t x) {
  complex_t result;
  result.real = x.real;
  result.imag = -x.imag;
  return result;
}

double c_real(complex_t x) { return x.real; }

double c_imag(complex_t x) { return x.imag; }

complex_t c_exp(complex_t x) {
  // e^a + bi = e^a⋅(cosb + isinb)
  complex_t result;
  result.real = exp(x.real) * cos(x.imag);
  result.imag = exp(x.real) * sin(x.imag);
  return result;
}
