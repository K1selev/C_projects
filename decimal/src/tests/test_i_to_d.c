#include "s21_decimal_tst.h"

START_TEST(int_to_dec_1) {
  s21_decimal decimal = {{0, 0, 0, 0}};
  int i = -3000, res = 0;
  s21_from_int_to_decimal(i, &decimal);
  s21_from_decimal_to_int(decimal, &res);
  ck_assert_int_eq(i, res);
}
END_TEST

START_TEST(int_to_dec_2) {
  s21_decimal x = {{0, 0, 0, 0}};
  s21_decimal y = {{15, 0, 0, 0}};
  int z = 15;
  s21_from_int_to_decimal(z, &x);
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", x.bits[0], x.bits[1],
           x.bits[2], x.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u", y.bits[0], y.bits[1],
           y.bits[2], y.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(int_to_dec_3) {
  s21_decimal x = {{0, 0, 0, 0}};
  s21_decimal y = {{15, 0, 0, 2147483648}};
  int z = -15;
  s21_from_int_to_decimal(z, &x);
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", x.bits[0], x.bits[1],
           x.bits[2], x.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u", y.bits[0], y.bits[1],
           y.bits[2], y.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(int_to_dec_4) {
  s21_decimal x = {{0, 0, 0, 0}};
  s21_decimal y = {{0, 0, 0, 0}};
  int z = 0;
  s21_from_int_to_decimal(z, &x);
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", x.bits[0], x.bits[1],
           x.bits[2], x.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u", y.bits[0], y.bits[1],
           y.bits[2], y.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

// START_TEST(int_to_dec_5) {
//   int src = 124;
//   int error = 0;
//   error = s21_from_int_to_decimal(src, NULL);
//   ck_assert_int_eq(error, 1);
// }
// END_TEST

START_TEST(int_to_dec_6) {
  s21_decimal result, origin;
  int src = 1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_7) {
  s21_decimal result, origin;
  int src = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_8) {
  s21_decimal result, origin;
  int src = -1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_9) {
  s21_decimal result, origin;
  int src = 2147483647;
  origin.bits[0] = 0b01111111111111111111111111111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_10) {
  s21_decimal result, origin;
  int src = -2147483647;
  origin.bits[0] = 0b01111111111111111111111111111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_11) {
  s21_decimal result, origin;
  int src = -12345;
  origin.bits[0] = 0b00000000000000000011000000111001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_12) {
  s21_decimal result, origin;
  int src = -12345;
  origin.bits[0] = 0b00000000000000000011000000111001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_13) {
  s21_decimal result, origin;
  int src = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_14) {
  s21_decimal result, origin;
  int src = 45678;
  origin.bits[0] = 0b00000000000000001011001001101110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_15) {
  s21_decimal result, origin;
  int src = -45678;
  origin.bits[0] = 0b00000000000000001011001001101110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_16) {
  s21_decimal result, origin;
  int src = 5555555;
  origin.bits[0] = 0b00000000010101001100010101100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_17) {
  s21_decimal result, origin;
  int src = -5555555;
  origin.bits[0] = 0b00000000010101001100010101100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_18) {
  s21_decimal result, origin;
  int src = 127;
  origin.bits[0] = 0b00000000000000000000000001111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_19) {
  s21_decimal result, origin;
  int src = -127;
  origin.bits[0] = 0b00000000000000000000000001111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_20) {
  s21_decimal result, origin;
  int src = 34567898;
  origin.bits[0] = 0b00000010000011110111011011011010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_21) {
  s21_decimal result, origin;
  int src = -34567898;
  origin.bits[0] = 0b00000010000011110111011011011010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_22) {
  s21_decimal result, origin;
  int src = 999;
  origin.bits[0] = 0b00000000000000000000001111100111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_23) {
  s21_decimal result, origin;
  int src = -999;
  origin.bits[0] = 0b00000000000000000000001111100111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_24) {
  s21_decimal result, origin;
  int src = -3254754;
  origin.bits[0] = 0b00000000001100011010100111100010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_25) {
  s21_decimal result, origin;
  int src = 3436425;
  origin.bits[0] = 0b00000000001101000110111110001001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_26) {
  s21_decimal result, origin;
  int src = 222222222;
  origin.bits[0] = 0b00001101001111101101011110001110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_t_dec_1) {
  s21_decimal result, origin;
  int src = 1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_t_dec_2) {
  s21_decimal result, origin;
  int src = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_t_dec_3) {
  s21_decimal result, origin;
  int src = -1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_t_dec_4) {
  s21_decimal result, origin;
  int src = 2147483647;
  origin.bits[0] = 0b01111111111111111111111111111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_t_dec_5) {
  s21_decimal result, origin;
  int src = -2147483647;
  origin.bits[0] = 0b01111111111111111111111111111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_t_dec_6) {
  s21_decimal result, origin;
  int src = -12345;
  origin.bits[0] = 0b00000000000000000011000000111001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_t_dec_7) {
  s21_decimal result, origin;
  int src = -12345;
  origin.bits[0] = 0b00000000000000000011000000111001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_t_dec_8) {
  s21_decimal result, origin;
  int src = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_t_dec_9) {
  s21_decimal result, origin;
  int src = 45678;
  origin.bits[0] = 0b00000000000000001011001001101110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_t_dec_10) {
  s21_decimal result, origin;
  int src = -45678;
  origin.bits[0] = 0b00000000000000001011001001101110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_t_dec_11) {
  s21_decimal result, origin;
  int src = 5555555;
  origin.bits[0] = 0b00000000010101001100010101100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_t_dec_12) {
  s21_decimal result, origin;
  int src = -5555555;
  origin.bits[0] = 0b00000000010101001100010101100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_t_dec_13) {
  s21_decimal result, origin;
  int src = 127;
  origin.bits[0] = 0b00000000000000000000000001111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_t_dec_14) {
  s21_decimal result, origin;
  int src = -127;
  origin.bits[0] = 0b00000000000000000000000001111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_t_dec_15) {
  s21_decimal result, origin;
  int src = 34567898;
  origin.bits[0] = 0b00000010000011110111011011011010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_t_dec_16) {
  s21_decimal result, origin;
  int src = -34567898;
  origin.bits[0] = 0b00000010000011110111011011011010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_t_dec_17) {
  s21_decimal result, origin;
  int src = 999;
  origin.bits[0] = 0b00000000000000000000001111100111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_t_dec_18) {
  s21_decimal result, origin;
  int src = -999;
  origin.bits[0] = 0b00000000000000000000001111100111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_t_dec_19) {
  s21_decimal result, origin;
  int src = -3254754;
  origin.bits[0] = 0b00000000001100011010100111100010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_t_dec_20) {
  s21_decimal result, origin;
  int src = 3436425;
  origin.bits[0] = 0b00000000001101000110111110001001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_t_dec_21) {
  s21_decimal result, origin;
  int src = 222222222;
  origin.bits[0] = 0b00001101001111101101011110001110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

Suite *suite_itod(void) {
  Suite *s = suite_create("int_to_decimal");
  TCase *tc = tcase_create("insert_tc");

  tcase_add_test(tc, int_to_dec_1);
  tcase_add_test(tc, int_to_dec_2);
  tcase_add_test(tc, int_to_dec_3);
  tcase_add_test(tc, int_to_dec_4);
  // tcase_add_test(tc, int_to_dec_5);
  tcase_add_test(tc, int_to_dec_6);
  tcase_add_test(tc, int_to_dec_7);
  tcase_add_test(tc, int_to_dec_8);
  tcase_add_test(tc, int_to_dec_9);
  tcase_add_test(tc, int_to_dec_10);
  tcase_add_test(tc, int_to_dec_11);
  tcase_add_test(tc, int_to_dec_12);
  tcase_add_test(tc, int_to_dec_13);
  tcase_add_test(tc, int_to_dec_14);
  tcase_add_test(tc, int_to_dec_15);
  tcase_add_test(tc, int_to_dec_16);
  tcase_add_test(tc, int_to_dec_17);
  tcase_add_test(tc, int_to_dec_18);
  tcase_add_test(tc, int_to_dec_19);
  tcase_add_test(tc, int_to_dec_20);
  tcase_add_test(tc, int_to_dec_21);
  tcase_add_test(tc, int_to_dec_22);
  tcase_add_test(tc, int_to_dec_23);
  tcase_add_test(tc, int_to_dec_24);
  tcase_add_test(tc, int_to_dec_25);
  tcase_add_test(tc, int_to_dec_26);

  tcase_add_test(tc, int_t_dec_1);
  tcase_add_test(tc, int_t_dec_2);
  tcase_add_test(tc, int_t_dec_3);
  tcase_add_test(tc, int_t_dec_4);
  tcase_add_test(tc, int_t_dec_5);
  tcase_add_test(tc, int_t_dec_6);
  tcase_add_test(tc, int_t_dec_7);
  tcase_add_test(tc, int_t_dec_8);
  tcase_add_test(tc, int_t_dec_9);
  tcase_add_test(tc, int_t_dec_10);
  tcase_add_test(tc, int_t_dec_11);
  tcase_add_test(tc, int_t_dec_12);
  tcase_add_test(tc, int_t_dec_13);
  tcase_add_test(tc, int_t_dec_14);
  tcase_add_test(tc, int_t_dec_15);
  tcase_add_test(tc, int_t_dec_16);
  tcase_add_test(tc, int_t_dec_17);
  tcase_add_test(tc, int_t_dec_18);
  tcase_add_test(tc, int_t_dec_19);
  tcase_add_test(tc, int_t_dec_20);
  tcase_add_test(tc, int_t_dec_21);

  suite_add_tcase(s, tc);
  return s;
}
//
// int main(void) {
//  /* We create variable no_failed to store the number of failed tests: */
//  int no_failed = 0;
//  /* We declare s as a pointer to a Suite and call on function in order to
//   * create and return our test suite: */
//  Suite *s = suite_insert();
//  /* We pass our newly created test suite to the function srunner_create in
//   * order to get a pointer to a test suite runner */
//  SRunner *sr = srunner_create(s);
//  /* This function will run our test suite and check our assertions,
//  CK_VERBOSE
//   * used to show all tests,  use CK_NORMAL instead to see only failed ones:
//   */
//  srunner_run_all(sr, CK_NORMAL);
//  /* To extract the number of failed tests: */
//  no_failed = srunner_ntests_failed(sr);
//  /* We free any memory that was allocated due to our runner: */
//  srunner_free(sr);
//  /* We return if the number of failed tests is 0 else we fail the test run */
//  return no_failed == 0 ? 0 : 1;
//
//  /*  for mor information check
//  https://www.ccs.neu.edu/home/skotthe/classes/cs5600/fall/2015/labs/intro-check.html
//  or https://check.sourceforge.net/doc/doxygen/html/check_8h.html  */
//}
