#include "s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
  if (src == S21_NULL || str == S21_NULL) return S21_NULL;

  const s21_size_t source_length = s21_strlen(src);
  const s21_size_t string_to_insert_length = s21_strlen(str);

  if (start_index > source_length) return S21_NULL;

  char *new_string =
      malloc(sizeof(char) * (source_length + string_to_insert_length + 1));

  for (s21_size_t index = 0; index < start_index; ++index)
    new_string[index] = src[index];

  for (s21_size_t index = 0; index < string_to_insert_length; ++index)
    new_string[index + start_index] = str[index];

  for (s21_size_t index = 0; index < source_length - start_index; ++index)
    new_string[index + start_index + string_to_insert_length] =
        src[index + start_index];

  new_string[source_length + string_to_insert_length] = '\0';

  return new_string;
}