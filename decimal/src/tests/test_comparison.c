#include "s21_decimal_tst.h"

START_TEST(is_not_equal_1) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int ourRes = s21_is_not_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_not_equal_2) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 1, NEGATIVE}};

  int ourRes = s21_is_not_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_not_equal_3) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, NEGATIVE}};

  int ourRes = s21_is_not_equal(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_not_equal_4) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 1, 0}};

  int ourRes = s21_is_not_equal(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_not_equal_5) {
  s21_decimal x = {{0, 52, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int ourRes = s21_is_not_equal(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_not_equal_6) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{1747, 0, 1, 0}};
  int ourRes = s21_is_not_equal(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_not_equal_7) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{1747, 0, 1, 0}};

  int ourRes = s21_is_not_equal(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_not_equal_8) {
  s21_decimal x = {{1, 2, 3, 655360}};
  s21_decimal y = {{3, 2, 1, -2146828288}};
  int ourRes = s21_is_not_equal(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_not_equal_9) {
  s21_decimal x = {{1, 2, 3, -2146828288}};
  s21_decimal y = {{3, 2, 1, -2146828288}};
  int ourRes = s21_is_not_equal(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_not_equal_10) {
  s21_decimal x = {{1, 2, 3, -2146566144}};
  s21_decimal y = {{3, 2, 1, -2146959360}};
  int ourRes = s21_is_not_equal(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_not_equal_11) {
  s21_decimal x = {{10, 2, 3, -2146566144}};
  s21_decimal y = {{3, 2, 1, 524288}};
  int ourRes = s21_is_not_equal(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_not_equal_12) {
  s21_decimal x = {{1, 2, 3, 917504}};
  s21_decimal y = {{1, 2, 3, 917504}};
  int ourRes = s21_is_not_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_not_equal_13) {
  s21_decimal num1 = {{0, 0, 0, 0}};
  s21_decimal num2 = {{0, 0, 0, -2147483648}};
  int flag = s21_is_not_equal(num1, num2);
  ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(is_not_equal_14) {
  s21_decimal num1 = {{1, 0, 0, -2147483648}};
  s21_decimal num2 = {{1, 0, 0, 0}};
  int flag = s21_is_not_equal(num1, num2);
  ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(is_not_equal_15) {
  s21_decimal num1 = {{3, 2, 1, 0}};
  s21_decimal num2 = {{3, 2, 1, 0}};
  int flag = s21_is_not_equal(num1, num2);
  ck_assert_int_eq(flag, 0);
}
END_TEST

START_TEST(is_not_equal_16) {
  s21_decimal num1 = {{4, 2, 1, 0}};
  s21_decimal num2 = {{3, 2, 1, 0}};
  int flag = s21_is_not_equal(num1, num2);
  ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(is_not_equal_17) {
  s21_decimal num1 = {{4, 2, 1, 65536}};
  s21_decimal num2 = {{4, 2, 1, 0}};
  int flag1 = s21_is_not_equal(num1, num2);
  int flag2 = s21_is_not_equal(num2, num1);
  ck_assert_int_eq(flag1, 1);
  ck_assert_int_eq(flag2, 1);
}
END_TEST

START_TEST(is_not_equal_18) {
  s21_decimal num1 = {{4, 2, 1, 65536}};
  s21_decimal num2 = {{4, 3, 1, 0}};
  int flag1 = s21_is_not_equal(num1, num2);
  int flag2 = s21_is_not_equal(num2, num1);
  ck_assert_int_eq(flag1, 1);
  ck_assert_int_eq(flag2, 1);
}
END_TEST

START_TEST(is_not_equal_19) {
  s21_decimal num1 = {{44, 369, 1687, 65536}};
  s21_decimal num2 = {{44, 369, 1687, 65536}};
  int flag1 = s21_is_not_equal(num1, num2);
  ck_assert_int_eq(flag1, 0);
}
END_TEST

START_TEST(is_not_equal_20) {
  s21_decimal num1 = {{-1, -1, -1, 0}};
  s21_decimal num2 = {{44, 369, 1687, 65536}};
  int flag1 = s21_is_not_equal(num1, num2);
  ck_assert_int_eq(flag1, 1);
}
END_TEST

/*---------------------------------- IS EQUAL -------------------*/
START_TEST(is_equal_1) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int ourRes = s21_is_equal(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_equal_2) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 1, NEGATIVE}};

  int ourRes = s21_is_equal(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_equal_3) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, NEGATIVE}};

  int ourRes = s21_is_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_equal_4) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 1, 0}};

  int ourRes = s21_is_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_equal_5) {
  s21_decimal x = {{0, 52, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int ourRes = s21_is_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_equal_6) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{1747, 0, 1, 0}};
  int ourRes = s21_is_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_equal_7) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{1747, 0, 1, 0}};

  int ourRes = s21_is_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_equal_8) {
  s21_decimal x = {{0, 0, 0, NEGATIVE}};
  s21_decimal y = {{1, 0, 0, 0}};

  int ourRes = s21_is_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_equal_9) {
  s21_decimal x = {{1, 0, 0, 0}};
  s21_decimal y = {{0, 0, 0, NEGATIVE}};

  int ourRes = s21_is_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_equal_10) {
  s21_decimal x = {{0, 0, 0, 0}};
  s21_decimal y = {{0, 0, 0, NEGATIVE}};

  int ourRes = s21_is_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_equal_11) {
  s21_decimal x = {{1, 2, 3, 655360}};
  s21_decimal y = {{3, 2, 1, -2146828288}};
  int ourRes = s21_is_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_equal_12) {
  s21_decimal x = {{1, 2, 3, -2146828288}};
  s21_decimal y = {{3, 2, 1, -2146828288}};
  int ourRes = s21_is_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_equal_13) {
  s21_decimal x = {{1, 2, 3, -2146566144}};
  s21_decimal y = {{3, 2, 1, -2146959360}};
  int ourRes = s21_is_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_equal_14) {
  s21_decimal x = {{10, 2, 3, -2146566144}};
  s21_decimal y = {{3, 2, 1, 524288}};
  int ourRes = s21_is_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_equal_15) {
  s21_decimal x = {{1, 2, 3, 917504}};
  s21_decimal y = {{1, 2, 3, 917504}};
  int ourRes = s21_is_equal(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_equal_16) {
  s21_decimal num1 = {{0, 0, 0, 0}};
  s21_decimal num2 = {{0, 0, 0, -2147483648}};
  int flag = s21_is_equal(num1, num2);

  ck_assert_int_eq(flag, 0);
}
END_TEST

START_TEST(is_equal_17) {
  // Arrange
  s21_decimal num1 = {{0, 0, 0, -2147483648}};
  s21_decimal num2 = {{0, 0, 0, -2147483648}};
  // Act
  int flag = s21_is_equal(num1, num2);
  // Accert
  ck_assert_int_eq(flag, 1);
}
END_TEST

// START_TEST(is_equal_18) {
//   s21_decimal num1 = {{3345, 2656, 1242, 0}};
//   s21_decimal num2 = {{3345, 2656, 1242, 0}};
//   int flag = s21_is_equal(num1, num2);
//   ck_assert_int_eq(flag, 1);
// }
// END_TEST

START_TEST(is_equal_19) {
  s21_decimal num1 = {{467, 2, 1, 0}};
  s21_decimal num2 = {{3, 234653, 1, 0}};
  int flag = s21_is_equal(num1, num2);
  ck_assert_int_eq(flag, 0);
}
END_TEST

START_TEST(is_equal_20) {
  s21_decimal num1 = {{4, 2, 1, 589824}};
  s21_decimal num2 = {{4, 2, 1, 0}};
  int flag1 = s21_is_equal(num1, num2);
  int flag2 = s21_is_equal(num2, num1);
  ck_assert_int_eq(flag1, 0);
  ck_assert_int_eq(flag2, 0);
}
END_TEST

START_TEST(is_equal_21) {
  s21_decimal num1 = {{4, 2, 1, 65536}};
  s21_decimal num2 = {{4, 3, 1, 0}};
  int flag1 = s21_is_equal(num1, num2);
  int flag2 = s21_is_equal(num2, num1);
  ck_assert_int_eq(flag1, 0);
  ck_assert_int_eq(flag2, 0);
}
END_TEST

START_TEST(is_equal_22) {
  s21_decimal num1 = {{454, 3269, 16887, 786432}};
  s21_decimal num2 = {{454, 3269, 16887, 786432}};
  int flag1 = s21_is_equal(num1, num2);
  ck_assert_int_eq(flag1, 1);
}
END_TEST

START_TEST(is_equal_23) {
  s21_decimal num2 = {{-1, -1, -1, 0}};
  s21_decimal num1 = {{44, 369, 1687, 1835008}};
  int flag1 = s21_is_equal(num1, num2);
  ck_assert_int_eq(flag1, 0);
}
END_TEST

/*----------------------------------great-than tests-------------------*/
START_TEST(is_greater_1) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int ourRes = s21_is_greater(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_2) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int ourRes = s21_is_greater(y, x);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_3) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int ourRes = s21_is_greater(y, x);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_4) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 2, NEGATIVE}};

  int ourRes = s21_is_greater(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_5) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 2, NEGATIVE}};

  int ourRes = s21_is_greater(y, x);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_6) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 1, NEGATIVE}};
  int ourRes = s21_is_greater(y, x);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_7) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 1, 0}};

  int ourRes = s21_is_greater(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_8) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, NEGATIVE}};

  int ourRes = s21_is_greater(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_9) {
  s21_decimal x = {{1, 2, 3, 655360}};
  s21_decimal y = {{3, 2, 1, -2146828288}};
  int ourRes = s21_is_greater(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_10) {
  s21_decimal x = {{1, 2, 3, -2146828288}};
  s21_decimal y = {{3, 2, 1, -2146828288}};
  int ourRes = s21_is_greater(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_11) {
  s21_decimal x = {{1, 2, 3, -2146566144}};
  s21_decimal y = {{3, 2, 1, -2146959360}};
  int ourRes = s21_is_greater(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_12) {
  s21_decimal x = {{10, 2, 3, -2146566144}};
  s21_decimal y = {{3, 2, 1, 524288}};
  int ourRes = s21_is_greater(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_13) {
  s21_decimal x = {{1, 2, 3, 917504}};
  s21_decimal y = {{1, 2, 3, 917504}};
  int ourRes = s21_is_greater(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_14) {
  s21_decimal num1 = {{-1, -1, -1, -2147483648}};
  s21_decimal num2 = {{0, 0, 100, 0}};
  int flag1 = s21_is_greater(num1, num2);
  ck_assert_int_eq(flag1, 0);
}
END_TEST

START_TEST(is_greater_15) {
  s21_decimal num1 = {{1, 0, 0, 0}};
  s21_decimal num2 = {{1, 0, 0, -2147483648}};
  int flag1 = s21_is_greater(num1, num2);
  ck_assert_int_eq(flag1, 1);
}
END_TEST

START_TEST(is_greater_16) {
  s21_decimal num1 = {{10, 0, 0, -2147483648}};
  s21_decimal num2 = {{9, 0, 0, -2147483648}};
  int flag1 = s21_is_greater(num1, num2);
  ck_assert_int_eq(flag1, 0);
}
END_TEST

START_TEST(is_greater_17) {
  s21_decimal num1 = {{9, 90, 0, -2147483648}};
  s21_decimal num2 = {{10, 100, 0, -2147483648}};
  int flag1 = s21_is_greater(num1, num2);
  ck_assert_int_eq(flag1, 1);
}
END_TEST

START_TEST(is_greater_18) {
  s21_decimal num1 = {{10, 11, 12, 0}};
  s21_decimal num2 = {{9, 8, 130, 0}};
  int flag1 = s21_is_greater(num1, num2);
  ck_assert_int_eq(flag1, 0);
}
END_TEST

START_TEST(is_greater_19) {
  s21_decimal num1 = {{5, 1, 8, -2146041856}};
  s21_decimal num2 = {{5, 1, 8, -2146238464}};
  int flag1 = s21_is_greater(num1, num2);
  ck_assert_int_eq(flag1, 1);
}
END_TEST

START_TEST(is_greater_20) {
  s21_decimal num1 = {{5, 40, 8, -2146238464}};
  s21_decimal num2 = {{500, 1, 3, -2146041856}};
  int flag1 = s21_is_greater(num1, num2);
  ck_assert_int_eq(flag1, 0);
}
END_TEST

START_TEST(is_greater_21) {
  s21_decimal num1 = {{10, 11, 12, 65536}};
  s21_decimal num2 = {{9, 8, 13, 65536}};
  int flag1 = s21_is_greater(num1, num2);
  ck_assert_int_eq(flag1, 0);
}
END_TEST

START_TEST(is_greater_22) {
  s21_decimal num1 = {{6, 0, 0, 589824}};
  s21_decimal num2 = {{0, 0, 10, 0}};
  int flag1 = s21_is_greater(num1, num2);
  ck_assert_int_eq(flag1, 0);
}
END_TEST

/*---------------------------------- IS LESS -------------------*/
START_TEST(is_less_1) {
  s21_decimal x = {{4294967295, 0, 0, 0}};
  s21_decimal y = {{0, 1, 0, 0}};
  int ourRes = s21_is_less(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_2) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int ourRes = s21_is_less(y, x);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_3) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int ourRes = s21_is_less(y, x);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_4) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 2, NEGATIVE}};

  int ourRes = s21_is_less(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_5) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 2, NEGATIVE}};

  int ourRes = s21_is_less(y, x);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_6) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 1, NEGATIVE}};

  int ourRes = s21_is_less(y, x);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_7) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 1, 0}};

  int ourRes = s21_is_less(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_8) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, NEGATIVE}};

  int ourRes = s21_is_less(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_9) {
  s21_decimal x = {{1, 2, 3, 655360}};
  s21_decimal y = {{3, 2, 1, -2146828288}};
  int ourRes = s21_is_less(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_10) {
  s21_decimal x = {{1, 2, 3, -2146828288}};
  s21_decimal y = {{3, 2, 1, -2146828288}};
  int ourRes = s21_is_less(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_11) {
  s21_decimal x = {{1, 2, 3, -2146566144}};
  s21_decimal y = {{3, 2, 1, -2146959360}};
  int ourRes = s21_is_less(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_12) {
  s21_decimal x = {{10, 2, 3, -2146566144}};
  s21_decimal y = {{3, 2, 1, 524288}};
  int ourRes = s21_is_less(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_13) {
  s21_decimal x = {{1, 2, 3, 917504}};
  s21_decimal y = {{1, 2, 3, 917504}};
  int ourRes = s21_is_less(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_14) {
  s21_decimal num1 = {{-1, -1, -1, -2147483648}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  int flag1 = s21_is_less(num1, num2);
  ck_assert_int_eq(flag1, 1);
}
END_TEST

START_TEST(is_less_15) {
  s21_decimal num1 = {{1, 0, 0, 0}};
  s21_decimal num2 = {{1, 0, 0, -2147483648}};
  int flag1 = s21_is_less(num1, num2);
  ck_assert_int_eq(flag1, 0);
}
END_TEST

START_TEST(is_less_16) {
  s21_decimal num1 = {{10, 0, 0, -2147483648}};
  s21_decimal num2 = {{9, 0, 0, -2147483648}};
  int flag1 = s21_is_less(num1, num2);
  ck_assert_int_eq(flag1, 1);
}
END_TEST

START_TEST(is_less_17) {
  s21_decimal num1 = {{9, 0, 0, -2147483648}};
  s21_decimal num2 = {{10, 0, 0, -2147483648}};
  int flag1 = s21_is_less(num1, num2);
  ck_assert_int_eq(flag1, 0);
}
END_TEST

START_TEST(is_less_18) {
  s21_decimal num1 = {{10, 11, 12, 0}};
  s21_decimal num2 = {{9, 8, 13, 0}};
  int flag1 = s21_is_less(num1, num2);
  ck_assert_int_eq(flag1, 1);
}
END_TEST

START_TEST(is_less_19) {
  s21_decimal num1 = {{500, 1, 3, -2146041856}};
  s21_decimal num2 = {{5, 4, 8, -2146238464}};
  int flag1 = s21_is_less(num1, num2);
  ck_assert_int_eq(flag1, 0);
}
END_TEST

START_TEST(is_less_20) {
  s21_decimal num1 = {{5, 4, 8, -2146238464}};
  s21_decimal num2 = {{500, 1, 3, -2146041856}};
  int flag1 = s21_is_less(num1, num2);
  ck_assert_int_eq(flag1, 1);
}
END_TEST
START_TEST(is_less_21) {
  s21_decimal num1 = {{10, 11, 12, 65536}};
  s21_decimal num2 = {{9, 8, 13, 65536}};
  int flag1 = s21_is_less(num1, num2);
  ck_assert_int_eq(flag1, 1);
}
END_TEST

START_TEST(is_less_22) {
  s21_decimal num1 = {{6, 0, 0, 589824}};
  s21_decimal num2 = {{0, 0, 10, 0}};
  int flag1 = s21_is_less(num1, num2);
  ck_assert_int_eq(flag1, 1);
}
END_TEST

/*----------------------------------IS LESS OR EQUAL -----------*/

START_TEST(is_less_or_equal_1) {
  s21_decimal x = {{1, 2, 3, 655360}};
  s21_decimal y = {{3, 2, 1, -2146828288}};
  int ourRes = s21_is_less_or_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_or_equal_2) {
  s21_decimal x = {{1, 2, 3, -2146828288}};
  s21_decimal y = {{3, 2, 1, -2146828288}};
  int ourRes = s21_is_less_or_equal(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_or_equal_3) {
  s21_decimal x = {{1, 2, 3, -2146566144}};
  s21_decimal y = {{3, 2, 1, -2146959360}};
  int ourRes = s21_is_less_or_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_or_equal_4) {
  s21_decimal x = {{10, 2, 3, -2146566144}};
  s21_decimal y = {{3, 2, 1, 524288}};
  int ourRes = s21_is_less_or_equal(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_or_equal_5) {
  s21_decimal x = {{1, 2, 3, 917504}};
  s21_decimal y = {{1, 2, 3, 917504}};
  int ourRes = s21_is_less_or_equal(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_or_equal_6) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int ourRes = s21_is_less_or_equal(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_or_equal_7) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int ourRes = s21_is_less_or_equal(y, x);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_or_equal_8) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int ourRes = s21_is_less_or_equal(y, x);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_or_equal_9) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 2, NEGATIVE}};

  int ourRes = s21_is_less_or_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_or_equal_10) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 2, NEGATIVE}};

  int ourRes = s21_is_less_or_equal(y, x);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_or_equal_11) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 1, NEGATIVE}};

  int ourRes = s21_is_less_or_equal(y, x);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_or_equal_12) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 1, 0}};

  int ourRes = s21_is_less_or_equal(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_less_or_equal_13) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, NEGATIVE}};

  int ourRes = s21_is_less_or_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

