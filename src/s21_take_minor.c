#include "s21_matrix.h"
void s21_take_minor(int rows, int cols, matrix_t *A, matrix_t *result) {
  int row = 0;
  int col = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == rows) continue;
    col = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == cols) continue;
      result->matrix[row][col] = A->matrix[i][j];
      col++;
    }
    row++;
  }
}