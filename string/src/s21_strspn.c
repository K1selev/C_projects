#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  for (const char *p = str1; *p != '\0'; p++) {
    const char *a = str2;
    for (a = str2; *a != '\0'; a++)
      if (*p == *a) break;
    if (*a == '\0')
      break;
    else
      count++;
  }
  return count;
}