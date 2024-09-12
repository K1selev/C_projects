#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *buff = (unsigned char *)str;
  if (str != S21_NULL) {
    for (s21_size_t i = 0; i < n; ++i) {
      buff[i] = c;
    }
  }
  return buff;
}