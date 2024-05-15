#include "s21_matrix.h"
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  if (!s21_matrix_not_null(A) || !s21_matrix_not_null(B)) return 1;
  if (A->rows == B->rows && A->columns == B->columns) {
    error = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  } else
    error = 2;
  return error;
}