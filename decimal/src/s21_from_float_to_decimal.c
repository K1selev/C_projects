#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int res = 1, exp = s21_get_float_exp(&src);
  s21_nullify(dst);
  if (src != 0 && !isinf(src)) {
    int sign = 0;
    if (src < 0) {
      src *= -1;
      sign = 1;
    }
    double tmp = (double)src;
    int scale = 0;
    while (scale < 28 && (int)tmp / (int)pow(2, 21) == 0) {
      tmp *= 10;
      scale++;
    }
    if (scale <= 28 && (exp > -94 && exp < 96)) {
      s21_float mant;
      tmp = (float)tmp;
      for (; fmod(tmp, 10) == 0 && scale > 0; scale--, tmp /= 10) {
      }
      mant.number = tmp;
      exp = s21_get_float_exp(&mant.number);
      s21_set_bit(dst, exp, 1);
      for (int i = exp - 1, j = 22; j >= 0; i--, j--) {
        if ((mant.bits & (1 << j)) != 0) {
          s21_set_bit(dst, i, 1);
        }
      }
      s21_set_sign(dst, sign);
      s21_set_exp(dst, scale);
      res = 0;
    }
  }
  return res;
}