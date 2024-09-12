#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, size_t n) {
  int res = 0;
  for (size_t i = 0; i < n; i++) {
    if (((unsigned char *)str1)[i] == ((unsigned char *)str2)[i]) {
      continue;
    }
    res += (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
    break;
  }
  return res;
}