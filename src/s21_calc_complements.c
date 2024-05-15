#include "s21_matrix.h"
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = 0;
  double determinant = 0;
  matrix_t minor = {0};
  if (s21_matrix_not_null(A) && s21_matrix_not_null(A)) {
    if (A->rows == A->columns) {
      error = s21_create_matrix(A->columns, A->rows, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          error = s21_create_matrix(A->columns - 1, A->rows - 1, &minor);
          s21_take_minor(i, j, A, &minor);
          s21_determinant(&minor, &determinant);
          result->matrix[i][j] = pow(-1, (i + j)) * determinant;
          s21_remove_matrix(&minor);
        }
      }
    } else
      error = 2;
  } else {
    error = 1;
  }
  return error;
}