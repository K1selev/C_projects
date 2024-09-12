#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  for (s21_size_t index = 0; index < n; ++index)
    if (str1[index] != str2[index]) return str1[index] - str2[index];

  return 0;
}