#include "s21_decimal_tst.h"

void tests_func_s21(Suite *s);

int main() {
  Suite *array_test_cases[10];

  array_test_cases[0] = s21_suite_arith();
  array_test_cases[1] = suite_comp();
  array_test_cases[2] = suite_dtof();
  array_test_cases[3] = suite_dtoi();
  array_test_cases[4] = suite_ftod();
  array_test_cases[5] = suite_floor();
  array_test_cases[6] = suite_itod();
  array_test_cases[7] = suite_negate();
  array_test_cases[8] = suite_round();
  array_test_cases[9] = suite_trun();

  for (int i = 0; i < 10; i++) {
    tests_func_s21(array_test_cases[i]);
  }
  return 0;
}

void tests_func_s21(Suite *s) {
  SRunner *runner = srunner_create(s);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  srunner_free(runner);
}
