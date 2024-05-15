#include "s21_matrix.h"

int s21_matrix_not_null(matrix_t *A) {
  int result = 0;
  if (A != NULL && A->matrix != NULL && A->columns > 0 && A->rows > 0) {
    result = 1;
  }
  return result;
}