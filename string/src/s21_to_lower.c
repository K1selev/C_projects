#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *new_str = NULL;
  if (str != NULL) {
    int len = s21_strlen(str);
    new_str = malloc(sizeof(char) * (len + 1));
    if (new_str) {
      for (int i = 0; i <= len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          new_str[i] = (str[i] - 'A') + 'a';
        } else {
          new_str[i] = str[i];
        }
      }
      new_str[len] = '\0';
    }
  }
  return new_str;
}
