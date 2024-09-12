#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  if (dest != S21_NULL && src != S21_NULL) {
    unsigned char *buff1 = (unsigned char *)dest;
    unsigned char *buff2 = (unsigned char *)src;
    if (dest < src) {
      for (s21_size_t i = 0; i < n; i++) {
        buff1[i] = buff2[i];
      }
    } else {
      for (s21_size_t i = n; i > 0; i--) {
        buff1[i - 1] = buff2[i - 1];
      }
    }
  }
  return dest;
}