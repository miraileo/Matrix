#include "s21_matrix.h"
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = 0;
  double determinant = 0;
  matrix_t tmp1 = {0};
  matrix_t tmp = {0};
  if (!s21_matrix_not_null(A)) return 1;
  s21_determinant(A, &determinant);
  if (A->rows == 1) {
    error = s21_create_matrix(A->rows, A->rows, result);
    if (!error) {
      if (determinant != 0)
        result->matrix[0][0] = 1 / A->matrix[0][0];
      else
        error = 2;
    }
    return error;
  }
  if (determinant != 0) {
    error = s21_calc_complements(A, &tmp);
    if (!error) {
      error = s21_transpose(&tmp, &tmp1);
      if (!error) {
        s21_mult_number(&tmp1, 1 / determinant, result);
      }
      s21_remove_matrix(&tmp1);
    }
    s21_remove_matrix(&tmp);
  } else {
    error = 2;
  }
  return error;
}