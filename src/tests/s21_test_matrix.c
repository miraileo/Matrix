#include "s21_test_matrix.h"
int main(void) {
  int failed = 0;
  Suite *s21_matrix[] = {suite_calc_complements(),
                         suite_create_matrix(),
                         suite_eq_matrix(),
                         suite_sum_matrix(),
                         suite_sub_matrix(),
                         suite_mult_number_matrix(),
                         suite_mult_matrix(),
                         suite_transpose_matrix(),
                         suite_determinant(),
                         suite_inverse_matrix(),
                         NULL};

  for (int i = 0; s21_matrix[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_matrix[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return 0;
}

double get_rand(double min, double max) {
  double val = (double)rand() / RAND_MAX;
  return min + val * (max - min);
}