#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  int flag = 0;
  while (*str1 != '\0' && flag != 1) {
    const char *a = str2;
    while (*a != '\0' && flag != 1)
      if (*a++ == *str1) flag = 1;
    if (flag != 1) str1++;
  }
  return (flag != 1) ? S21_NULL : (char *)str1;
}