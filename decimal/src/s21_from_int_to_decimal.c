#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  s21_nullify(dst);
  uint32_t bits = src;
  uint8_t sign = 0;
  if (src < 0) {
    sign = 1;
    bits--;
    bits = ~bits;
  }
  s21_set_sign(dst, sign);
  dst->bits[0] = bits;
  return 0;
}