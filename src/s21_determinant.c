#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  double res = 0;
  int error = 0;
  int sign = 1;
  matrix_t tmp = {0};
  if (s21_matrix_not_null(A) && result != NULL) {
    *result = 0;
    if (A->rows <= 0) error = 1;
    if (A->rows == A->columns) {
      if (A->rows == 1)
        *result = A->matrix[0][0];
      else {
        s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
        for (int i = 0; i < A->columns; i++) {
          s21_take_minor(0, i, A, &tmp);
          s21_determinant(&tmp, &res);
          *result += sign * (A->matrix[0][i] * res);
          sign *= -1;
        }
        s21_remove_matrix(&tmp);
      }
    } else
      error = 2;
  } else {
    error = 1;
  }
  return error;
}