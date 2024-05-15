#include "s21_test_matrix.h"

START_TEST(complements_1) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 2, &m);
  if (!codec) {
    int code = s21_calc_complements(&m, &result);
    ck_assert_int_eq(code, 2);
    s21_remove_matrix(&m);
  }
}
END_TEST

START_TEST(complements_2) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_calc_complements(&m, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(complements_3) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(3, 4, &m);
  if (codec == 0) {
    int code = s21_calc_complements(&m, &result);
    ck_assert_int_eq(code, 2);
    s21_remove_matrix(&m);
  }
}
END_TEST

START_TEST(complements_4) {
  matrix_t expected = {0};
  matrix_t m = {0};
  matrix_t result = {0};
  int code1 = 0;
  code1 = s21_create_matrix(3, 3, &m);
  int code2 = 0;
  code2 = s21_create_matrix(3, 3, &expected);
  if (!code1 && !code2) {
    m.matrix[0][0] = 1;
    m.matrix[0][1] = 2;
    m.matrix[0][2] = 3;

    m.matrix[1][0] = 0;
    m.matrix[1][1] = 4;
    m.matrix[1][2] = 2;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = 2;
    m.matrix[2][2] = 1;

    expected.matrix[0][0] = 0;
    expected.matrix[0][1] = 10;
    expected.matrix[0][2] = -20;

    expected.matrix[1][0] = 4;
    expected.matrix[1][1] = -14;
    expected.matrix[1][2] = 8;

    expected.matrix[2][0] = -8;
    expected.matrix[2][1] = -2;
    expected.matrix[2][2] = 4;

    int code = s21_calc_complements(&m, &result);

    ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);
    ck_assert_int_eq(code, 0);
    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);
  }
}
END_TEST

START_TEST(complements_5) {
  int result = s21_calc_complements(NULL, NULL);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(complements_7) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(10, 9, &A);
  int res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

END_TEST
Suite *suite_calc_complements(void) {
  Suite *s = suite_create("suite_calc_complements");
  TCase *tc = tcase_create("case_calc_complements");

  tcase_add_test(tc, complements_1);
  tcase_add_test(tc, complements_2);
  tcase_add_test(tc, complements_3);
  tcase_add_test(tc, complements_4);
  tcase_add_test(tc, complements_5);
  tcase_add_test(tc, complements_7);

  suite_add_tcase(s, tc);
  return s;
}