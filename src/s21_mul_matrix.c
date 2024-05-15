#include "s21_matrix.h"
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  if (!s21_matrix_not_null(A) || !s21_matrix_not_null(B)) return 1;
  if ((A->columns == B->rows)) {
    error = s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int a = 0; a < B->rows; a++) {
          result->matrix[i][j] += A->matrix[i][a] * B->matrix[a][j];
        }
      }
    }
  } else {
    error = 2;
  }

  return error;
}