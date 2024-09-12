#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *res = S21_NULL;

  if (str != S21_NULL) {
    for (int i = (int)s21_strlen(str); i > -1; --i) {
      if (str[i] == c) {
        res = (char *)&str[i];
        i = -1;
      }
    }
  }
  return res;
}