#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *buff = (unsigned char *)str;
  unsigned char *res = S21_NULL;
  for (s21_size_t i = 0; i < n; i++) {
    if (buff[i] == c) {
      res = &buff[i];
      i = i + n;
    }
  }
  return res;
}