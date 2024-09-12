#ifndef SRC_TESTS_S21_DECIMAL_TST_H_
#define SRC_TESTS_S21_DECIMAL_TST_H_

#include <stdlib.h>
#include <stdio.h>
#include <check.h>
#include <time.h>
#include "../s21_decimal.h"

#define NEGATIVE 2147483648

Suite *s21_suite_arith();
Suite *suite_comp();
Suite *suite_dtof();
Suite *suite_dtoi();
Suite *suite_ftod();
Suite *suite_floor();
Suite *suite_itod();
Suite *suite_negate();
Suite *suite_round();
Suite *suite_trun();

#endif // SRC_TESTS_S21_DECIMAL_TST_H_

