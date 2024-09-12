#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t res = 0;

  if (str1 != S21_NULL && str2 != S21_NULL) {
    int flag = 0;
    for (s21_size_t i = 0; i < s21_strlen(str1); ++i) {
      for (s21_size_t j = 0; j < s21_strlen(str2); ++j) {
        if (str1[i] == str2[j]) flag = 1;
      }
      if (!flag) {
        ++res;
      } else {
        i = s21_strlen(str1);
      }
    }
  }
  return res;
}