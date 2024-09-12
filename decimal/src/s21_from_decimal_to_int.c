#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = 0;
  s21_truncate(src, &src);
  uint32_t sign = s21_get_sign(src);
  if (src.bits[2] == 0 && src.bits[1] == 0 && src.bits[0] <= INT_MAX + sign) {
    if (sign) {
      src.bits[0] = ~src.bits[0];
      src.bits[0]++;
    }
    *dst = src.bits[0];
  } else {
    error = 1;
  }
  return error;
}
