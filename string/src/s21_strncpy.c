#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, size_t n) {
  s21_size_t length = 0;
  dest[0] = '\0';
  for (; length < s21_strlen(src); length++) {
  }
  for (s21_size_t i = 0; ((i < length) && (i < n)); i++) {
    dest[i] = src[i];
    if (n > length) dest[i + 1] = '\0';
  }
  return dest;
}