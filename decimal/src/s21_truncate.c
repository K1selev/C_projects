#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  *result = value;
  char exp = s21_get_exp(*result);
  while (exp > 0) {
    exp--;
    s21_div_10(*result, result);
  }
  s21_set_exp(result, exp);
  return 0;
}