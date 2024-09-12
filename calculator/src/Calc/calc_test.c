#include "calculate.h"
#include "check.h"
#include "credit_calc.h"
#include "parse_string.h"
#include "s21_helper.h"
#include "stack.h"
#include "stdlib.h"

START_TEST(create_stack_fn) {
  struct Node *stack = NULL;
  push_back(&stack, 1, '+');
  ck_assert_int_eq(stack->prior, 1);
  ck_assert_int_eq(stack->symb, 43);
  ck_assert_ptr_null(stack->next);
}
END_TEST

START_TEST(check_stack_fn) {
  struct Node *stack = NULL;
  push_back(&stack, 1, '+');
  int status = check_stack(stack);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(check_stack_1_fn) {
  struct Node *stack = NULL;
  int status = check_stack(stack);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(pop_prior_stack_fn) {
  struct Node *stack = NULL;
  push_back(&stack, 1, '+');
  int prior;
  pop_prior(stack, &prior);
  ck_assert_int_eq(prior, 1);
}
END_TEST

START_TEST(pop_back_stack_fn) {
  struct Node *stack = NULL;
  push_back(&stack, 1, '+');
  int prior;
  char symb;
  pop_back(&stack, &prior, &symb);
  ck_assert_int_eq(prior, 1);
  ck_assert_int_eq(symb, 43);
}
END_TEST

START_TEST(add_stack_fn) {
  char data[256] = "-2+sin(x)*(+(-2)*2)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  ck_assert_str_eq(notation, "0 2 - x s 0 0 2 - 2 * + * + ");
  ck_assert_int_eq(status, OK);
  free(notation);
}
END_TEST

START_TEST(add_stack_2_fn) {
  char data[256] = "-2+sin(x)*(+(-2)*2)^2";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  ck_assert_str_eq(notation, "0 2 - x s 0 0 2 - 2 * + 2 ^ * + ");
  ck_assert_int_eq(status, OK);
  free(notation);
}
END_TEST

START_TEST(add_stack_3_fn) {
  char data[256] = "-2+sin(x)*(+(-2)*2)^2)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  ck_assert_int_eq(status, ERR);
  free(notation);
}
END_TEST

START_TEST(add_stack_4_fn) {
  char data[256] = "())-2+sin(x)*(+(-2)*2)^2)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  ck_assert_int_eq(status, ERR);
  free(notation);
}
END_TEST

START_TEST(add_stack_5_fn) {
  char data[256] = "(0.2.2))-2+sin(x)*(+(-2)*2)^2)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  ck_assert_int_eq(status, ERR);
  free(notation);
}
END_TEST

START_TEST(add_stack_6_fn) {
  char data[256] = "-2+cos(x)*(+(-2)*2)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  ck_assert_str_eq(notation, "0 2 - x c 0 0 2 - 2 * + * + ");
  ck_assert_int_eq(status, OK);
  free(notation);
}
END_TEST

START_TEST(add_stack_7_fn) {
  char data[256] = "-2+acos(x)*(+(-2)*2)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  ck_assert_str_eq(notation, "0 2 - x C 0 0 2 - 2 * + * + ");
  ck_assert_int_eq(status, OK);
  free(notation);
}
END_TEST

START_TEST(add_stack_8_fn) {
  char data[256] = "-2+asin(x)*(+(-2)*2)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  ck_assert_str_eq(notation, "0 2 - x S 0 0 2 - 2 * + * + ");
  ck_assert_int_eq(status, OK);
  free(notation);
}
END_TEST

START_TEST(add_stack_9_fn) {
  char data[256] = "-2+atan(x)*(+(-2)*2)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  ck_assert_str_eq(notation, "0 2 - x T 0 0 2 - 2 * + * + ");
  ck_assert_int_eq(status, OK);
  free(notation);
}
END_TEST

START_TEST(add_stack_10_fn) {
  char data[256] = "-2+tan(x)*(+(-2)*2)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  ck_assert_str_eq(notation, "0 2 - x t 0 0 2 - 2 * + * + ");
  ck_assert_int_eq(status, OK);
  free(notation);
}
END_TEST

START_TEST(add_stack_11_fn) {
  char data[256] = "-2+sqrt(x)*(+(-2)*2)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  ck_assert_str_eq(notation, "0 2 - x q 0 0 2 - 2 * + * + ");
  ck_assert_int_eq(status, OK);
  free(notation);
}
END_TEST

START_TEST(add_stack_12_fn) {
  char data[256] = "-2+ln(x)*(+(-2)*2)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  ck_assert_str_eq(notation, "0 2 - x l 0 0 2 - 2 * + * + ");
  ck_assert_int_eq(status, OK);
  free(notation);
}
END_TEST

START_TEST(add_stack_13_fn) {
  char data[256] = "-2+log(x)*(+(-2)*2)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  ck_assert_str_eq(notation, "0 2 - x L 0 0 2 - 2 * + * + ");
  ck_assert_int_eq(status, OK);
  free(notation);
}
END_TEST

START_TEST(calculate_fn) {
  char data[256] = "-2+log(x)*(+(-2)*2)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  double x = 1.0;
  double ans = calculate(notation, x);
  ck_assert_str_eq(notation, "0 2 - x L 0 0 2 - 2 * + * + ");
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq(ans, -2);
  free(notation);
}
END_TEST

START_TEST(calculate_1_fn) {
  char data[256] = "sin(x) + cos(x) + log(x)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  double x = 1.0;
  double ans = calculate(notation, x);
  ck_assert_double_eq_tol(ans, 1.381773, 7);
  ck_assert_int_eq(status, ERR);
  free(notation);
}
END_TEST

START_TEST(calculate_2_fn) {
  char data[256] = "sin(2.5) + cos(0.1) + log(1)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  double x = 1.0;
  double ans = calculate(notation, x);
  ck_assert_double_eq_tol(ans, 1.593476, 7);
  ck_assert_int_eq(status, ERR);
  free(notation);
}
END_TEST

START_TEST(calculate_3_fn) {
  char data[256] = "2.5%2 + 0.1^1 + tan(1.1)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  double x = 1.0;
  double ans = calculate(notation, x);
  ck_assert_double_eq_tol(ans, 2.56476, 7);
  ck_assert_int_eq(status, ERR);
  free(notation);
}
END_TEST

START_TEST(calculate_4_fn) {
  char data[256] = "ln(1.1) + sqrt(2.5)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  double x = 1.0;
  double ans = calculate(notation, x);
  ck_assert_double_eq_tol(ans, 1.676449, 7);
  ck_assert_int_eq(status, ERR);
  free(notation);
}
END_TEST

START_TEST(calculate_5_fn) {
  char data[256] = "ln(1.1) / sqrt(2.5)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  double x = 1.0;
  double ans = calculate(notation, x);
  ck_assert_double_eq_tol(ans, 0.06027945, 7);
  ck_assert_int_eq(status, ERR);
  free(notation);
}
END_TEST

START_TEST(calculate_6_fn) {
  char data[256] = "1/2^2+sin(2.45)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  double x = 1.0;
  double ans = calculate(notation, x);
  ck_assert_double_eq_tol(ans, 0.8877647, 7);
  ck_assert_int_eq(status, OK);
  free(notation);
}
END_TEST

START_TEST(calculate_7_fn) {
  char data[256] = "acos(1)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  double x = 1.0;
  double ans = calculate(notation, x);
  ck_assert_double_eq_tol(ans, 0, 7);
  ck_assert_int_eq(status, OK);
  free(notation);
}
END_TEST

START_TEST(calculate_8_fn) {
  char data[256] = "asin(1)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  double x = 1.0;
  double ans = calculate(notation, x);
  ck_assert_double_eq_tol(ans, 1.570796, 7);
  ck_assert_int_eq(status, OK);
  free(notation);
}
END_TEST

START_TEST(calculate_9_fn) {
  char data[256] = "cos(1)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  double x = 1.0;
  double ans = calculate(notation, x);
  ck_assert_double_eq_tol(ans, 0.5403023, 7);
  ck_assert_int_eq(status, OK);
  free(notation);
}
END_TEST

START_TEST(calculate_10_fn) {
  char data[256] = "tan(1.1)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  double x = 1.0;
  double ans = calculate(notation, x);
  ck_assert_double_eq_tol(ans, 1.96476, 7);
  ck_assert_int_eq(status, OK);
  free(notation);
}
END_TEST

START_TEST(calculate_11_fn) {
  char data[256] = "1.0/2.45";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  double x = 1.0;
  double ans = calculate(notation, x);
  ck_assert_double_eq_tol(ans, 0.4081633, 7);
  ck_assert_int_eq(status, OK);
  free(notation);
}
END_TEST

START_TEST(calculate_12_fn) {
  char data[256] = "1.0%2.45";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  double x = 1.0;
  double ans = calculate(notation, x);
  ck_assert_double_eq_tol(ans, 1, 7);
  ck_assert_int_eq(status, OK);
  free(notation);
}
END_TEST

START_TEST(calculate_13_fn) {
  char data[256] = "atan(1.2)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  double x = 1.0;
  double ans = calculate(notation, x);
  ck_assert_double_eq_tol(ans, 0.8760581, 7);
  ck_assert_int_eq(status, OK);
  free(notation);
}
END_TEST

START_TEST(calculate_14_fn) {
  char data[256] = "ln(1.2)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  double x = 1.0;
  double ans = calculate(notation, x);
  ck_assert_double_eq_tol(ans, 0.1823216, 7);
  ck_assert_int_eq(status, OK);
  free(notation);
}
END_TEST

START_TEST(calculate_15_fn) {
  char data[256] = "sqrt(1.2)";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  double x = 1.0;
  double ans = calculate(notation, x);
  ck_assert_double_eq_tol(ans, 1.095445, 7);
  ck_assert_int_eq(status, OK);
  free(notation);
}
END_TEST

START_TEST(credit_calculate_fn) {
  double tel_cred = 10000, proc_cred = 13.3;
  int month = 5;
  double anuitet = calculate_annuitet(tel_cred, proc_cred, month);
  double percent = annuitet_percent(tel_cred, proc_cred, month);
  double anu_sum = annuitet_dolg_proc(tel_cred, proc_cred, month);
  ck_assert_double_eq_tol(anuitet, 2066.99, 7);
  ck_assert_double_eq_tol(percent, 334.95, 7);
  ck_assert_double_eq_tol(anu_sum, 10334.95, 7);
}
END_TEST

START_TEST(credit_calculate_1_fn) {
  double tel_cred = 10000, proc_cred = 13.3;
  int month = 5;
  double dif_min = dif_month_min(tel_cred, proc_cred, month);
  double dif_max = dif_month_max(tel_cred, proc_cred, month);
  double dif_pere = dif_pereplat(tel_cred, proc_cred, month);
  double dif_tot = dif_total(tel_cred, proc_cred, month);
  ck_assert_double_eq_tol(dif_min, 2110.83, 7);
  ck_assert_double_eq_tol(dif_max, 2022.17, 7);
  ck_assert_double_eq_tol(dif_pere, 332.50, 7);
  ck_assert_double_eq_tol(dif_tot, 10332.50, 7);
}
END_TEST

Suite *calc_suit(void) {
  Suite *s;
  s = suite_create("Caclulator functions");

  TCase *tc_create = tcase_create("work with stack");
  suite_add_tcase(s, tc_create);
  tcase_add_test(tc_create, create_stack_fn);
  tcase_add_test(tc_create, check_stack_fn);
  tcase_add_test(tc_create, check_stack_1_fn);
  tcase_add_test(tc_create, pop_prior_stack_fn);
  tcase_add_test(tc_create, pop_back_stack_fn);

  TCase *tc_parse_string = tcase_create("parsing string");
  suite_add_tcase(s, tc_parse_string);
  tcase_add_test(tc_parse_string, add_stack_fn);
  tcase_add_test(tc_parse_string, add_stack_2_fn);
  tcase_add_test(tc_parse_string, add_stack_3_fn);
  tcase_add_test(tc_parse_string, add_stack_4_fn);
  tcase_add_test(tc_parse_string, add_stack_5_fn);
  tcase_add_test(tc_parse_string, add_stack_6_fn);
  tcase_add_test(tc_parse_string, add_stack_7_fn);
  tcase_add_test(tc_parse_string, add_stack_8_fn);
  tcase_add_test(tc_parse_string, add_stack_9_fn);
  tcase_add_test(tc_parse_string, add_stack_10_fn);
  tcase_add_test(tc_parse_string, add_stack_11_fn);
  tcase_add_test(tc_parse_string, add_stack_12_fn);
  tcase_add_test(tc_parse_string, add_stack_13_fn);

  TCase *tc_calculate = tcase_create("calculate");
  suite_add_tcase(s, tc_calculate);
  tcase_add_test(tc_calculate, calculate_fn);
  tcase_add_test(tc_calculate, calculate_1_fn);
  tcase_add_test(tc_calculate, calculate_2_fn);
  tcase_add_test(tc_calculate, calculate_3_fn);
  tcase_add_test(tc_calculate, calculate_4_fn);
  tcase_add_test(tc_calculate, calculate_5_fn);
  tcase_add_test(tc_calculate, calculate_6_fn);
  tcase_add_test(tc_calculate, calculate_7_fn);
  tcase_add_test(tc_calculate, calculate_8_fn);
  tcase_add_test(tc_calculate, calculate_9_fn);
  tcase_add_test(tc_calculate, calculate_10_fn);
  tcase_add_test(tc_calculate, calculate_11_fn);
  tcase_add_test(tc_calculate, calculate_12_fn);
  tcase_add_test(tc_calculate, calculate_13_fn);
  tcase_add_test(tc_calculate, calculate_14_fn);
  tcase_add_test(tc_calculate, calculate_15_fn);

  TCase *tc_credit_calc = tcase_create("credit calculation");
  suite_add_tcase(s, tc_credit_calc);
  tcase_add_test(tc_credit_calc, credit_calculate_fn);
  tcase_add_test(tc_credit_calc, credit_calculate_1_fn);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s = calc_suit();
  ;
  SRunner *sr;

  // s = calc_suit();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (0 == number_failed) ? EXIT_SUCCESS : EXIT_FAILURE;
}