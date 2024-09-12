#include "s21_string.h"

char *s21_itoa_er(long int num, char *str) {
  int sign = num;
  if (sign < 0) {
    num *= -1;
  }
  int flag = 1;
  s21_size_t i = 0;
  for (; flag; i++) {
    str[i] = num % 10 + 48;
    num /= 10;
    if (num == 0) {
      flag = 0;
    }
  }
  if (sign < 0) {
    str[i++] = '-';
  }
  str[i] = 0;
  char tmp;
  for (s21_size_t j = 0; j < (s21_strlen(str)) / 2; j++) {
    tmp = str[j];
    str[j] = str[s21_strlen(str) - 1 - j];
    str[s21_strlen(str) - 1 - j] = tmp;
  }
  return str;
}