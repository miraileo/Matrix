#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int error = SUCCESS;
  if (A->rows == B->rows && A->columns == B->columns &&
      s21_matrix_not_null(A) && s21_matrix_not_null(B)) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (round(A->matrix[i][j] * pow(10, 6)) !=
            round(B->matrix[i][j] * pow(10, 6))) {
          error = FAILURE;
          break;
        }
      }
    }
  } else
    error = FAILURE;
  return error;
}