/*----------------------------------greater or equal----------*/
START_TEST(is_greater_or_equal_1) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int ourRes = s21_is_greater_or_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_or_equal_2) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int ourRes = s21_is_greater_or_equal(y, x);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_or_equal_3) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int ourRes = s21_is_greater_or_equal(y, x);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_or_equal_4) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 2, NEGATIVE}};

  int ourRes = s21_is_greater_or_equal(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_or_equal_5) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 2, NEGATIVE}};

  int ourRes = s21_is_greater_or_equal(y, x);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_or_equal_6) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 1, NEGATIVE}};

  int ourRes = s21_is_greater_or_equal(y, x);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_or_equal_7) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 1, 0}};

  int ourRes = s21_is_greater_or_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_or_equal_8) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, NEGATIVE}};

  int ourRes = s21_is_greater_or_equal(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_or_equal_9) {
  s21_decimal x = {{1, 2, 3, 655360}};
  s21_decimal y = {{3, 2, 1, -2146828288}};

  int ourRes = s21_is_greater_or_equal(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_or_equal_10) {
  s21_decimal x = {{1, 2, 3, -2146828288}};
  s21_decimal y = {{3, 2, 1, -2146828288}};

  int ourRes = s21_is_greater_or_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_or_equal_11) {
  s21_decimal x = {{1, 2, 3, -2146566144}};
  s21_decimal y = {{3, 2, 1, -2146959360}};

  int ourRes = s21_is_greater_or_equal(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_or_equal_12) {
  s21_decimal x = {{10, 2, 3, -2146566144}};
  s21_decimal y = {{3, 2, 1, 524288}};

  int ourRes = s21_is_greater_or_equal(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_or_equal_13) {
  s21_decimal x = {{1, 2, 3, 917504}};
  s21_decimal y = {{1, 2, 3, 917504}};

  int ourRes = s21_is_greater_or_equal(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_or_equal_14) {
  s21_decimal num1 = {{6, 0, 0, 589824}};
  s21_decimal num2 = {{6, 0, 0, 589824}};
  int flag1 = s21_is_greater_or_equal(num1, num2);
  ck_assert_int_eq(flag1, 1);
}
END_TEST

START_TEST(is_greater_or_equal_15) {
  s21_decimal num1 = {{6, 0, 1, 589824}};
  s21_decimal num2 = {{6, 0, 0, 589824}};
  int flag1 = s21_is_greater_or_equal(num1, num2);
  ck_assert_int_eq(flag1, 1);
}
END_TEST

START_TEST(is_greater_or_equal_16) {
  s21_decimal num1 = {{5, 0, 0, 589824}};
  s21_decimal num2 = {{6, 0, 0, 589824}};
  int flag1 = s21_is_greater_or_equal(num1, num2);
  ck_assert_int_eq(flag1, 0);
}
END_TEST

START_TEST(s21_less_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b10000000000000000000000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b00000000000000000000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 1);
}
END_TEST

START_TEST(s21_less_2) {
  s21_decimal first = {{4412, 5675, 1254, 0b00000000000000000000000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b10000000000000000000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 0);
}
END_TEST

START_TEST(s21_less_3_zero) {
  s21_decimal first = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal second = {{0, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 0);
}
END_TEST

// START_TEST(s21_less_4_zero) {
//   s21_decimal first = {{0, 0, 0, 0b10000000000000000000000000000000}};
//   s21_decimal second = {{0, 0, 0, 0b00000000000000000000000000000000}};
//   ck_assert_int_eq(s21_is_less(first, second), 0);
// }
// END_TEST

// START_TEST(s21_less_5_len_int_part) {
//   s21_decimal first = {{0, 0, 0, 0b10000000000000000000000000000000}};
//   s21_decimal second = {{0, 0, 0, 0b00000000000000000000000000000000}};
//   ck_assert_int_eq(s21_is_less(first, second), 0);
// }
// END_TEST

START_TEST(s21_less_6_len_int_part_positive) {
  s21_decimal first = {{4412, 5675, 1254, 0b00000011000000000000000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b00000101000000000000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 0);
}
END_TEST

START_TEST(s21_less_7_len_int_part_negative) {
  s21_decimal first = {{4422, 5515, 9254, 0b10000000000000110000000000000000}};
  s21_decimal second = {{6312, 5616, 1844, 0b10000000000001010000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 1);
}
END_TEST

START_TEST(s21_less_8_value_int_part_positive) {
  s21_decimal first = {{4412, 5775, 1254, 0b00000000000001110000000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b00000000000001110000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 0);
}
END_TEST

START_TEST(s21_less_9_value_fract_part_positive) {
  s21_decimal first = {{4412, 5775, 1254, 0b00000000000010000000000000000000}};
  s21_decimal second = {{4412, 5775, 1254, 0b00000000000001110000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 1);
}
END_TEST

START_TEST(s21_less_10_max_int_positive) {
  s21_decimal first = {
      {2147483646, 2147483647, 2147483647, 0b00000000000001110000000000000000}};
  s21_decimal second = {
      {2147483647, 2147483647, 2147483647, 0b00000000000001110000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 1);
}
END_TEST

START_TEST(s21_less_11_max_int_negative) {
  s21_decimal first = {
      {2147483647, 2147483647, 2147483647, 0b10000000000001110000000000000000}};
  s21_decimal second = {
      {2147483646, 2147483647, 2147483647, 0b10000000000001110000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 1);
}
END_TEST

START_TEST(s21_less_12) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_13) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2.00;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_14) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

// START_TEST(s21_less_15) {
//   s21_decimal src1, src2;
//   int origin;
//   // src1 = 0.000000000000000000000000000;
//   // src2 = 0;
//   src1.bits[0] = 0b00000000000000000000000000000000;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000110110000000000000000;
//   src2.bits[0] = 0b00000000000000000000000000000000;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000000000000000000000;
//   int result = s21_is_less(src1, src2);
//   origin = 0;
//   ck_assert_int_eq(origin, result);
// }
// END_TEST

START_TEST(s21_less_16) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -3;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_17) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_18) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.22221200000001000;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000111100011111010001111101000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_19) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 3.2222121;
  // src2 = 3.222212;
  src1.bits[0] = 0b00000001111010111010101110101001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001110000000000000000;
  src2.bits[0] = 0b00000000001100010010101011000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_20) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = -2.2222120002;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00101100100010101010010001000010;
  src2.bits[1] = 0b00000000000000000000000000000101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000010100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_21) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_22) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 987456543210.0;
  // src2 = 98745654321.0;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11101000111111110001100111101010;
  src2.bits[1] = 0b00000000000000000000000011100101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_23) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -9878798789.5867800;
  // src2 = -9878798789.58678;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b10110101010001000001111001010110;
  src2.bits[1] = 0b00000000000000111000001001111000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_24) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_25) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615;
  // src2 = 18446744073709551615.000000000;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11000100011001010011011000000000;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00111011100110101100100111111111;
  src2.bits[3] = 0b00000000000010010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_26) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_27) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -545454512454545.35265454545645;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b10000010111000100101101011101101;
  src2.bits[1] = 0b11111001111010000010010110101101;
  src2.bits[2] = 0b10110000001111101111000010010100;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_28) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_29) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 7961327.845421879754123131254;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b01001110111001000011100101110110;
  src2.bits[1] = 0b01001011001101011010000111011001;
  src2.bits[2] = 0b00011001101110010111010010111111;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_30) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 12345677.987654000000000000000;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b11100111110001110000000000000000;
  src2.bits[1] = 0b11000000010001001001101110001101;
  src2.bits[2] = 0b00100111111001000001101100000000;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_31) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_32) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876531;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110011;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_33) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876530;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110010;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_34) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.0;
  // src2 = 0.69;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000001000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_35) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -69.1234567;
  // src2 = -69.12345670000000;
  src1.bits[0] = 0b00101001001100110110011100000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b11100100001110011001110110000000;
  src2.bits[1] = 0b00000000000110001000111010111101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_36) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 13436577854.000000000000;
  // src2 = 13436577854;
  src1.bits[0] = 0b00100110011110011110000000000000;
  src1.bits[1] = 0b01100101111110011111000000101100;
  src1.bits[2] = 0b00000000000000000000001011011000;
  src1.bits[3] = 0b00000000000011000000000000000000;
  src2.bits[0] = 0b00100000111000011110100000111110;
  src2.bits[1] = 0b00000000000000000000000000000011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_37) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_38) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_39) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_40) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.7986531268974139743;
  // src2 = 2.7986531268974139743;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11111110100100001101100101011111;
  src2.bits[1] = 0b10000100011001000010000111101000;
  src2.bits[2] = 0b00000000000000000000000000000001;
  src2.bits[3] = 0b00000000000100110000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_41) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2156878451.8547640000000000;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_42) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 5.4564654654864768465454654846;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b01101110100110100110010101111110;
  src2.bits[1] = 0b11100010111000110111110100101010;
  src2.bits[2] = 0b10110000010011101101001100001111;
  src2.bits[3] = 0b00000000000111000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_43) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -7.7545545454546589781677545545;
  // src2 = -7.7545545454546589781677545545;
  src1.bits[0] = 0b00000101101101111001100001001001;
  src1.bits[1] = 0b01101011011011011010110110010010;
  src1.bits[2] = 0b11111010100100000010101111111010;
  src1.bits[3] = 0b10000000000111000000000000000000;
  src2.bits[0] = 0b00000101101101111001100001001001;
  src2.bits[1] = 0b01101011011011011010110110010010;
  src2.bits[2] = 0b11111010100100000010101111111010;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_44) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -79228162514264337593543950335;
  // src2 = -792281625.14264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000101000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_45) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 675432788976.5424354657687;
  // src2 = 67543278.89765424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_46) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -579895323215489956.67897455465;
  // src2 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_47) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 1844674407370955161.50;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11111111111111111111111111110110;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00000000000000000000000000001001;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_48) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 44073709551615.0;
  // src2 = 44073709551615.00000000;
  src1.bits[0] = 0b00011010000001000111111111110110;
  src1.bits[1] = 0b00000000000000011001000011011001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b10011111010010100001111100000000;
  src2.bits[1] = 0b11101100100011110001010001110111;
  src2.bits[2] = 0b00000000000000000000000011101110;
  src2.bits[3] = 0b00000000000010000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_49) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 228162514264337.5935439503;
  // src2 = 228162514264337.59354395030000;
  src1.bits[0] = 0b01010010111101011100001010001111;
  src1.bits[1] = 0b00100101100101100010101000001101;
  src1.bits[2] = 0b00000000000000011110001100100111;
  src1.bits[3] = 0b00000000000010100000000000000000;
  src2.bits[0] = 0b10011111111111111111000111110000;
  src2.bits[1] = 0b00111001110010101010100001111000;
  src2.bits[2] = 0b01001001101110010010100100101100;
  src2.bits[3] = 0b00000000000011100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_50) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -754554545454658.97816770;
  // src2 = -754554545454658.9781677;
  src1.bits[0] = 0b00100000101101101001001011000010;
  src1.bits[1] = 0b01110010110010011000000011111000;
  src1.bits[2] = 0b00000000000000000000111111111010;
  src1.bits[3] = 0b10000000000010000000000000000000;
  src2.bits[0] = 0b10011100110111110000111010101101;
  src2.bits[1] = 0b00001011011110101000110011100101;
  src2.bits[2] = 0b00000000000000000000000110011001;
  src2.bits[3] = 0b10000000000001110000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_51) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2.514264337593543;
  // src2 = -2.514264337593542;
  src1.bits[0] = 0b11001000101101101011010011000111;
  src1.bits[1] = 0b00000000000010001110111010110101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b11001000101101101011010011000110;
  src2.bits[1] = 0b00000000000010001110111010110101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_52) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -79228162514264337593543950335;
  // src2 = 0;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b00000100000000000010000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b00000100000000000010000000000000}};
  ck_assert_int_eq(s21_is_equal(first, second), 1);
}
END_TEST

