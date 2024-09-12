#include "s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int is_less = 0;
  uint8_t condition = s21_get_sign(value_1) * 2 + s21_get_sign(value_2);
  if (condition == 2) {
    is_less = 1;
  } else if (condition != 1) {
    s21_equalize_exp(&value_1, &value_2);
    for (int i = 2; i >= 0; i--) {
      if (value_1.bits[i] < value_2.bits[i] && condition == 0) is_less = 1;
      if (value_1.bits[i] > value_2.bits[i] && condition == 3) is_less = 1;
      if (value_1.bits[i] != value_2.bits[i]) i = 0;
    }
  }
  return is_less;
}
