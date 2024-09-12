#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int check = 0;
  if ((result != NULL) && (rows > 0) && (columns > 0)) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)malloc(columns * sizeof(double));
    }
  } else {
    check = 1;
  }
  return check;
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
  }
}

int s21_check_size_of_matrices(matrix_t *A, matrix_t *B) {
  int res = 0;
  if ((A->rows != B->rows) || (A->columns != B->columns)) {
    res = 2;
  }
  return res;
}

void s21_get_minor(matrix_t *A, matrix_t *result, int x, int y) {
  int k = 0;
  for (int i = 0; i < result->rows; i++) {
    if (i == x) {
      k = 1;
    }
    int m = 0;
    for (int j = 0; j < result->rows; j++) {
      if (j == y) {
        m = 1;
      }
      result->matrix[i][j] = A->matrix[i + k][j + m];
    }
  }
}