START_TEST(s21_is_equalal_2) {
  s21_decimal first = {{4412, 5675, 1254, 0b10000100000000000010000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b10000100000000000010000000000000}};
  ck_assert_int_eq(s21_is_equal(first, second), 1);
}
END_TEST

START_TEST(s21_is_equalal_3_fraction) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110010000000001110000111000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11001001000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 1);
}
END_TEST

START_TEST(s21_is_equalal_4_sign) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b01110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST

START_TEST(s21_is_equalal_5_sign) {
  s21_decimal first = {{4412, 5675, 1254, 0b00110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST

START_TEST(s21_is_equalal_6) {
  s21_decimal first = {{4412, 5675, 1154, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST

START_TEST(s21_is_equalal_7) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1244, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST

START_TEST(s21_is_equalal_8) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {
      {4412, 5675, 12541, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST

START_TEST(s21_is_equalal_9_ss) {
  s21_decimal first = {
      {0x4A1D, 05675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {
      {0x4A1D, 05675, 1254, 0b10110100111111110010000000000011}};
  ck_assert_int_eq(s21_is_equal(first, second), 1);
}
END_TEST

START_TEST(s21_is_equalal_10) {
  s21_decimal first = {{412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST

START_TEST(s21_is_equalal_12_value) {
  s21_decimal first = {
      {1564, 31452, 6109410, 0b11110100000000000010000111111110}};
  s21_decimal second = {
      {1564, 31452, 610941, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST

START_TEST(s21_is_equalal_13_value) {
  s21_decimal first = {
      {1564, 31452, 610941, 0b11110100000000000010000111111110}};
  s21_decimal second = {
      {1564, 3142, 610941, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST

START_TEST(s21_is_equalal_14_value) {
  s21_decimal first = {
      {15614, 31452, 610941, 0b11110100000000000010000111111110}};
  s21_decimal second = {
      {1564, 31452, 610941, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST

START_TEST(s21_is_equalal_15) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

// START_TEST(s21_is_equalal_16) {
//   s21_decimal src1, src2;
//   int origin;
//   // src1 = 2;
//   // src2 = 2.00;
//   src1.bits[0] = 0b00000000000000000000000000000010;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   src2.bits[0] = 0b00000000000000000000000011001000;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000100000000000000000;
//   int result = s21_is_equal(src1, src2);
//   origin = 1;
//   ck_assert_int_eq(origin, result);
// }
// END_TEST

START_TEST(s21_is_equalal_17) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

// START_TEST(s21_is_equalal_18) {
//   s21_decimal src1, src2;
//   int origin;
//   // src1 = 0.000000000000000000000000000;
//   // src2 = 0;
//   src1.bits[0] = 0b00000000000000000000000000000000;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000110110000000000000000;
//   src2.bits[0] = 0b00000000000000000000000000000000;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000000000000000000000;
//   int result = s21_is_equal(src1, src2);
//   origin = 1;
//   ck_assert_int_eq(origin, result);
// }
// END_TEST

START_TEST(s21_is_equalal_19) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -3;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_20) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_21) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.22221200000000000;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000111100011111010000000000000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_22) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 3.2222121;
  // src2 = 3.222212;
  src1.bits[0] = 0b00000001111010111010101110101001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001110000000000000000;
  src2.bits[0] = 0b00000000001100010010101011000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_23) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = -2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_24) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_25) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 987456543210.0;
  // src2 = 98745654321.0;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11101000111111110001100111101010;
  src2.bits[1] = 0b00000000000000000000000011100101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_26) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -9878798789.5867800;
  // src2 = -9878798789.58678;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b10110101010001000001111001010110;
  src2.bits[1] = 0b00000000000000111000001001111000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_27) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_28) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615;
  // src2 = 18446744073709551615.000000000;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11000100011001010011011000000000;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00111011100110101100100111111111;
  src2.bits[3] = 0b00000000000010010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_29) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_30) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -545454512454545.35265454545645;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b10000010111000100101101011101101;
  src2.bits[1] = 0b11111001111010000010010110101101;
  src2.bits[2] = 0b10110000001111101111000010010100;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_31) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_32) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 7961327.845421879754123131254;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b01001110111001000011100101110110;
  src2.bits[1] = 0b01001011001101011010000111011001;
  src2.bits[2] = 0b00011001101110010111010010111111;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_33) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 12345677.987654000000000000000;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b11100111110001110000000000000000;
  src2.bits[1] = 0b11000000010001001001101110001101;
  src2.bits[2] = 0b00100111111001000001101100000000;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_34) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_35) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876531;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110011;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_36) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876530;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110010;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_37) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.0;
  // src2 = 0.69;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000001000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_38) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -69.1234567;
  // src2 = -69.12345670000000;
  src1.bits[0] = 0b00101001001100110110011100000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b11100100001110011001110110000000;
  src2.bits[1] = 0b00000000000110001000111010111101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_39) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 13436577854.000000000000;
  // src2 = 13436577854;
  src1.bits[0] = 0b00100110011110011110000000000000;
  src1.bits[1] = 0b01100101111110011111000000101100;
  src1.bits[2] = 0b00000000000000000000001011011000;
  src1.bits[3] = 0b00000000000011000000000000000000;
  src2.bits[0] = 0b00100000111000011110100000111110;
  src2.bits[1] = 0b00000000000000000000000000000011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_40) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_41) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_42) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_43) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.7986531268974139743;
  // src2 = 2.7986531268974139743;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11111110100100001101100101011111;
  src2.bits[1] = 0b10000100011001000010000111101000;
  src2.bits[2] = 0b00000000000000000000000000000001;
  src2.bits[3] = 0b00000000000100110000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_44) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2156878451.8547640000000000;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_45) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 5.4564654654864768465454654846;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b01101110100110100110010101111110;
  src2.bits[1] = 0b11100010111000110111110100101010;
  src2.bits[2] = 0b10110000010011101101001100001111;
  src2.bits[3] = 0b00000000000111000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_46) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -7.7545545454546589781677545545;
  // src2 = -7.7545545454546589781677545545;
  src1.bits[0] = 0b00000101101101111001100001001001;
  src1.bits[1] = 0b01101011011011011010110110010010;
  src1.bits[2] = 0b11111010100100000010101111111010;
  src1.bits[3] = 0b10000000000111000000000000000000;
  src2.bits[0] = 0b00000101101101111001100001001001;
  src2.bits[1] = 0b01101011011011011010110110010010;
  src2.bits[2] = 0b11111010100100000010101111111010;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_47) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -79228162514264337593543950335;
  // src2 = -792281625.14264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000101000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_48) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 675432788976.5424354657687;
  // src2 = 67543278.89765424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_49) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -579895323215489956.67897455465;
  // src2 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_50) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 1844674407370955161.50;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11111111111111111111111111110110;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00000000000000000000000000001001;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_51) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 44073709551615.0;
  // src2 = 44073709551615.00000000;
  src1.bits[0] = 0b00011010000001000111111111110110;
  src1.bits[1] = 0b00000000000000011001000011011001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b10011111010010100001111100000000;
  src2.bits[1] = 0b11101100100011110001010001110111;
  src2.bits[2] = 0b00000000000000000000000011101110;
  src2.bits[3] = 0b00000000000010000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_52) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 228162514264337.5935439503;
  // src2 = 228162514264337.59354395030000;
  src1.bits[0] = 0b01010010111101011100001010001111;
  src1.bits[1] = 0b00100101100101100010101000001101;
  src1.bits[2] = 0b00000000000000011110001100100111;
  src1.bits[3] = 0b00000000000010100000000000000000;
  src2.bits[0] = 0b10011111111111111111000111110000;
  src2.bits[1] = 0b00111001110010101010100001111000;
  src2.bits[2] = 0b01001001101110010010100100101100;
  src2.bits[3] = 0b00000000000011100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_53) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -754554545454658.97816770;
  // src2 = -754554545454658.9781677;
  src1.bits[0] = 0b00100000101101101001001011000010;
  src1.bits[1] = 0b01110010110010011000000011111000;
  src1.bits[2] = 0b00000000000000000000111111111010;
  src1.bits[3] = 0b10000000000010000000000000000000;
  src2.bits[0] = 0b10011100110111110000111010101101;
  src2.bits[1] = 0b00001011011110101000110011100101;
  src2.bits[2] = 0b00000000000000000000000110011001;
  src2.bits[3] = 0b10000000000001110000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_54) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2.514264337593543;
  // src2 = -2.5142643375935430000000000000;
  src1.bits[0] = 0b11001000101101101011010011000111;
  src1.bits[1] = 0b00000000000010001110111010110101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b01010011100110100110000000000000;
  src2.bits[1] = 0b10000010110010001001101110001011;
  src2.bits[2] = 0b01010001001111011000000111010100;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_1_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b00000100000000000010000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b00000100000000000010000000000000}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 0);
}
END_TEST

