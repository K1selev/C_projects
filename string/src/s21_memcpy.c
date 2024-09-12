#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  if (dest != S21_NULL && src != S21_NULL) {
    for (s21_size_t i = 0; i < n; i++) {
      ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
    }
  }
  return dest;
}