#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int check = s21_check_size_of_matrices(A, B);
  if (!check) {
    check = 1;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs((A->matrix)[i][j] - (B->matrix)[i][j]) < 1e-7) {
          check = 1;
        } else {
          check = 0;
        }
      }
    }
  } else {
    check = 0;
  }
  return check;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int check = s21_check_size_of_matrices(A, B);
  if (!check && (result != NULL)) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  } else if (result == NULL) {
    check = 1;
  }
  return check;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int check = s21_check_size_of_matrices(A, B);
  if (!check && (result != NULL)) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  } else if (result == NULL) {
    check = 1;
  }
  return check;
}
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int check = 0;
  if (result == NULL) {
    check = 1;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return check;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int check = 0;
  if (result != NULL) {
    if (A->columns == B->rows) {
      s21_create_matrix(A->rows, B->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          for (int k = 0; k < A->columns; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    } else {
      check = 2;
    }
  } else {
    check = 1;
  }
  return check;
}