START_TEST(s21_not_equal_2_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b10000100000000000010000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b10000100000000000010000000000000}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 0);
}
END_TEST

START_TEST(s21_not_equal_3_fraction_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110010000000001110000111000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11001001000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 0);
}
END_TEST

START_TEST(s21_not_equal_4_sign_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b01110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST

START_TEST(s21_not_equal_5_sign_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b00110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST

START_TEST(s21_not_equal_6_1) {
  s21_decimal first = {{4412, 5675, 1154, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST

START_TEST(s21_not_equal_7_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1244, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST

START_TEST(s21_not_equal_8_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {
      {4412, 5675, 12541, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST

START_TEST(s21_not_equal_9_ss_1) {
  s21_decimal first = {
      {0x4A1D, 05675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {
      {0x4A1D, 05675, 1254, 0b10110100111111110010000000000011}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 0);
}
END_TEST

START_TEST(s21_not_equal_10_1) {
  s21_decimal first = {{412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST

// START_TEST(s21_not_equal_11_zero_1) {
//   s21_decimal first = {{0, 0, 0, 0b11110100000000000010000111111110}};
//   s21_decimal second = {{0, 0, 0, 0b01110100000000000010000111111110}};
//   ck_assert_int_eq(s21_is_not_equal(first, second), 0);
// }
// END_TEST

START_TEST(s21_not_equal_12_value_1) {
  s21_decimal first = {
      {1564, 31452, 6109410, 0b11110100000000000010000111111110}};
  s21_decimal second = {
      {1564, 31452, 610941, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST

START_TEST(s21_not_equal_13_value_1) {
  s21_decimal first = {
      {1564, 31452, 610941, 0b11110100000000000010000111111110}};
  s21_decimal second = {
      {1564, 3142, 610941, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST

START_TEST(s21_not_equal_14_value_1) {
  s21_decimal first = {
      {15614, 31452, 610941, 0b11110100000000000010000111111110}};
  s21_decimal second = {
      {1564, 31452, 610941, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST

START_TEST(s21_not_equal_1) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_2) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2.00;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_3) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

// START_TEST(s21_not_equal_4) {
//   s21_decimal src1, src2;
//   int origin;
//   // src1 = 0.000000000000000000000000000;
//   // src2 = 0;
//   src1.bits[0] = 0b00000000000000000000000000000000;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000110110000000000000000;
//   src2.bits[0] = 0b00000000000000000000000000000000;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000000000000000000000;
//   int result = s21_is_not_equal(src1, src2);
//   origin = 0;
//   ck_assert_int_eq(origin, result);
// }
// END_TEST

START_TEST(s21_not_equal_5) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -3;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_6) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_7) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.22221200000000000;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000111100011111010000000000000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_8) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 3.2222121;
  // src2 = 3.222212;
  src1.bits[0] = 0b00000001111010111010101110101001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001110000000000000000;
  src2.bits[0] = 0b00000000001100010010101011000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_9) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = -2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_10) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_11) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 987456543210.0;
  // src2 = 98745654321.0;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11101000111111110001100111101010;
  src2.bits[1] = 0b00000000000000000000000011100101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_12) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -9878798789.5867800;
  // src2 = -9878798789.58678;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b10110101010001000001111001010110;
  src2.bits[1] = 0b00000000000000111000001001111000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_13) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_14) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615;
  // src2 = 18446744073709551615.000000000;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11000100011001010011011000000000;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00111011100110101100100111111111;
  src2.bits[3] = 0b00000000000010010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_15) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_16) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -545454512454545.35265454545645;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b10000010111000100101101011101101;
  src2.bits[1] = 0b11111001111010000010010110101101;
  src2.bits[2] = 0b10110000001111101111000010010100;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_17) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_18) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 7961327.845421879754123131254;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b01001110111001000011100101110110;
  src2.bits[1] = 0b01001011001101011010000111011001;
  src2.bits[2] = 0b00011001101110010111010010111111;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_19) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 12345677.987654000000000000000;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b11100111110001110000000000000000;
  src2.bits[1] = 0b11000000010001001001101110001101;
  src2.bits[2] = 0b00100111111001000001101100000000;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_20) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_21) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876531;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110011;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_22) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876530;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110010;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_23) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.0;
  // src2 = 0.69;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000001000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_24) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -69.1234567;
  // src2 = -69.12345670000000;
  src1.bits[0] = 0b00101001001100110110011100000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b11100100001110011001110110000000;
  src2.bits[1] = 0b00000000000110001000111010111101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_25) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 13436577854.000000000000;
  // src2 = 13436577854;
  src1.bits[0] = 0b00100110011110011110000000000000;
  src1.bits[1] = 0b01100101111110011111000000101100;
  src1.bits[2] = 0b00000000000000000000001011011000;
  src1.bits[3] = 0b00000000000011000000000000000000;
  src2.bits[0] = 0b00100000111000011110100000111110;
  src2.bits[1] = 0b00000000000000000000000000000011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_26) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_27) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_28) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_29) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.7986531268974139743;
  // src2 = 2.7986531268974139743;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11111110100100001101100101011111;
  src2.bits[1] = 0b10000100011001000010000111101000;
  src2.bits[2] = 0b00000000000000000000000000000001;
  src2.bits[3] = 0b00000000000100110000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_30) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2156878451.8547640000000000;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_31) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 5.4564654654864768465454654846;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b01101110100110100110010101111110;
  src2.bits[1] = 0b11100010111000110111110100101010;
  src2.bits[2] = 0b10110000010011101101001100001111;
  src2.bits[3] = 0b00000000000111000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_32) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -7.7545545454546589781677545545;
  // src2 = -7.7545545454546589781677545545;
  src1.bits[0] = 0b00000101101101111001100001001001;
  src1.bits[1] = 0b01101011011011011010110110010010;
  src1.bits[2] = 0b11111010100100000010101111111010;
  src1.bits[3] = 0b10000000000111000000000000000000;
  src2.bits[0] = 0b00000101101101111001100001001001;
  src2.bits[1] = 0b01101011011011011010110110010010;
  src2.bits[2] = 0b11111010100100000010101111111010;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_33) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -79228162514264337593543950335;
  // src2 = -792281625.14264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000101000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_34) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 675432788976.5424354657687;
  // src2 = 67543278.89765424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_35) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -579895323215489956.67897455465;
  // src2 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_36) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 1844674407370955161.50;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11111111111111111111111111110110;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00000000000000000000000000001001;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_37) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 44073709551615.0;
  // src2 = 44073709551615.00000000;
  src1.bits[0] = 0b00011010000001000111111111110110;
  src1.bits[1] = 0b00000000000000011001000011011001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b10011111010010100001111100000000;
  src2.bits[1] = 0b11101100100011110001010001110111;
  src2.bits[2] = 0b00000000000000000000000011101110;
  src2.bits[3] = 0b00000000000010000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_38) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 228162514264337.5935439503;
  // src2 = 228162514264337.59354395030000;
  src1.bits[0] = 0b01010010111101011100001010001111;
  src1.bits[1] = 0b00100101100101100010101000001101;
  src1.bits[2] = 0b00000000000000011110001100100111;
  src1.bits[3] = 0b00000000000010100000000000000000;
  src2.bits[0] = 0b10011111111111111111000111110000;
  src2.bits[1] = 0b00111001110010101010100001111000;
  src2.bits[2] = 0b01001001101110010010100100101100;
  src2.bits[3] = 0b00000000000011100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_39) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -754554545454658.97816770;
  // src2 = -754554545454658.9781677;
  src1.bits[0] = 0b00100000101101101001001011000010;
  src1.bits[1] = 0b01110010110010011000000011111000;
  src1.bits[2] = 0b00000000000000000000111111111010;
  src1.bits[3] = 0b10000000000010000000000000000000;
  src2.bits[0] = 0b10011100110111110000111010101101;
  src2.bits[1] = 0b00001011011110101000110011100101;
  src2.bits[2] = 0b00000000000000000000000110011001;
  src2.bits[3] = 0b10000000000001110000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_40) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2.514264337593543;
  // src2 = -2.5142643375935430000000000000;
  src1.bits[0] = 0b11001000101101101011010011000111;
  src1.bits[1] = 0b00000000000010001110111010110101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b01010011100110100110000000000000;
  src2.bits[1] = 0b10000010110010001001101110001011;
  src2.bits[2] = 0b01010001001111011000000111010100;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_1) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_2) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2.00;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_3) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_4) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.000000000000000000000000000;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_5) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -3;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_6) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_7) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.22221200000001000;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000111100011111010001111101000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_8) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 3.2222121;
  // src2 = 3.222212;
  src1.bits[0] = 0b00000001111010111010101110101001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001110000000000000000;
  src2.bits[0] = 0b00000000001100010010101011000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_9) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = -2.2222120002;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00101100100010101010010001000010;
  src2.bits[1] = 0b00000000000000000000000000000101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000010100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_10) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_11) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 987456543210.0;
  // src2 = 98745654321.0;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11101000111111110001100111101010;
  src2.bits[1] = 0b00000000000000000000000011100101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_12) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -9878798789.5867800;
  // src2 = -9878798789.58678;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b10110101010001000001111001010110;
  src2.bits[1] = 0b00000000000000111000001001111000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_13) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_14) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615;
  // src2 = 18446744073709551615.000000000;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11000100011001010011011000000000;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00111011100110101100100111111111;
  src2.bits[3] = 0b00000000000010010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_15) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_16) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -545454512454545.35265454545645;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b10000010111000100101101011101101;
  src2.bits[1] = 0b11111001111010000010010110101101;
  src2.bits[2] = 0b10110000001111101111000010010100;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_17) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_18) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 7961327.845421879754123131254;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b01001110111001000011100101110110;
  src2.bits[1] = 0b01001011001101011010000111011001;
  src2.bits[2] = 0b00011001101110010111010010111111;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_19) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 12345677.987654000000000000000;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b11100111110001110000000000000000;
  src2.bits[1] = 0b11000000010001001001101110001101;
  src2.bits[2] = 0b00100111111001000001101100000000;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_20) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_21) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876531;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110011;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_22) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876530;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110010;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_23) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.0;
  // src2 = 0.69;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000001000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_24) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -69.1234567;
  // src2 = -69.12345670000000;
  src1.bits[0] = 0b00101001001100110110011100000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b11100100001110011001110110000000;
  src2.bits[1] = 0b00000000000110001000111010111101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_25) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 13436577854.000000000000;
  // src2 = 13436577854;
  src1.bits[0] = 0b00100110011110011110000000000000;
  src1.bits[1] = 0b01100101111110011111000000101100;
  src1.bits[2] = 0b00000000000000000000001011011000;
  src1.bits[3] = 0b00000000000011000000000000000000;
  src2.bits[0] = 0b00100000111000011110100000111110;
  src2.bits[1] = 0b00000000000000000000000000000011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_26) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_27) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_28) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_29) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.7986531268974139743;
  // src2 = 2.7986531268974139743;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11111110100100001101100101011111;
  src2.bits[1] = 0b10000100011001000010000111101000;
  src2.bits[2] = 0b00000000000000000000000000000001;
  src2.bits[3] = 0b00000000000100110000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_30) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2156878451.8547640000000000;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_31) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 5.4564654654864768465454654846;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b01101110100110100110010101111110;
  src2.bits[1] = 0b11100010111000110111110100101010;
  src2.bits[2] = 0b10110000010011101101001100001111;
  src2.bits[3] = 0b00000000000111000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_32) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -7.7545545454546589781677545545;
  // src2 = -7.7545545454546589781677545545;
  src1.bits[0] = 0b00000101101101111001100001001001;
  src1.bits[1] = 0b01101011011011011010110110010010;
  src1.bits[2] = 0b11111010100100000010101111111010;
  src1.bits[3] = 0b10000000000111000000000000000000;
  src2.bits[0] = 0b00000101101101111001100001001001;
  src2.bits[1] = 0b01101011011011011010110110010010;
  src2.bits[2] = 0b11111010100100000010101111111010;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_33) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -79228162514264337593543950335;
  // src2 = -792281625.14264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000101000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_34) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 675432788976.5424354657687;
  // src2 = 67543278.89765424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_35) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -579895323215489956.67897455465;
  // src2 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_36) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 1844674407370955161.50;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11111111111111111111111111110110;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00000000000000000000000000001001;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_37) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 44073709551615.0;
  // src2 = 44073709551615.00000000;
  src1.bits[0] = 0b00011010000001000111111111110110;
  src1.bits[1] = 0b00000000000000011001000011011001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b10011111010010100001111100000000;
  src2.bits[1] = 0b11101100100011110001010001110111;
  src2.bits[2] = 0b00000000000000000000000011101110;
  src2.bits[3] = 0b00000000000010000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_38) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 228162514264337.5935439503;
  // src2 = 228162514264337.59354395030000;
  src1.bits[0] = 0b01010010111101011100001010001111;
  src1.bits[1] = 0b00100101100101100010101000001101;
  src1.bits[2] = 0b00000000000000011110001100100111;
  src1.bits[3] = 0b00000000000010100000000000000000;
  src2.bits[0] = 0b10011111111111111111000111110000;
  src2.bits[1] = 0b00111001110010101010100001111000;
  src2.bits[2] = 0b01001001101110010010100100101100;
  src2.bits[3] = 0b00000000000011100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_39) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -754554545454658.97816770;
  // src2 = -754554545454658.9781677;
  src1.bits[0] = 0b00100000101101101001001011000010;
  src1.bits[1] = 0b01110010110010011000000011111000;
  src1.bits[2] = 0b00000000000000000000111111111010;
  src1.bits[3] = 0b10000000000010000000000000000000;
  src2.bits[0] = 0b10011100110111110000111010101101;
  src2.bits[1] = 0b00001011011110101000110011100101;
  src2.bits[2] = 0b00000000000000000000000110011001;
  src2.bits[3] = 0b10000000000001110000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_40) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2.514264337593543;
  // src2 = -2.514264337593542;
  src1.bits[0] = 0b11001000101101101011010011000111;
  src1.bits[1] = 0b00000000000010001110111010110101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b11001000101101101011010011000110;
  src2.bits[1] = 0b00000000000010001110111010110101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_1) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_2) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 457;
  // src2 = 2.00;
  src1.bits[0] = 0b00000000000000000000000111001001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_3) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 54;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000110110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_4) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.000000000000000000000000000;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_5) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -3;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_6) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_7) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.22221200000001000;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000111100011111010001111101000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_8) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 3.745754741;
  // src2 = 3.222212;
  src1.bits[0] = 0b11011111010000111010111001110101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010010000000000000000;
  src2.bits[0] = 0b00000000001100010010101011000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_9) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = -2.2222120002;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00101100100010101010010001000010;
  src2.bits[1] = 0b00000000000000000000000000000101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000010100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_10) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_11) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 987456543210.0;
  // src2 = 98745654321.0;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11101000111111110001100111101010;
  src2.bits[1] = 0b00000000000000000000000011100101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_12) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -9878798789.5867800;
  // src2 = -9878798789.58678;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b10110101010001000001111001010110;
  src2.bits[1] = 0b00000000000000111000001001111000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_13) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_14) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615;
  // src2 = 434345343551615.00000000000;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01000110001111010001100000000000;
  src2.bits[1] = 0b11010011010011111110100110011101;
  src2.bits[2] = 0b00000000001000111110110110011110;
  src2.bits[3] = 0b00000000000010110000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_15) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_16) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -796214545.3526545454564545456;
  // src2 = -545454512454545.35265454545645;
  src1.bits[0] = 0b10111111111111101001001110110000;
  src1.bits[1] = 0b11101010111111101111100111101000;
  src1.bits[2] = 0b00011001101110100010000111100001;
  src1.bits[3] = 0b10000000000100110000000000000000;
  src2.bits[0] = 0b10000010111000100101101011101101;
  src2.bits[1] = 0b11111001111010000010010110101101;
  src2.bits[2] = 0b10110000001111101111000010010100;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_17) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_18) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -7961327845421.843434341378545;
  // src2 = 7961327.845421879754123131254;
  src1.bits[0] = 0b11110011001100111010100111110001;
  src1.bits[1] = 0b01001011001101011000000011010000;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b01001110111001000011100101110110;
  src2.bits[1] = 0b01001011001101011010000111011001;
  src2.bits[2] = 0b00011001101110010111010010111111;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_19) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 12345677.987654000000000000000;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b11100111110001110000000000000000;
  src2.bits[1] = 0b11000000010001001001101110001101;
  src2.bits[2] = 0b00100111111001000001101100000000;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_20) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 145752736456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b10001101100101011101000110000101;
  src2.bits[1] = 0b11000001100101010111000111101011;
  src2.bits[2] = 0b00000100101101011010001101101100;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_21) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876531;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110011;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_22) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -854764561465456456.9876545679;
  // src2 = -87654323456.98765456789876530;
  src1.bits[0] = 0b11000100000001000100000010001111;
  src1.bits[1] = 0b01000000100100100110001100010101;
  src1.bits[2] = 0b00011011100111100111001001011101;
  src1.bits[3] = 0b10000000000010100000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110010;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_23) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.0;
  // src2 = 0.69;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000001000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_24) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -69.1234567;
  // src2 = -69.12345670000000;
  src1.bits[0] = 0b00101001001100110110011100000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b11100100001110011001110110000000;
  src2.bits[1] = 0b00000000000110001000111010111101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_25) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 13436577854.000000000000;
  // src2 = 13436577854;
  src1.bits[0] = 0b00100110011110011110000000000000;
  src1.bits[1] = 0b01100101111110011111000000101100;
  src1.bits[2] = 0b00000000000000000000001011011000;
  src1.bits[3] = 0b00000000000011000000000000000000;
  src2.bits[0] = 0b00100000111000011110100000111110;
  src2.bits[1] = 0b00000000000000000000000000000011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_26) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_27) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_28) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_29) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.7986531268974139743;
  // src2 = 2.7986531268974139743;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11111110100100001101100101011111;
  src2.bits[1] = 0b10000100011001000010000111101000;
  src2.bits[2] = 0b00000000000000000000000000000001;
  src2.bits[3] = 0b00000000000100110000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_30) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2156878451.8547640000000000;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_31) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 45645405.456456345684654546548;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b01000110110111011101111001110100;
  src2.bits[1] = 0b11111110010110110111101101110010;
  src2.bits[2] = 0b10010011011111001111111010010011;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_32) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -776890.75455454213415678965898;
  // src2 = -7.7545545454546589781677545545;
  src1.bits[0] = 0b11000010010111101111100010001010;
  src1.bits[1] = 0b01011100000101000111000011011000;
  src1.bits[2] = 0b11111011000001101110010110100011;
  src1.bits[3] = 0b10000000000101110000000000000000;
  src2.bits[0] = 0b00000101101101111001100001001001;
  src2.bits[1] = 0b01101011011011011010110110010010;
  src2.bits[2] = 0b11111010100100000010101111111010;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_33) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -732123534337593543950335.12;
  // src2 = -792281625.14264337593543950335;
  src1.bits[0] = 0b11000011000110111111111110101000;
  src1.bits[1] = 0b10100001110111010100101100101110;
  src1.bits[2] = 0b00000000001111001000111101010001;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000101000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_34) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 675432788976.5424354657687;
  // src2 = 67543278.89765424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_35) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -579895323215489956.67897455465;
  // src2 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_36) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 123523543453453453.0;
  // src2 = 1844674407370955161.50;
  src1.bits[0] = 0b01001001011001111111110110000010;
  src1.bits[1] = 0b00010001001001000111000000010101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11111111111111111111111111110110;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00000000000000000000000000001001;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_37) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 31231232456315.0;
  // src2 = 44073709551615.00000000;
  src1.bits[0] = 0b11100001001010100010000011001110;
  src1.bits[1] = 0b00000000000000010001110000001011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b10011111010010100001111100000000;
  src2.bits[1] = 0b11101100100011110001010001110111;
  src2.bits[2] = 0b00000000000000000000000011101110;
  src2.bits[3] = 0b00000000000010000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_38) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 78987543557678337.5935439503;
  // src2 = 228162514264337.59354395030000;
  src1.bits[0] = 0b00111011110001111000001010001111;
  src1.bits[1] = 0b00101001100010100010010001100011;
  src1.bits[2] = 0b00000010100011010101111010100001;
  src1.bits[3] = 0b00000000000010100000000000000000;
  src2.bits[0] = 0b10011111111111111111000111110000;
  src2.bits[1] = 0b00111001110010101010100001111000;
  src2.bits[2] = 0b01001001101110010010100100101100;
  src2.bits[3] = 0b00000000000011100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_39) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -754567488438.97816770;
  // src2 = -754554545454658.9781677;
  src1.bits[0] = 0b01011010011001011000011011000010;
  src1.bits[1] = 0b00010111001011000011100101001001;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000010000000000000000000;
  src2.bits[0] = 0b10011100110111110000111010101101;
  src2.bits[1] = 0b00001011011110101000110011100101;
  src2.bits[2] = 0b00000000000000000000000110011001;
  src2.bits[3] = 0b10000000000001110000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_40) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2.514475768684753643;
  // src2 = -2.514264337593542;
  src1.bits[0] = 0b10101100110010000011001011101011;
  src1.bits[1] = 0b00100010111001010011011001100011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000100100000000000000000;
  src2.bits[0] = 0b11001000101101101011010011000110;
  src2.bits[1] = 0b00000000000010001110111010110101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_1) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_2) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 457;
  // src2 = 2.00;
  src1.bits[0] = 0b00000000000000000000000111001001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_3) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 54;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000110110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

