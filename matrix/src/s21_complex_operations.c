#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int check = 0;
  if (result != NULL) {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  } else {
    check = 1;
  }
  return check;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int check = 0;
  if ((result != NULL) && (A->rows > 0) && (A->columns > 0)) {
    if (A->rows == A->columns) {
      s21_create_matrix(A->rows, A->columns, result);
      double det;
      matrix_t minor;
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
          s21_get_minor(A, &minor, i, j);
          s21_determinant(&minor, &det);
          result->matrix[i][j] = pow((-1), i + j) * det;
          s21_remove_matrix(&minor);
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

int s21_determinant(matrix_t *A, double *result) {
  int check = 0;
  if (result == NULL) {
    check = 1;
  } else if (A->rows == A->columns) {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else if (A->rows == 2) {
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    } else {
      int i = 0;
      double next_minor;
      matrix_t minor;
      *result = 0;
      s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
      for (int j = 0; j < A->columns; j++) {
        s21_get_minor(A, &minor, i, j);
        s21_determinant(&minor, &next_minor);
        *result += A->matrix[i][j] * pow((-1), i + j) * next_minor;
      }
      s21_remove_matrix(&minor);
    }
  } else {
    check = 2;
  }
  return check;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int check = 0;
  if (result == NULL) {
    check = 1;
  } else if (A->rows != A->columns) {
    check = 2;
  } else {
    if (A->rows == 1) {
      check = s21_create_matrix(A->rows, A->columns, result);
      if (!check) {
        result->matrix[0][0] = 1 / A->matrix[0][0];
      }
    } else {
      double det = 0.0;
      s21_determinant(A, &det);
      if (det) {
        matrix_t minor = {0};
        check = s21_calc_complements(A, &minor);
        if (!check) {
          matrix_t trans = {0};
          s21_transpose(&minor, &trans);
          s21_mult_number(&trans, 1 / det, result);
          s21_remove_matrix(&trans);
        }
        s21_remove_matrix(&minor);
      } else {
        check = 2;
      }
    }
  }
  return check;
}