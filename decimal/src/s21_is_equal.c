#include "s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int is_equal = 1;
  if (s21_get_sign(value_1) == s21_get_sign(value_2)) {
    s21_equalize_exp(&value_1, &value_2);
    for (int i = 2; i >= 0; i--) {
      if (value_1.bits[i] != value_2.bits[i]) {
        is_equal = 0;
        i = 0;
      }
    }
  } else
    is_equal = 0;
  return is_equal;
}