// START_TEST(s21_greater_or_equal_4) {
//   s21_decimal src1, src2;
//   int origin;
//   // src1 = 0.000000000000000000000000000;
//   // src2 = 0;
//   src1.bits[0] = 0b00000000000000000000000000000000;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000110110000000000000000;
//   src2.bits[0] = 0b00000000000000000000000000000000;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000000000000000000000;
//   int result = s21_is_greater_or_equal(src1, src2);
//   origin = 1;
//   ck_assert_int_eq(origin, result);
// }
// END_TEST

START_TEST(s21_greater_or_equal_5) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -3;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_6) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_7) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.22221200000001000;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000111100011111010001111101000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_8) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 3.745754741;
  // src2 = 3.222212;
  src1.bits[0] = 0b11011111010000111010111001110101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010010000000000000000;
  src2.bits[0] = 0b00000000001100010010101011000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_9) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = -2.2222120002;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00101100100010101010010001000010;
  src2.bits[1] = 0b00000000000000000000000000000101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000010100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_10) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_11) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 987456543210.0;
  // src2 = 98745654321.0;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11101000111111110001100111101010;
  src2.bits[1] = 0b00000000000000000000000011100101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_12) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -9878798789.5867800;
  // src2 = -9878798789.58678;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b10110101010001000001111001010110;
  src2.bits[1] = 0b00000000000000111000001001111000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_13) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_14) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615;
  // src2 = 434345343551615.00000000000;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01000110001111010001100000000000;
  src2.bits[1] = 0b11010011010011111110100110011101;
  src2.bits[2] = 0b00000000001000111110110110011110;
  src2.bits[3] = 0b00000000000010110000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_15) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_16) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -796214545.3526545454564545456;
  // src2 = -545454512454545.35265454545645;
  src1.bits[0] = 0b10111111111111101001001110110000;
  src1.bits[1] = 0b11101010111111101111100111101000;
  src1.bits[2] = 0b00011001101110100010000111100001;
  src1.bits[3] = 0b10000000000100110000000000000000;
  src2.bits[0] = 0b10000010111000100101101011101101;
  src2.bits[1] = 0b11111001111010000010010110101101;
  src2.bits[2] = 0b10110000001111101111000010010100;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_17) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_18) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -7961327845421.843434341378545;
  // src2 = 7961327.845421879754123131254;
  src1.bits[0] = 0b11110011001100111010100111110001;
  src1.bits[1] = 0b01001011001101011000000011010000;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b01001110111001000011100101110110;
  src2.bits[1] = 0b01001011001101011010000111011001;
  src2.bits[2] = 0b00011001101110010111010010111111;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_19) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 12345677.987654000000000000000;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b11100111110001110000000000000000;
  src2.bits[1] = 0b11000000010001001001101110001101;
  src2.bits[2] = 0b00100111111001000001101100000000;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_20) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 145752736456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b10001101100101011101000110000101;
  src2.bits[1] = 0b11000001100101010111000111101011;
  src2.bits[2] = 0b00000100101101011010001101101100;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_21) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876531;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110011;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_22) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -854764561465456456.9876545679;
  // src2 = -87654323456.98765456789876530;
  src1.bits[0] = 0b11000100000001000100000010001111;
  src1.bits[1] = 0b01000000100100100110001100010101;
  src1.bits[2] = 0b00011011100111100111001001011101;
  src1.bits[3] = 0b10000000000010100000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110010;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_23) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.0;
  // src2 = 0.69;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000001000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_24) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -69.1234567;
  // src2 = -69.12345670000000;
  src1.bits[0] = 0b00101001001100110110011100000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b11100100001110011001110110000000;
  src2.bits[1] = 0b00000000000110001000111010111101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_25) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 13436577854.000000000000;
  // src2 = 13436577854;
  src1.bits[0] = 0b00100110011110011110000000000000;
  src1.bits[1] = 0b01100101111110011111000000101100;
  src1.bits[2] = 0b00000000000000000000001011011000;
  src1.bits[3] = 0b00000000000011000000000000000000;
  src2.bits[0] = 0b00100000111000011110100000111110;
  src2.bits[1] = 0b00000000000000000000000000000011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_26) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_27) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_28) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_29) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.7986531268974139743;
  // src2 = 2.7986531268974139743;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11111110100100001101100101011111;
  src2.bits[1] = 0b10000100011001000010000111101000;
  src2.bits[2] = 0b00000000000000000000000000000001;
  src2.bits[3] = 0b00000000000100110000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_30) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2156878451.8547640000000000;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_31) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 45645405.456456345684654546548;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b01000110110111011101111001110100;
  src2.bits[1] = 0b11111110010110110111101101110010;
  src2.bits[2] = 0b10010011011111001111111010010011;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_32) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -776890.75455454213415678965898;
  // src2 = -7.7545545454546589781677545545;
  src1.bits[0] = 0b11000010010111101111100010001010;
  src1.bits[1] = 0b01011100000101000111000011011000;
  src1.bits[2] = 0b11111011000001101110010110100011;
  src1.bits[3] = 0b10000000000101110000000000000000;
  src2.bits[0] = 0b00000101101101111001100001001001;
  src2.bits[1] = 0b01101011011011011010110110010010;
  src2.bits[2] = 0b11111010100100000010101111111010;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_33) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -732123534337593543950335.12;
  // src2 = -792281625.14264337593543950335;
  src1.bits[0] = 0b11000011000110111111111110101000;
  src1.bits[1] = 0b10100001110111010100101100101110;
  src1.bits[2] = 0b00000000001111001000111101010001;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000101000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_34) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 675432788976.5424354657687;
  // src2 = 67543278.89765424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_35) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -579895323215489956.67897455465;
  // src2 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_36) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 123523543453453453.0;
  // src2 = 1844674407370955161.50;
  src1.bits[0] = 0b01001001011001111111110110000010;
  src1.bits[1] = 0b00010001001001000111000000010101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11111111111111111111111111110110;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00000000000000000000000000001001;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_37) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 31231232456315.0;
  // src2 = 44073709551615.00000000;
  src1.bits[0] = 0b11100001001010100010000011001110;
  src1.bits[1] = 0b00000000000000010001110000001011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b10011111010010100001111100000000;
  src2.bits[1] = 0b11101100100011110001010001110111;
  src2.bits[2] = 0b00000000000000000000000011101110;
  src2.bits[3] = 0b00000000000010000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_38) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 78987543557678337.5935439503;
  // src2 = 228162514264337.59354395030000;
  src1.bits[0] = 0b00111011110001111000001010001111;
  src1.bits[1] = 0b00101001100010100010010001100011;
  src1.bits[2] = 0b00000010100011010101111010100001;
  src1.bits[3] = 0b00000000000010100000000000000000;
  src2.bits[0] = 0b10011111111111111111000111110000;
  src2.bits[1] = 0b00111001110010101010100001111000;
  src2.bits[2] = 0b01001001101110010010100100101100;
  src2.bits[3] = 0b00000000000011100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_39) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -754567488438.97816770;
  // src2 = -754554545454658.9781677;
  src1.bits[0] = 0b01011010011001011000011011000010;
  src1.bits[1] = 0b00010111001011000011100101001001;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000010000000000000000000;
  src2.bits[0] = 0b10011100110111110000111010101101;
  src2.bits[1] = 0b00001011011110101000110011100101;
  src2.bits[2] = 0b00000000000000000000000110011001;
  src2.bits[3] = 0b10000000000001110000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_40) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2.514475768684753643;
  // src2 = -2.514264337593542;
  src1.bits[0] = 0b10101100110010000011001011101011;
  src1.bits[1] = 0b00100010111001010011011001100011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000100100000000000000000;
  src2.bits[0] = 0b11001000101101101011010011000110;
  src2.bits[1] = 0b00000000000010001110111010110101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

