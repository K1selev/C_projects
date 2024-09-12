#include "s21_string.h"

char *s21_strcat(char *destination, const char *source) {
  int length = 0;
  int length2 = 0;

  for (; *(destination + length); length++) {
  }
  for (; *(source + length2); length2++) {
  }

  for (int i = 0; i < length2; i++) {
    destination[length + i] = source[i];
  }
  return destination;
}