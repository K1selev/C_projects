#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  if (s21_get_exp(value) != 0) {
    s21_truncate(value, result);
    if (s21_get_sign(*result)) s21_increment(*result, result);
  }
  return 0;
}