Suite *suite_comp(void) {
  Suite *s = suite_create("comparation");
  TCase *tc = tcase_create("insert_tc");

  tcase_add_test(tc, is_not_equal_1);
  tcase_add_test(tc, is_not_equal_2);
  tcase_add_test(tc, is_not_equal_3);
  tcase_add_test(tc, is_not_equal_4);
  tcase_add_test(tc, is_not_equal_5);
  tcase_add_test(tc, is_not_equal_6);
  tcase_add_test(tc, is_not_equal_7);
  tcase_add_test(tc, is_not_equal_8);
  tcase_add_test(tc, is_not_equal_9);
  tcase_add_test(tc, is_not_equal_10);
  tcase_add_test(tc, is_not_equal_11);
  tcase_add_test(tc, is_not_equal_12);
  tcase_add_test(tc, is_not_equal_13);
  tcase_add_test(tc, is_not_equal_14);
  tcase_add_test(tc, is_not_equal_15);
  tcase_add_test(tc, is_not_equal_16);
  tcase_add_test(tc, is_not_equal_17);
  //  tcase_add_test(tc, is_not_equal_18);
  tcase_add_test(tc, is_not_equal_19);
  tcase_add_test(tc, is_not_equal_20);

  tcase_add_test(tc, is_equal_1);
  tcase_add_test(tc, is_equal_2);
  tcase_add_test(tc, is_equal_3);
  tcase_add_test(tc, is_equal_4);
  tcase_add_test(tc, is_equal_5);
  tcase_add_test(tc, is_equal_6);
  tcase_add_test(tc, is_equal_7);
  tcase_add_test(tc, is_equal_8);
  tcase_add_test(tc, is_equal_9);
  tcase_add_test(tc, is_equal_10);
  tcase_add_test(tc, is_equal_11);
  tcase_add_test(tc, is_equal_12);
  tcase_add_test(tc, is_equal_13);
  tcase_add_test(tc, is_equal_14);
  tcase_add_test(tc, is_equal_15);
  tcase_add_test(tc, is_equal_16);
  tcase_add_test(tc, is_equal_17);
  //  tcase_add_test(tc, is_equal_18);
  tcase_add_test(tc, is_equal_19);
  tcase_add_test(tc, is_equal_20);

  tcase_add_test(tc, is_equal_21);
  tcase_add_test(tc, is_equal_22);
  tcase_add_test(tc, is_equal_23);

  tcase_add_test(tc, is_less_22);
  tcase_add_test(tc, is_less_1);
  tcase_add_test(tc, is_less_2);
  tcase_add_test(tc, is_less_3);
  tcase_add_test(tc, is_less_4);
  tcase_add_test(tc, is_less_5);
  tcase_add_test(tc, is_less_6);
  tcase_add_test(tc, is_less_7);
  tcase_add_test(tc, is_less_8);
  tcase_add_test(tc, is_less_9);
  tcase_add_test(tc, is_less_10);
  tcase_add_test(tc, is_less_11);
  tcase_add_test(tc, is_less_12);
  tcase_add_test(tc, is_less_13);
  tcase_add_test(tc, is_less_14);
  tcase_add_test(tc, is_less_15);
  tcase_add_test(tc, is_less_16);
  tcase_add_test(tc, is_less_17);
  tcase_add_test(tc, is_less_18);
  tcase_add_test(tc, is_less_19);
  tcase_add_test(tc, is_less_20);
  tcase_add_test(tc, is_less_21);
  tcase_add_test(tc, is_less_22);

  tcase_add_test(tc, is_greater_1);
  tcase_add_test(tc, is_greater_2);
  tcase_add_test(tc, is_greater_3);
  tcase_add_test(tc, is_greater_4);
  tcase_add_test(tc, is_greater_5);
  tcase_add_test(tc, is_greater_6);
  tcase_add_test(tc, is_greater_7);
  tcase_add_test(tc, is_greater_8);
  tcase_add_test(tc, is_greater_9);
  tcase_add_test(tc, is_greater_10);
  tcase_add_test(tc, is_greater_11);
  tcase_add_test(tc, is_greater_12);
  tcase_add_test(tc, is_greater_13);
  tcase_add_test(tc, is_greater_14);
  tcase_add_test(tc, is_greater_15);
  tcase_add_test(tc, is_greater_16);
  tcase_add_test(tc, is_greater_17);
  tcase_add_test(tc, is_greater_18);
  tcase_add_test(tc, is_greater_19);
  tcase_add_test(tc, is_greater_20);
  tcase_add_test(tc, is_greater_21);
  tcase_add_test(tc, is_greater_22);

  tcase_add_test(tc, is_greater_or_equal_1);
  tcase_add_test(tc, is_greater_or_equal_2);
  tcase_add_test(tc, is_greater_or_equal_3);
  tcase_add_test(tc, is_greater_or_equal_4);
  tcase_add_test(tc, is_greater_or_equal_5);
  tcase_add_test(tc, is_greater_or_equal_6);
  tcase_add_test(tc, is_greater_or_equal_7);
  tcase_add_test(tc, is_greater_or_equal_8);
  tcase_add_test(tc, is_greater_or_equal_9);
  tcase_add_test(tc, is_greater_or_equal_10);
  tcase_add_test(tc, is_greater_or_equal_11);
  tcase_add_test(tc, is_greater_or_equal_12);
  tcase_add_test(tc, is_greater_or_equal_13);
  tcase_add_test(tc, is_greater_or_equal_14);
  tcase_add_test(tc, is_greater_or_equal_15);
  tcase_add_test(tc, is_greater_or_equal_16);

  tcase_add_test(tc, is_less_or_equal_1);
  tcase_add_test(tc, is_less_or_equal_2);
  tcase_add_test(tc, is_less_or_equal_3);
  tcase_add_test(tc, is_less_or_equal_4);
  tcase_add_test(tc, is_less_or_equal_5);
  tcase_add_test(tc, is_less_or_equal_6);
  tcase_add_test(tc, is_less_or_equal_7);
  tcase_add_test(tc, is_less_or_equal_8);
  tcase_add_test(tc, is_less_or_equal_9);
  tcase_add_test(tc, is_less_or_equal_10);
  tcase_add_test(tc, is_less_or_equal_11);
  tcase_add_test(tc, is_less_or_equal_12);
  tcase_add_test(tc, is_less_or_equal_13);

  tcase_add_test(tc, s21_is_equalal_1);
  tcase_add_test(tc, s21_is_equalal_2);
  tcase_add_test(tc, s21_is_equalal_3_fraction);
  tcase_add_test(tc, s21_is_equalal_4_sign);
  tcase_add_test(tc, s21_is_equalal_5_sign);
  tcase_add_test(tc, s21_is_equalal_6);
  tcase_add_test(tc, s21_is_equalal_7);
  tcase_add_test(tc, s21_is_equalal_8);
  tcase_add_test(tc, s21_is_equalal_9_ss);
  tcase_add_test(tc, s21_is_equalal_10);
  tcase_add_test(tc, s21_is_equalal_12_value);
  tcase_add_test(tc, s21_is_equalal_13_value);
  tcase_add_test(tc, s21_is_equalal_14_value);
  tcase_add_test(tc, s21_is_equalal_15);
  tcase_add_test(tc, s21_is_equalal_17);
  //  tcase_add_test(tc, s21_is_equalal_18);
  tcase_add_test(tc, s21_is_equalal_19);
  tcase_add_test(tc, s21_is_equalal_20);
  tcase_add_test(tc, s21_is_equalal_21);
  tcase_add_test(tc, s21_is_equalal_22);
  tcase_add_test(tc, s21_is_equalal_23);
  tcase_add_test(tc, s21_is_equalal_24);
  tcase_add_test(tc, s21_is_equalal_25);
  tcase_add_test(tc, s21_is_equalal_26);
  tcase_add_test(tc, s21_is_equalal_27);
  tcase_add_test(tc, s21_is_equalal_28);
  tcase_add_test(tc, s21_is_equalal_29);
  tcase_add_test(tc, s21_is_equalal_30);
  tcase_add_test(tc, s21_is_equalal_31);
  tcase_add_test(tc, s21_is_equalal_32);
  tcase_add_test(tc, s21_is_equalal_33);
  tcase_add_test(tc, s21_is_equalal_34);
  tcase_add_test(tc, s21_is_equalal_35);
  tcase_add_test(tc, s21_is_equalal_36);
  tcase_add_test(tc, s21_is_equalal_37);
  tcase_add_test(tc, s21_is_equalal_38);
  tcase_add_test(tc, s21_is_equalal_39);
  tcase_add_test(tc, s21_is_equalal_40);
  tcase_add_test(tc, s21_is_equalal_41);
  tcase_add_test(tc, s21_is_equalal_42);
  tcase_add_test(tc, s21_is_equalal_43);
  tcase_add_test(tc, s21_is_equalal_44);
  tcase_add_test(tc, s21_is_equalal_45);
  tcase_add_test(tc, s21_is_equalal_46);
  tcase_add_test(tc, s21_is_equalal_47);
  tcase_add_test(tc, s21_is_equalal_48);
  tcase_add_test(tc, s21_is_equalal_49);
  tcase_add_test(tc, s21_is_equalal_50);
  tcase_add_test(tc, s21_is_equalal_51);
  tcase_add_test(tc, s21_is_equalal_52);
  tcase_add_test(tc, s21_is_equalal_53);
  tcase_add_test(tc, s21_is_equalal_54);
  tcase_add_test(tc, s21_not_equal_1_1);
  tcase_add_test(tc, s21_not_equal_2_1);
  tcase_add_test(tc, s21_not_equal_3_fraction_1);
  tcase_add_test(tc, s21_not_equal_4_sign_1);
  tcase_add_test(tc, s21_not_equal_5_sign_1);
  tcase_add_test(tc, s21_not_equal_6_1);
  tcase_add_test(tc, s21_not_equal_7_1);
  tcase_add_test(tc, s21_not_equal_8_1);
  tcase_add_test(tc, s21_not_equal_9_ss_1);
  tcase_add_test(tc, s21_not_equal_10_1);
  //  tcase_add_test(tc, s21_not_equal_11_zero_1);
  tcase_add_test(tc, s21_not_equal_12_value_1);
  tcase_add_test(tc, s21_not_equal_13_value_1);
  tcase_add_test(tc, s21_not_equal_14_value_1);
  tcase_add_test(tc, s21_not_equal_1);
  tcase_add_test(tc, s21_not_equal_2);
  tcase_add_test(tc, s21_not_equal_3);
  //  tcase_add_test(tc, s21_not_equal_4);
  tcase_add_test(tc, s21_not_equal_5);
  tcase_add_test(tc, s21_not_equal_6);
  tcase_add_test(tc, s21_not_equal_7);
  tcase_add_test(tc, s21_not_equal_8);
  tcase_add_test(tc, s21_not_equal_9);
  tcase_add_test(tc, s21_not_equal_10);
  tcase_add_test(tc, s21_not_equal_11);
  tcase_add_test(tc, s21_not_equal_12);
  tcase_add_test(tc, s21_not_equal_13);
  tcase_add_test(tc, s21_not_equal_14);
  tcase_add_test(tc, s21_not_equal_15);
  tcase_add_test(tc, s21_not_equal_16);
  tcase_add_test(tc, s21_not_equal_17);
  tcase_add_test(tc, s21_not_equal_18);
  tcase_add_test(tc, s21_not_equal_19);
  tcase_add_test(tc, s21_not_equal_20);
  tcase_add_test(tc, s21_not_equal_21);
  tcase_add_test(tc, s21_not_equal_22);
  tcase_add_test(tc, s21_not_equal_23);
  tcase_add_test(tc, s21_not_equal_24);
  tcase_add_test(tc, s21_not_equal_25);
  tcase_add_test(tc, s21_not_equal_26);
  tcase_add_test(tc, s21_not_equal_27);
  tcase_add_test(tc, s21_not_equal_28);
  tcase_add_test(tc, s21_not_equal_29);
  tcase_add_test(tc, s21_not_equal_30);
  tcase_add_test(tc, s21_not_equal_31);
  tcase_add_test(tc, s21_not_equal_32);
  tcase_add_test(tc, s21_not_equal_33);
  tcase_add_test(tc, s21_not_equal_34);
  tcase_add_test(tc, s21_not_equal_35);
  tcase_add_test(tc, s21_not_equal_36);
  tcase_add_test(tc, s21_not_equal_37);
  tcase_add_test(tc, s21_not_equal_38);
  tcase_add_test(tc, s21_not_equal_39);
  tcase_add_test(tc, s21_not_equal_40);
  tcase_add_test(tc, s21_less_1);
  tcase_add_test(tc, s21_less_2);
  tcase_add_test(tc, s21_less_3_zero);
  //  tcase_add_test(tc, s21_less_4_zero);
  //  tcase_add_test(tc, s21_less_5_len_int_part);
  tcase_add_test(tc, s21_less_6_len_int_part_positive);
  tcase_add_test(tc, s21_less_7_len_int_part_negative);
  tcase_add_test(tc, s21_less_8_value_int_part_positive);
  tcase_add_test(tc, s21_less_9_value_fract_part_positive);
  tcase_add_test(tc, s21_less_10_max_int_positive);
  tcase_add_test(tc, s21_less_11_max_int_negative);
  tcase_add_test(tc, s21_less_12);
  tcase_add_test(tc, s21_less_13);
  tcase_add_test(tc, s21_less_14);
  //  tcase_add_test(tc, s21_less_15);
  tcase_add_test(tc, s21_less_16);
  tcase_add_test(tc, s21_less_17);
  tcase_add_test(tc, s21_less_18);
  tcase_add_test(tc, s21_less_19);
  tcase_add_test(tc, s21_less_20);
  tcase_add_test(tc, s21_less_21);
  tcase_add_test(tc, s21_less_22);
  tcase_add_test(tc, s21_less_23);
  tcase_add_test(tc, s21_less_24);
  tcase_add_test(tc, s21_less_25);
  tcase_add_test(tc, s21_less_26);
  tcase_add_test(tc, s21_less_27);
  tcase_add_test(tc, s21_less_28);
  tcase_add_test(tc, s21_less_29);
  tcase_add_test(tc, s21_less_30);
  tcase_add_test(tc, s21_less_31);
  tcase_add_test(tc, s21_less_32);
  tcase_add_test(tc, s21_less_33);
  tcase_add_test(tc, s21_less_34);
  tcase_add_test(tc, s21_less_35);
  tcase_add_test(tc, s21_less_36);
  tcase_add_test(tc, s21_less_37);
  tcase_add_test(tc, s21_less_38);
  tcase_add_test(tc, s21_less_39);
  tcase_add_test(tc, s21_less_40);
  tcase_add_test(tc, s21_less_41);
  tcase_add_test(tc, s21_less_42);
  tcase_add_test(tc, s21_less_43);
  tcase_add_test(tc, s21_less_44);
  tcase_add_test(tc, s21_less_45);
  tcase_add_test(tc, s21_less_46);
  tcase_add_test(tc, s21_less_47);
  tcase_add_test(tc, s21_less_48);
  tcase_add_test(tc, s21_less_49);
  tcase_add_test(tc, s21_less_50);
  tcase_add_test(tc, s21_less_51);
  tcase_add_test(tc, s21_less_52);
  tcase_add_test(tc, s21_less_or_equal_1);
  tcase_add_test(tc, s21_less_or_equal_2);
  tcase_add_test(tc, s21_less_or_equal_3);
  tcase_add_test(tc, s21_less_or_equal_4);
  tcase_add_test(tc, s21_less_or_equal_5);
  tcase_add_test(tc, s21_less_or_equal_6);
  tcase_add_test(tc, s21_less_or_equal_7);
  tcase_add_test(tc, s21_less_or_equal_8);
  tcase_add_test(tc, s21_less_or_equal_9);
  tcase_add_test(tc, s21_less_or_equal_10);
  tcase_add_test(tc, s21_less_or_equal_11);
  tcase_add_test(tc, s21_less_or_equal_12);
  tcase_add_test(tc, s21_less_or_equal_13);
  tcase_add_test(tc, s21_less_or_equal_14);
  tcase_add_test(tc, s21_less_or_equal_15);
  tcase_add_test(tc, s21_less_or_equal_16);
  tcase_add_test(tc, s21_less_or_equal_17);
  tcase_add_test(tc, s21_less_or_equal_18);
  tcase_add_test(tc, s21_less_or_equal_19);
  tcase_add_test(tc, s21_less_or_equal_20);
  tcase_add_test(tc, s21_less_or_equal_21);
  tcase_add_test(tc, s21_less_or_equal_22);
  tcase_add_test(tc, s21_less_or_equal_23);
  tcase_add_test(tc, s21_less_or_equal_24);
  tcase_add_test(tc, s21_less_or_equal_25);
  tcase_add_test(tc, s21_less_or_equal_26);
  tcase_add_test(tc, s21_less_or_equal_27);
  tcase_add_test(tc, s21_less_or_equal_28);
  tcase_add_test(tc, s21_less_or_equal_29);
  tcase_add_test(tc, s21_less_or_equal_30);
  tcase_add_test(tc, s21_less_or_equal_31);
  tcase_add_test(tc, s21_less_or_equal_32);
  tcase_add_test(tc, s21_less_or_equal_33);
  tcase_add_test(tc, s21_less_or_equal_34);
  tcase_add_test(tc, s21_less_or_equal_35);
  tcase_add_test(tc, s21_less_or_equal_36);
  tcase_add_test(tc, s21_less_or_equal_37);
  tcase_add_test(tc, s21_less_or_equal_38);
  tcase_add_test(tc, s21_less_or_equal_39);
  tcase_add_test(tc, s21_less_or_equal_40);
  tcase_add_test(tc, s21_greater_1);
  tcase_add_test(tc, s21_greater_2);
  tcase_add_test(tc, s21_greater_3);
  tcase_add_test(tc, s21_greater_4);
  tcase_add_test(tc, s21_greater_5);
  tcase_add_test(tc, s21_greater_6);
  tcase_add_test(tc, s21_greater_7);
  tcase_add_test(tc, s21_greater_8);
  tcase_add_test(tc, s21_greater_9);
  tcase_add_test(tc, s21_greater_10);
  tcase_add_test(tc, s21_greater_11);
  tcase_add_test(tc, s21_greater_12);
  tcase_add_test(tc, s21_greater_13);
  tcase_add_test(tc, s21_greater_14);
  tcase_add_test(tc, s21_greater_15);
  tcase_add_test(tc, s21_greater_16);
  tcase_add_test(tc, s21_greater_17);
  tcase_add_test(tc, s21_greater_18);
  tcase_add_test(tc, s21_greater_19);
  tcase_add_test(tc, s21_greater_20);
  tcase_add_test(tc, s21_greater_21);
  tcase_add_test(tc, s21_greater_22);
  tcase_add_test(tc, s21_greater_23);
  tcase_add_test(tc, s21_greater_24);
  tcase_add_test(tc, s21_greater_25);
  tcase_add_test(tc, s21_greater_26);
  tcase_add_test(tc, s21_greater_27);
  tcase_add_test(tc, s21_greater_28);
  tcase_add_test(tc, s21_greater_29);
  tcase_add_test(tc, s21_greater_30);
  tcase_add_test(tc, s21_greater_31);
  tcase_add_test(tc, s21_greater_32);
  tcase_add_test(tc, s21_greater_33);
  tcase_add_test(tc, s21_greater_34);
  tcase_add_test(tc, s21_greater_35);
  tcase_add_test(tc, s21_greater_36);
  tcase_add_test(tc, s21_greater_37);
  tcase_add_test(tc, s21_greater_38);
  tcase_add_test(tc, s21_greater_39);
  tcase_add_test(tc, s21_greater_40);
  tcase_add_test(tc, s21_greater_or_equal_1);
  tcase_add_test(tc, s21_greater_or_equal_2);
  tcase_add_test(tc, s21_greater_or_equal_3);
  //  tcase_add_test(tc, s21_greater_or_equal_4);
  tcase_add_test(tc, s21_greater_or_equal_5);
  tcase_add_test(tc, s21_greater_or_equal_6);
  tcase_add_test(tc, s21_greater_or_equal_7);
  tcase_add_test(tc, s21_greater_or_equal_8);
  tcase_add_test(tc, s21_greater_or_equal_9);
  tcase_add_test(tc, s21_greater_or_equal_10);
  tcase_add_test(tc, s21_greater_or_equal_11);
  tcase_add_test(tc, s21_greater_or_equal_12);
  tcase_add_test(tc, s21_greater_or_equal_13);
  tcase_add_test(tc, s21_greater_or_equal_14);
  tcase_add_test(tc, s21_greater_or_equal_15);
  tcase_add_test(tc, s21_greater_or_equal_16);
  tcase_add_test(tc, s21_greater_or_equal_17);
  tcase_add_test(tc, s21_greater_or_equal_18);
  tcase_add_test(tc, s21_greater_or_equal_19);
  tcase_add_test(tc, s21_greater_or_equal_20);
  tcase_add_test(tc, s21_greater_or_equal_21);
  tcase_add_test(tc, s21_greater_or_equal_22);
  tcase_add_test(tc, s21_greater_or_equal_23);
  tcase_add_test(tc, s21_greater_or_equal_24);
  tcase_add_test(tc, s21_greater_or_equal_25);
  tcase_add_test(tc, s21_greater_or_equal_26);
  tcase_add_test(tc, s21_greater_or_equal_27);
  tcase_add_test(tc, s21_greater_or_equal_28);
  tcase_add_test(tc, s21_greater_or_equal_29);
  tcase_add_test(tc, s21_greater_or_equal_30);
  tcase_add_test(tc, s21_greater_or_equal_31);
  tcase_add_test(tc, s21_greater_or_equal_32);
  tcase_add_test(tc, s21_greater_or_equal_33);
  tcase_add_test(tc, s21_greater_or_equal_34);
  tcase_add_test(tc, s21_greater_or_equal_35);
  tcase_add_test(tc, s21_greater_or_equal_36);
  tcase_add_test(tc, s21_greater_or_equal_37);
  tcase_add_test(tc, s21_greater_or_equal_38);
  tcase_add_test(tc, s21_greater_or_equal_39);
  tcase_add_test(tc, s21_greater_or_equal_40);

  suite_add_tcase(s, tc);
  return s;
}
