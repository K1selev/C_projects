#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = 1;
  int sign_value_1 = s21_get_sign(value_1);
  int sign_value_2 = s21_get_sign(value_2);
  s21_nullify(result);
  if (sign_value_1 != sign_value_2) s21_set_sign(result, 1);
  if (!s21_is_null(value_2))
    status = 0;
  else {
    int value_1_int = 0;
    int value_2_int = 0;
    s21_from_decimal_to_int(value_1, &value_1_int);
    s21_from_decimal_to_int(value_2, &value_2_int);
    int res = value_1_int / value_2_int;
    s21_from_int_to_decimal(res, result);
  }
  return status;
}
