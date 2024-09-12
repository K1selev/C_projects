#include "s21_string.h"

char *s21_strchr(const char *str, int sym) {
  char *result = S21_NULL;
  while ((*str != '\0') && (*str != sym)) {
    str++;
  }
  if (*str == sym) {
    result = (char *)str;
  }
  return result;
}