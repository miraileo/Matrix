#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = 0;
  if (rows <= 0 || columns <= 0) {
    error = 1;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
  }
  if (result->matrix == NULL) {
    error = 1;
  } else {
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
      if (result->matrix[i] == NULL) {
        error = 1;
        for (int j = 0; j < i; j++) {
          free(result->matrix[j]);
        }
      }
    }
  }
  return error;
}