#include "s21_string.h"

char *s21_strcpy(char *destination, const char *source) {
  int length = 0;
  destination[0] = '\0';
  for (; (((s21_size_t)length < s21_strlen(source)) &&
          ((source[length] != '\0')));
       length++) {
  }
  for (int i = 0; i < length; i++) {
    destination[i] = source[i];
    destination[i + 1] = '\0';
  }
  return destination;
}
