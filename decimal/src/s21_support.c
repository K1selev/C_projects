#include "s21_decimal.h"

uint8_t s21_get_bit(s21_decimal value, uint8_t bit_pos) {
  uint8_t num_ind = bit_pos / 32u;
  uint8_t bit_ind = bit_pos % 32u;
  return (value.bits[num_ind] & (1u << bit_ind)) >> bit_ind;
}

s21_decimal *s21_set_bit(s21_decimal *value, uint8_t bit_pos, uint8_t bit_val) {
  uint8_t num_ind = bit_pos / 32u;
  uint8_t bit_ind = bit_pos % 32u;
  value->bits[num_ind] = bit_val ? value->bits[num_ind] | (1u << bit_ind)
                                 : value->bits[num_ind] & ~(1u << bit_ind);
  return value;
}

char s21_get_exp(s21_decimal value) {
  return (char)(value.bits[3] >> 16 & 0xFF);
}

s21_decimal *s21_set_exp(s21_decimal *value, char exp) {
  value->bits[3] &= 1u << 31;
  value->bits[3] |= (exp & 0xFF) << 16;
  return value;
}

uint8_t s21_get_sign(s21_decimal value) { return s21_get_bit(value, 127); }
s21_decimal *s21_set_sign(s21_decimal *value, uint8_t sign) {
  return s21_set_bit(value, 127, sign);
}

s21_decimal *s21_nullify(s21_decimal *value) {
  for (uint8_t i = 0; i < 4; i++) {
    value->bits[i] = 0;
  }
  return value;
}

int s21_is_null(s21_decimal value) {
  int flag = 1;
  for (uint8_t i = 0; i < 3 && flag; i++) {
    if (value.bits[i] != 0) {
      flag = 0;
    }
  }
  return flag;
}

uint8_t s21_summer(uint8_t bit_1, uint8_t bit_2, uint8_t *trans_bit) {
  uint8_t tmp_bit = *trans_bit;
  *trans_bit = (bit_1 & bit_2) ^ (bit_1 & tmp_bit) ^ (bit_2 & tmp_bit);
  return bit_1 ^ bit_2 ^ tmp_bit;
}

int s21_mul_10(s21_decimal value, s21_decimal *result) {
  int error = 0;
  *result = value;
  for (uint8_t i = 0; i < 3; i++) {
    result->bits[i] = 0;
  }
  for (uint8_t shift = 1; shift <= 3 && !error; shift += 2) {
    uint8_t trans_bit = 0;
    for (uint8_t i = 0; i < 96 - shift; i++) {
      s21_set_bit(result, i + shift,
                  s21_summer(s21_get_bit(value, i),
                             s21_get_bit(*result, i + shift), &trans_bit));
    }
    if (trans_bit) error = 1;
  }
  if (error) {
    *result = value;
  }
  return error;
}

void s21_div_10(s21_decimal value, s21_decimal *result) {
  *result = value;
  uint8_t remainder = 0;
  for (char i = 96; i >= 0; i--) {
    uint8_t bit = s21_get_bit(*result, i);
    uint8_t quotient = (remainder * 2 + bit) / 10;
    remainder = (remainder * 2 + bit) % 10;
    s21_set_bit(result, i, quotient);
  }
}

void s21_mod_10(s21_decimal value, uint8_t *result) {
  *result = 0;
  for (char i = 96; i >= 0; i--) {
    uint8_t bit = s21_get_bit(value, i);
    uint8_t quotient = ((*result) * 2 + bit) / 10;
    *result = ((*result) * 2 + bit) % 10;
    s21_set_bit(&value, i, quotient);
  }
}

void s21_increment(s21_decimal value, s21_decimal *result) {
  *result = value;
  uint8_t trans_bit = 1;
  for (uint8_t i = 0; i < 96; i++) {
    s21_set_bit(result, i, s21_summer(s21_get_bit(*result, i), 0, &trans_bit));
  }
}

void s21_decrement(s21_decimal value, s21_decimal *result) {
  *result = value;
  for (uint8_t i = 0; i < 96; i++) {
    if (s21_get_bit(*result, i)) {
      s21_set_bit(result, i, 0);
      i = 95;
    } else
      s21_set_bit(result, i, 1);
  }
}

s21_decimal *s21_reduce(s21_decimal *value) {
  uint8_t remainder;
  char exp = s21_get_exp(*value);
  s21_mod_10(*value, &remainder);
  while (exp > 0 && remainder == 0) {
    exp--;
    s21_div_10(*value, value);
    s21_mod_10(*value, &remainder);
  }
  if (value->bits[2] == 0 && value->bits[1] == 0 && value->bits[0] == 0) {
    value->bits[3] = 0;
  }
  s21_set_exp(value, exp);
  return value;
}

void s21_equalize_exp(s21_decimal *value_1, s21_decimal *value_2) {
  // отсутствует банковское округление
  s21_reduce(value_1);
  s21_reduce(value_2);
  char value_1_exp = s21_get_exp(*value_1);
  char value_2_exp = s21_get_exp(*value_2);
  int error = 0;
  while (value_1_exp != value_2_exp) {
    if (value_1_exp > value_2_exp) {
      if (error) {
        s21_div_10(*value_1, value_1);
        value_1_exp--;
      } else {
        error = s21_mul_10(*value_2, value_2);
        if (!error) value_2_exp++;
      }
    } else {
      if (error) {
        s21_div_10(*value_2, value_2);
        value_2_exp--;
      } else {
        error = s21_mul_10(*value_1, value_1);
        if (!error) value_1_exp++;
      }
    }
  }
  s21_set_exp(value_1, value_1_exp);
  s21_set_exp(value_2, value_2_exp);
}

void print(s21_decimal value) {
  for (char i = 3; i >= 0; i--) {
    printf("bits[%d]: ", i);
    for (char j = 31; j >= 0; j--) {
      printf("%u", s21_get_bit(value, i * 32 + j));
    }
    putchar('\n');
  }
}

int s21_get_float_exp(float *value) {
  return ((*((int *)value) & ~(1u << 31)) >> 23) - 127;
}