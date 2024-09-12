#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = 0;
  s21_equalize_exp(&value_1, &value_2);
  s21_nullify(result);
  result->bits[3] = value_1.bits[3];
  uint8_t value_1_sign = s21_get_sign(value_1),
          value_2_sign = s21_get_sign(value_2);
  if (value_1_sign != value_2_sign) {
    for (uint8_t i = 0; i < 3; i++) {
      if (value_1_sign)
        value_1.bits[i] = ~value_1.bits[i];
      else
        value_2.bits[i] = ~value_2.bits[i];
    }
    if (value_1_sign)
      s21_increment(value_1, &value_1);
    else
      s21_increment(value_2, &value_2);
  }
  uint8_t trans_bit = 0;
  for (uint8_t i = 0; i < 96; i++) {
    s21_set_bit(result, i,
                s21_summer(s21_get_bit(value_1, i), s21_get_bit(value_2, i),
                           &trans_bit));
  }

  if (value_1_sign != value_2_sign) {
    s21_set_sign(result, s21_summer(value_1_sign, value_2_sign, &trans_bit));
    if (s21_get_sign(*result)) {
      s21_decrement(*result, result);
      for (uint8_t i = 0; i < 3; i++) {
        result->bits[i] = ~result->bits[i];
      }
    }
  } else if (trans_bit) {
    char exp = s21_get_exp(*result);
    if (exp > 0) {
      s21_set_bit(result, 96, trans_bit);
      s21_set_exp(result, --exp);
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
      if (s21_get_sign(*result))
        status = 2;
      else
        status = 1;
    }
  }
  return status;
}