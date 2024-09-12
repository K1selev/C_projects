#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <limits.h>
#include <math.h>
#include <stdio.h>

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;

typedef struct {
  uint32_t bits[4];
} s21_decimal;

typedef union {
  float number;
  uint32_t bits;
} s21_float;

void print(s21_decimal value);

uint8_t s21_get_bit(s21_decimal value, uint8_t bit_pos);
s21_decimal *s21_set_bit(s21_decimal *value, uint8_t bit_pos, uint8_t bit_val);
char s21_get_exp(s21_decimal value);
s21_decimal *s21_set_exp(s21_decimal *value, char exp);
uint8_t s21_get_sign(s21_decimal value);
s21_decimal *s21_set_sign(s21_decimal *value, uint8_t sign);
s21_decimal *s21_nullify(s21_decimal *value);
int s21_is_null(s21_decimal value);
uint8_t s21_summer(uint8_t bit_1, uint8_t bit_2, uint8_t *trans_bit);
int s21_mul_10(s21_decimal value, s21_decimal *result);
void s21_div_10(s21_decimal value, s21_decimal *result);
void s21_mod_10(s21_decimal value, uint8_t *result);
void s21_increment(s21_decimal value, s21_decimal *result);
void s21_decrement(s21_decimal value, s21_decimal *result);
s21_decimal *s21_reduce(s21_decimal *value);
void s21_equalize_exp(s21_decimal *value_1, s21_decimal *value_2);
int s21_get_float_exp(float *value);

int s21_add(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // +
int s21_sub(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // +
int s21_mul(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // +
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// s21_is_less и s21_is_equal - базовые функции
int s21_is_less(s21_decimal value_1, s21_decimal value_2);              // +
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);     // +
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);           // +
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);  // +
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);             // +
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);         // +

int s21_from_int_to_decimal(int src, s21_decimal *dst);  // +
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);  // +
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// другие функции
int s21_floor(s21_decimal value, s21_decimal *result);     // +
int s21_round(s21_decimal value, s21_decimal *result);     // +
int s21_truncate(s21_decimal value, s21_decimal *result);  // +
int s21_negate(s21_decimal value, s21_decimal *result);    // +

#endif
