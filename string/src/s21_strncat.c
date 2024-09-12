#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t length = s21_strlen(dest);
  s21_size_t length2 = s21_strlen(src);
  const s21_size_t size = n < length2 ? n : length2;
  for (s21_size_t i = 0; i < size; i++) {
    dest[length + i] = src[i];
  }
  return dest;
}