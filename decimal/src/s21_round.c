#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  *result = value;
  char exp = s21_get_exp(*result);
  uint8_t rem = 0;
  while (exp > 0) {
    exp--;
    s21_mod_10(*result, &rem);
    s21_div_10(*result, result);
  }
  s21_set_exp(result, exp);
  if (rem >= 5) {
    s21_increment(*result, result);
  }
  return 0;
}