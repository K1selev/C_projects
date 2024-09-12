#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = 0;
  uint8_t sign = s21_get_sign(value_1) ^ s21_get_sign(value_2);
  char exp = s21_get_exp(value_1) + s21_get_exp(value_2);
  value_1.bits[3] = 0;
  value_2.bits[3] = 0;
  if (s21_is_greater(value_1, value_2)) {
    *result = value_1;
    value_1 = value_2;
    value_2 = *result;
  }
  s21_nullify(result);
  uint8_t trans_bit = 0;
  while (!s21_is_null(value_1)) {
    for (uint8_t i = 0; i < 96; i++) {
      s21_set_bit(result, i,
                  s21_summer(s21_get_bit(*result, i), s21_get_bit(value_2, i),
                             &trans_bit));
    }
    if (trans_bit) {
      if (exp > 0) {
        s21_set_bit(result, 96, 1);
        exp--;
        uint8_t rem1, rem2;
        s21_mod_10(*result, &rem1);
        s21_div_10(*result, result);
        s21_mod_10(*result, &rem2);
        if (rem2 % 2) {
          if (rem1 >= 5)
            s21_increment(*result, result);
          else
            s21_decrement(*result, result);
        }
      } else {
        s21_nullify(&value_1);
        if (sign)
          status = 2;
        else
          status = 1;
      }
    }
    s21_decrement(value_1, &value_1);
  }
  while (exp > 28) {
    exp--;
    s21_div_10(*result, result);
  }
  s21_set_sign(result, sign);
  s21_set_exp(result, exp);
  return status;
}