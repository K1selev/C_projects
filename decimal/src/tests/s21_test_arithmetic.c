#include "s21_decimal_tst.h"

START_TEST(s21_add_1) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
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
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_2) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 3;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_3) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_4) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_6) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_7) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 6521;
  // src2 = 74121;
  src1.bits[0] = 0b00000000000000000001100101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000010010000110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000010011101100000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_8) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 4;
  // src2 = 97623323;
  src1.bits[0] = 0b00000000000000000000000000000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000101110100011001110100011011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000101110100011001110100011111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_9) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 65658654;
  // src2 = 5;
  src1.bits[0] = 0b00000011111010011101111100011110;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000011111010011101111100100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_10) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
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
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000001011001000011001011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_11) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1;
  // src2 = 98745654321;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111101101100110001110000110001;
  src2.bits[1] = 0b00000000000000000000000000010110;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111101101100110001110000110010;
  origin.bits[1] = 0b00000000000000000000000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_12) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -9878798789;
  // src2 = -3;
  src1.bits[0] = 0b01001100110100101000000111000101;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01001100110100101000000111001000;
  origin.bits[1] = 0b00000000000000000000000000000010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_13) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
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
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10001001111010000000000000000000;
  origin.bits[1] = 0b10001010110001110010001100000100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_14) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 18446744073709551615;
  // src2 = 1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000001;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

// START_TEST(s21_add_15) {
//   s21_decimal src1, src2, origin, result;
//   int value_type_result, value_type_origin;
//   // src1 = 18446744073709551615.0;
//   // src2 = 965453154;
//   src1.bits[0] = 0b11111111111111111111111111110110;
//   src1.bits[1] = 0b11111111111111111111111111111111;
//   src1.bits[2] = 0b00000000000000000000000000001001;
//   src1.bits[3] = 0b00000000000000010000000000000000;
//   src2.bits[0] = 0b00111001100010111010010101100010;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000000000000000000000;
//   value_type_result = s21_add(src1, src2, &result);
//   value_type_origin = 0;
//   origin.bits[0] = 0b00111111011101000111010111001010;
//   origin.bits[1] = 0b00000000000000000000000000000010;
//   origin.bits[2] = 0b00000000000000000000000000001010;
//   origin.bits[3] = 0b00000000000000010000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
//   ck_assert_int_eq(value_type_result, value_type_origin);
// }
// END_TEST

START_TEST(s21_add_16) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = 54564654;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b00000011010000001001011100101110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01110001001010101101101011101101;
  origin.bits[1] = 0b00101110001111001110000111111000;
  origin.bits[2] = 0b10110000001111101110111101101101;
  origin.bits[3] = 0b10000000000011100000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_18) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 0;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01001110111001000011100101110110;
  origin.bits[1] = 0b01001011001101011010000111011001;
  origin.bits[2] = 0b00011001101110010111010010111111;
  origin.bits[3] = 0b00000000000011110000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_23) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_24) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_25) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_27) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7922816251427554395;
  // src2 = 65645646;
  src1.bits[0] = 0b01011111000010000000010001011011;
  src1.bits[1] = 0b01101101111100110111111101100111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000011111010011010110001001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01100010111100011011000010101001;
  origin.bits[1] = 0b01101101111100110111111101100111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_28) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
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
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00110111111111010001010100111010;
  origin.bits[1] = 0b00000000000111110100000111110010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_29) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2.7986531268974139743;
  // src2 = 9.979623121254565121244554;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11010100101011100011110110001010;
  src2.bits[1] = 0b01110100000101000010011110100011;
  src2.bits[2] = 0b00000000000010000100000101000100;
  src2.bits[3] = 0b00000000000110000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10011010010111001101001011101010;
  origin.bits[1] = 0b10111110010100100100110100010011;
  origin.bits[2] = 0b00000000000010101001000111100111;
  origin.bits[3] = 0b00000000000110000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_30) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -9798956154578676.797564534156;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b01010100010000000011110110001100;
  src1.bits[1] = 0b10001011010100100000010101011001;
  src1.bits[2] = 0b00011111101010011000000110101101;
  src1.bits[3] = 0b10000000000011000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11010101111011100000000010001100;
  origin.bits[1] = 0b01111000000001011001100110101101;
  origin.bits[2] = 0b00011111101010011000001000100010;
  origin.bits[3] = 0b10000000000011000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_31) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 0.68985125146545154;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b00010111001001010100110000000010;
  src2.bits[1] = 0b00000000111101010001010110011011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01110000110111010100000010001101;
  origin.bits[1] = 0b01011010100111011110001100001010;
  origin.bits[2] = 0b00100111111010111100110001011010;
  origin.bits[3] = 0b00000000000111000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_36) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = -37986322154988653.784354545765;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01001111101101000110000001100101;
  src2.bits[1] = 0b01000010001101101011011001100001;
  src2.bits[2] = 0b01111010101111011000110010011010;
  src2.bits[3] = 0b10000000000011000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01001111101101000110000001100101;
  origin.bits[1] = 0b01000010001101101011011001100001;
  origin.bits[2] = 0b01111010101111011000110010011010;
  origin.bits[3] = 0b10000000000011000000000000000000;
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_40) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_44) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 546378;
  // src2 = 0;
  src1.bits[0] = 0b00000000000010000101011001001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000010000101011001001010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_45) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 8976545415646545.5746845454;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11011101111000010000101100001110;
  src2.bits[1] = 0b00000101010000010110101000000010;
  src2.bits[2] = 0b00000000010010100100000010010011;
  src2.bits[3] = 0b00000000000010100000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11011101111000010000101100001110;
  origin.bits[1] = 0b00000101010000010110101000000010;
  origin.bits[2] = 0b00000000010010100100000010010011;
  origin.bits[3] = 0b00000000000010100000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_51) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_52) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(add1) {
  s21_decimal var1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0, 0}};
  s21_decimal var2 = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_add(var1, var2, &result);
  s21_decimal answer = {{0x1, 0x0, 0x1, 0}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(add2) {
  s21_decimal var1 = {{4294967294, 4294967295, 4294967295, 0}};
  s21_decimal var2 = {{1, 0, 0, 1835008}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_add(var1, var2, &result);
  s21_decimal answer = {{4294967294, 4294967295, 4294967295, 0}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(add3) {
  s21_decimal var1 = {{456789, 0, 0, 0}};
  s21_decimal var2 = {{123456, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_add(var1, var2, &result);
  s21_decimal answer = {{580245, 0, 0, 0}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(add4) {
  s21_decimal var1 = {{3210, 0, 0, NEGATIVE}};
  s21_decimal var2 = {{1234, 0, 0, NEGATIVE}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_add(var1, var2, &result);
  s21_decimal answer = {{4444, 0, 0, NEGATIVE}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(add5) {
  s21_decimal var1 = {{3210, 0, 0, NEGATIVE}};
  s21_decimal var2 = {{1234, 0, 0, NEGATIVE}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_add(var1, var2, &result);
  s21_decimal answer = {{4444, 0, 0, NEGATIVE}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(add6) {
  s21_decimal var1 = {{4294967294, 4294967295, 0, 0}};
  s21_decimal var2 = {{1, 4294967295, 4294967294, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_add(var1, var2, &result);
  s21_decimal answer = {{4294967295, 4294967294, 4294967295, 0}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(add7) {
  s21_decimal var1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal var2 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_add(var1, var2, &result);
  ck_assert_int_eq(1, returned_var);
}
END_TEST

START_TEST(add8) {
  s21_decimal var1 = {{613478421, 0, 0, 196608}};
  s21_decimal var2 = {{2056771366, 613, 0, 393216}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_add(var1, var2, &result);
  s21_decimal answer = {{1354869038, 756, 0, 393216}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(add9) {
  s21_decimal var1 = {{613478421, 0, 0, 196608}};
  s21_decimal var2 = {{0, 0, 0, 393216}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_add(var1, var2, &result);
  s21_decimal answer = {{613478421, 0, 0, 196608}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(add10) {
  s21_decimal var1 = {{23784103, 0, 0, 0}};
  s21_decimal var2 = {{721398, 0, 0, NEGATIVE}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_add(var1, var2, &result);
  s21_decimal answer = {{23062705, 0, 0, 0}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(add11) {
  s21_decimal x = {{4294967295, 4294967295, 0, 0}};
  s21_decimal y = {{1, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char ourRes[1000], expect[1000] = "0 0 1 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(add12) {
  s21_decimal x = {{20, 1, 0, 2147483648}};
  s21_decimal y = {{21, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char ourRes[1000], expect[1000] = "4294967295 0 0 2147483648";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(add13) {
  s21_decimal x = {{20, 1, 0, 2147483648}};
  s21_decimal y = {{21, 0, 0, 2147483648}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char ourRes[1000], expect[1000] = "41 1 0 2147483648";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(add14) {
  s21_decimal x = {{20, 1, 0, 0}};
  s21_decimal y = {{21, 0, 0, 2147483648}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char ourRes[1000], expect[1000] = "4294967295 0 0 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(add15) {
  s21_decimal x = {{20, 0, 0, 2147483648}};
  s21_decimal y = {{21, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char ourRes[1000], expect[1000] = "1 0 0 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(add16) {
  s21_decimal x = {{25, 1, 0, 2147483648}};
  s21_decimal y = {{21, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char ourRes[1000], expect[1000] = "4 1 0 2147483648";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(add17) {
  s21_decimal x = {{100, 0, 0, 2147483648}};
  s21_decimal y = {{100, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char ourRes[1000], expect[1000] = "0 0 0 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(add18) {
  s21_decimal x = {{99, 0, 0, 0}};
  s21_decimal y = {{100, 0, 0, 2147483648}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char ourRes[1000], expect[1000] = "1 0 0 2147483648";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(add20) {
  s21_decimal x = {{0, 0, 3000000000, 0}};
  s21_decimal y = {{0, 0, 3000000000, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  int err = s21_add(x, y, &z);
  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(add22) {
  s21_decimal x = {{1, 1, 1, 65536}};
  s21_decimal y = {{1, 1, 1, 65536}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char ourRes[1000], expect[1000] = "2 2 2 65536";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(add23) {
  s21_decimal x = {{1, 1, 1, 65536}};
  s21_decimal y = {{1, 1, 1, 655360}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char ourRes[1000], expect[1000] = "1000000001 1000000001 1000000001 655360";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(add24) {
  s21_decimal x = {{24, 1, 1, -2147418112}};
  s21_decimal y = {{1, 15, 1, 655360}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char ourRes[1000], expect[1000] = "2525163519 999999990 999999999 2148139008";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(add25) {
  s21_decimal x = {{1, 1, 1, 655360}};
  s21_decimal y = {{1, 1, 1, -2147418112}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char ourRes[1000], expect[1000] = "999999999 999999999 999999999 2148139008";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(add26) {
  s21_decimal value_1 = {{4286807631U, 65535, 0, 2147680256U}};
  s21_decimal value_2 = {{4286807631U, 4095, 0, 458752}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal answer = {{15888289, 655355885, 0, 2147942400U}};
  ck_assert_int_eq(0, s21_add(value_1, value_2, &result));
  ck_assert_int_eq(1, s21_is_equal(result, answer));
}
END_TEST

START_TEST(add27) {
  s21_decimal value_1 = {{1614, 0, 0, 0}};
  s21_decimal value_2 = {{46071, 20, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal answer = {{47685, 20, 0, 0}};
  ck_assert_int_eq(0, s21_add(value_1, value_2, &result));
  ck_assert_int_eq(1, s21_is_equal(result, answer));
}
END_TEST

START_TEST(add28) {
  s21_decimal value_1 = {{13, 0, 0, 0}};
  s21_decimal value_2 = {{286, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal answer = {{299, 0, 0, 0}};
  ck_assert_int_eq(0, s21_add(value_1, value_2, &result));
  ck_assert_int_eq(1, s21_is_equal(result, answer));
}
END_TEST

START_TEST(add29) {
  s21_decimal value_1 = {{13, 0, 0, 0}};
  s21_decimal value_2 = {{286, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal answer = {{299, 0, 0, 0}};
  ck_assert_int_eq(0, s21_add(value_1, value_2, &result));
  ck_assert_int_eq(1, s21_is_equal(result, answer));
}
END_TEST

START_TEST(add30) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal answer = {{0, 0, 0, 0}};
  ck_assert_int_eq(1, s21_add(value_1, value_2, &result));
  ck_assert_int_eq(1, s21_is_equal(result, answer));
}
END_TEST

START_TEST(s21_sub_1) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 5;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_2) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 3;
  // src2 = 6;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_3) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 8;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000001000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_4) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_6) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 3;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_7) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 787891;
  // src2 = 238471;
  src1.bits[0] = 0b00000000000011000000010110110011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000111010001110000111;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000010000110001000101100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_8) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 9;
  // src2 = 18571145;
  src1.bits[0] = 0b00000000000000000000000000001001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000001000110110101111110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000001000110110101111110000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_9) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1849687;
  // src2 = 6;
  src1.bits[0] = 0b00000000000111000011100101010111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000111000011100101010001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_10) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -3187878;
  // src2 = 1;
  src1.bits[0] = 0b00000000001100001010010010100110;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000001100001010010010100111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_11) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1;
  // src2 = 18768768;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000001000111100110001110000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000001000111100110001101111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

// START_TEST(s21_sub_15) {
//   s21_decimal src1, src2, origin, result;
//   int value_type_result, value_type_origin;
//   // src1 = 18446744073709551615.0;
//   // src2 = 3556877454;
//   src1.bits[0] = 0b11111111111111111111111111110110;
//   src1.bits[1] = 0b11111111111111111111111111111111;
//   src1.bits[2] = 0b00000000000000000000000000001001;
//   src1.bits[3] = 0b00000000000000010000000000000000;
//   src2.bits[0] = 0b11010100000000011010010010001110;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000000000000000000000;
//   value_type_result = s21_sub(src1, src2, &result);
//   value_type_origin = 0;
//   origin.bits[0] = 0b10110111111011111001001001101010;
//   origin.bits[1] = 0b11111111111111111111111111110111;
//   origin.bits[2] = 0b00000000000000000000000000001001;
//   origin.bits[3] = 0b00000000000000010000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
//   ck_assert_int_eq(value_type_result, value_type_origin);
// }
// END_TEST

START_TEST(s21_sub_16) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -54896651557845.352654545456455;
  // src2 = 21465;
  src1.bits[0] = 0b01110001100100011000110101000111;
  src1.bits[1] = 0b00001111010011100000001101011111;
  src1.bits[2] = 0b10110001011000010111001000100100;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b00000000000000000101001111011001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01111001010101000000110101000111;
  origin.bits[1] = 0b00111001001100010000001100100101;
  origin.bits[2] = 0b10110001011000010111001000100101;
  origin.bits[3] = 0b10000000000011110000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_17) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 0;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01001110111001000011100101110110;
  origin.bits[1] = 0b01001011001101011010000111011001;
  origin.bits[2] = 0b00011001101110010111010010111111;
  origin.bits[3] = 0b00000000000011110000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_22) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_23) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_24) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_26) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7922816251427554395;
  // src2 = 65645646;
  src1.bits[0] = 0b01011111000010000000010001011011;
  src1.bits[1] = 0b01101101111100110111111101100111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000011111010011010110001001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01011011000111100101100000001101;
  origin.bits[1] = 0b01101101111100110111111101100111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_28) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2.7986531268974139743;
  // src2 = 9.979623121254565121244554;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11010100101011100011110110001010;
  src2.bits[1] = 0b01110100000101000010011110100011;
  src2.bits[2] = 0b00000000000010000100000101000100;
  src2.bits[3] = 0b00000000000110000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00001110111111111010100000101010;
  origin.bits[1] = 0b00101001110101100000001000110100;
  origin.bits[2] = 0b00000000000001011111000010100001;
  origin.bits[3] = 0b10000000000110000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_30) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 0.68985125146545154;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b00010111001001010100110000000010;
  src2.bits[1] = 0b00000000111101010001010110011011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01011010101111100101111101110011;
  origin.bits[1] = 0b00101101001111010011000001101000;
  origin.bits[2] = 0b00000100101010001101010101010111;
  origin.bits[3] = 0b10000000000111000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_35) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = -37986322154988653.784354545765;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01001111101101000110000001100101;
  src2.bits[1] = 0b01000010001101101011011001100001;
  src2.bits[2] = 0b01111010101111011000110010011010;
  src2.bits[3] = 0b10000000000011000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01001111101101000110000001100101;
  origin.bits[1] = 0b01000010001101101011011001100001;
  origin.bits[2] = 0b01111010101111011000110010011010;
  origin.bits[3] = 0b00000000000011000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_36) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 79228162513351883030198514100;
  // src2 = -912454563345436235;
  src1.bits[0] = 0b10110110000111000111000110110100;
  src1.bits[1] = 0b11110011010101100100111101101000;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01001001111000111000111001001011;
  src2.bits[1] = 0b00001100101010011011000010010111;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_39) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
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
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_51) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_52) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 1;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_53) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(sub1) {
  s21_decimal var1 = {{932169, 0, 0, 0}};
  s21_decimal var2 = {{123456}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_sub(var1, var2, &result);
  s21_decimal answer = {{808713, 0, 0, 0}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(sub2) {
  s21_decimal var1 = {{123456, 0, 0, 0}};
  s21_decimal var2 = {{932169, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_sub(var1, var2, &result);
  s21_decimal answer = {{808713, 0, 0, NEGATIVE}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(sub3) {
  s21_decimal var1 = {{987654, 0, 0, NEGATIVE}};
  s21_decimal var2 = {{123456, 0, 0, NEGATIVE}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_sub(var1, var2, &result);
  s21_decimal answer = {{864198, 0, 0, NEGATIVE}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(sub4) {
  s21_decimal var1 = {{123456, 0, 0, NEGATIVE}};
  s21_decimal var2 = {{987654, 0, 0, NEGATIVE}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_sub(var1, var2, &result);
  s21_decimal answer = {{864198, 0, 0, 0}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(sub5) {
  s21_decimal var1 = {{456123, 0, 0, 0}};
  s21_decimal var2 = {{123456, 0, 0, NEGATIVE}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_sub(var1, var2, &result);
  s21_decimal answer = {{579579, 0, 0, 0}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(sub6) {
  s21_decimal x = {{1, 0, 0, 0}};
  s21_decimal y = {{1, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char ourRes[1000], expect[1000] = "0 0 0 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(sub7) {
  s21_decimal x = {{2, 0, 0, 0}};
  s21_decimal y = {{1, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char ourRes[1000], expect[1000] = "1 0 0 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(sub8) {
  s21_decimal x = {{1, 0, 0, 0}};
  s21_decimal y = {{2, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char ourRes[1000], expect[1000] = "1 0 0 2147483648";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(sub9) {
  s21_decimal x = {{2, 0, 0, 2147483648}};
  s21_decimal y = {{2, 0, 0, 2147483648}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char ourRes[1000], expect[1000] = "0 0 0 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(sub10) {
  s21_decimal x = {{1, 0, 0, 2147483648}};
  s21_decimal y = {{2, 0, 0, 2147483648}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char ourRes[1000], expect[1000] = "1 0 0 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(sub11) {
  s21_decimal x = {{2, 0, 0, 2147483648}};
  s21_decimal y = {{1, 0, 0, 2147483648}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char ourRes[1000], expect[1000] = "1 0 0 2147483648";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(sub12) {
  s21_decimal x = {{2, 0, 0, 0}};
  s21_decimal y = {{1, 0, 0, 2147483648}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char ourRes[1000], expect[1000] = "3 0 0 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(sub13) {
  s21_decimal x = {{2, 0, 0, 2147483648}};
  s21_decimal y = {{1, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char ourRes[1000], expect[1000] = "3 0 0 2147483648";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(sub14) {
  s21_decimal x = {{1, 1, 1, 65536}};
  s21_decimal y = {{1, 1, 1, -2147418112}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char ourRes[1000], expect[1000] = "2 2 2 65536";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(sub15) {
  s21_decimal x = {{1, 1, 1, -0}};
  s21_decimal y = {{1, 1, 1, -0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char ourRes[1000], expect[1000] = "0 0 0 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(sub16) {
  s21_decimal x = {{24, 1, 1, -2147418112}};
  s21_decimal y = {{1, 1, 1, 65536}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char ourRes[1000], expect[1000] = "25 2 2 2147549184";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(s21_mul_1) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
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
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_2) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 3;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_3) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_4) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_6) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_7) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 6521;
  // src2 = 74121;
  src1.bits[0] = 0b00000000000000000001100101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000010010000110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00011100110011110011101011000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_8) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 4;
  // src2 = 97623323;
  src1.bits[0] = 0b00000000000000000000000000000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000101110100011001110100011011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00010111010001100111010001101100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_9) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 65658654;
  // src2 = 5;
  src1.bits[0] = 0b00000011111010011101111100011110;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00010011100100010101101110010110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_69) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
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
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000001011001000011001100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_11) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1;
  // src2 = 98745654321;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111101101100110001110000110001;
  src2.bits[1] = 0b00000000000000000000000000010110;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111101101100110001110000110001;
  origin.bits[1] = 0b00000000000000000000000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_12) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -9878798789;
  // src2 = -3;
  src1.bits[0] = 0b01001100110100101000000111000101;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11100110011101111000010101001111;
  origin.bits[1] = 0b00000000000000000000000000000110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_13) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
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
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10001001111001111111111111111111;
  origin.bits[1] = 0b10001010110001110010001100000100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_14) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 18446744073709551615;
  // src2 = 1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_23) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_24) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_25) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_26) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

// START_TEST(s21_mul_27) {
//   s21_decimal src1, src2, origin, result;
//   int value_type_result, value_type_origin;
//   // src1 = 7922816251427554395;
//   // src2 = 65645646;
//   src1.bits[0] = 0b01011111000010000000010001011011;
//   src1.bits[1] = 0b01101101111100110111111101100111;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   src2.bits[0] = 0b00000011111010011010110001001110;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000000000000000000000;        уводит в
//   бесонечный цикл value_type_result = s21_mul(src1, src2, &result);
//   value_type_origin = 0;
//   origin.bits[0] = 0b01011111001100010111011110111010;
//   origin.bits[1] = 0b01000100111111001101101110110001;
//   origin.bits[2] = 0b00000001101011100011011100011110;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
//   ck_assert_int_eq(value_type_result, value_type_origin);
// }
// END_TEST

// START_TEST(s21_mul_28) {
//   s21_decimal src1, src2, origin, result;
//   int value_type_result, value_type_origin;
//   // src1 = 665464545;
//   // src2 = 8798232189789785;
//   src1.bits[0] = 0b00100111101010100010111011100001;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   src2.bits[0] = 0b00010000010100101110011001011001;
//   src2.bits[1] = 0b00000000000111110100000111110010;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000000000000000000000;
//   value_type_result = s21_mul(src1, src2, &result);         уводит в
//   бесконечный цикл value_type_origin = 0; origin.bits[0] =
//   0b11000100010110100111001000111001; origin.bits[1] =
//   0b01100100100011011110110011010011; origin.bits[2] =
//   0b00000000000001001101011111010011; origin.bits[3] =
//   0b00000000000000000000000000000000; ck_assert_int_eq(origin.bits[3],
//   result.bits[3]); ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
//   ck_assert_int_eq(value_type_result, value_type_origin);
// }
// END_TEST

START_TEST(s21_mul_33) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -79228162514264337593543950335;
  // src2 = 1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(mul1) {
  s21_decimal var1 = {{100, 0, 0, 0}};
  s21_decimal var2 = {{2, 0, 0, 0}};
  s21_decimal result = {{200, 0, 0, 0}};
  int returned_var = s21_mul(var1, var2, &result);
  s21_decimal answer = {{200, 0, 0, 0}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(mul2) {
  s21_decimal var1 = {{5346, 0, 0, 0}};
  s21_decimal var2 = {{5346, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_mul(var1, var2, &result);
  s21_decimal answer = {{28579716, 0, 0, 0}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(mul3) {
  s21_decimal var1 = {{12345678, 0, 0, 229376}};
  s21_decimal var2 = {{3, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_mul(var1, var2, &result);
  s21_decimal answer = {{37037034, 0, 0, 229376}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

// START_TEST(mul4) {
//   s21_decimal var1 = {{4294879641, 49999, 0, 917504}};
//   s21_decimal var2 = {{4294879641, 49999, 0, 917504}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   int returned_var = s21_mul(var1, var2, &result);
//   s21_decimal answer = {{3388431729, 4119401889, 2499999997, 1835008}};
//   ck_assert_int_eq(0, returned_var);
//   ck_assert_int_eq(1, s21_is_equal(answer, result));
// }
// END_TEST
//
// START_TEST(mul5) {
//   s21_decimal var1 = {{4294879641, 49999, 0, 2148401152}};
//   s21_decimal var2 = {{4294879641, 49999, 0, 2148401152}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   int returned_var = s21_mul(var1, var2, &result);
//   s21_decimal answer = {{3388431729, 4119401889, 2499999997, 1835008}};
//   ck_assert_int_eq(0, returned_var);
//   ck_assert_int_eq(1, s21_is_equal(answer, result));
// }
// END_TEST

START_TEST(mul6) {
  s21_decimal var1 = {{4294967295, 3551657983, 116415321, 0}};
  s21_decimal var2 = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_mul(var1, var2, &result);
  s21_decimal answer = {{4294967294, 2808348671, 232830643, 0}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(mul7) {
  s21_decimal x = {{2, 0, 0, 0}};
  s21_decimal y = {{5, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char ourRes[1000], expect[1000] = "10 0 0 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(mul8) {
  s21_decimal x = {{2, 1, 2, 0}};
  s21_decimal y = {{5, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char ourRes[1000], expect[1000] = "10 5 10 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(mul9) {
  s21_decimal x = {{2, 0, 0, 0}};
  s21_decimal y = {{0, 0, 10, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char ourRes[1000], expect[1000] = "0 0 20 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(mul10) {
  s21_decimal x = {{1000000000, 0, 0, 0}};
  s21_decimal y = {{6, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char ourRes[1000], expect[1000] = "1705032704 1 0 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(mul11) {
  s21_decimal x = {{1000000000, 0, 0, 2147483648}};
  s21_decimal y = {{6, 0, 0, 2147483648}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char ourRes[1000], expect[1000] = "1705032704 1 0 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(mul12) {
  s21_decimal x = {{1000000000, 0, 0, 2147483648}};
  s21_decimal y = {{6, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char ourRes[1000], expect[1000] = "1705032704 1 0 2147483648";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(mul13) {
  s21_decimal x = {{1, 0, 0, 0}};
  s21_decimal y = {{165, 22, 6587456, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char ourRes[1000], expect[1000] = "165 22 6587456 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

// START_TEST(mul14) {
//   s21_decimal x = {{1, 1, 1, 655360}};
//   s21_decimal y = {{1, 1, 1, 655360}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   s21_mul(x, y, &z);
//   char ourRes[1000], expect[1000] = "1652684285 987621807 1844674408 655360";
//   snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
//            z.bits[2], z.bits[3]);
//   ck_assert_str_eq(ourRes, expect);
// }
// END_TEST

START_TEST(mul15) {
  s21_decimal x = {{1, 0, 0, 655360}};
  s21_decimal y = {{1, 0, 0, 655360}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char ourRes[1000], expect[1000] = "1 0 0 1310720";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(mul16) {
  s21_decimal x = {{1, 0, 0, 655360}};
  s21_decimal y = {{1, 0, 0, -2146828288}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char ourRes[1000], expect[1000] = "1 0 0 2148794368";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(mul17) {
  s21_decimal x = {{1, 0, 1, 917504}};
  s21_decimal y = {{1, 0, 0, -2146828288}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char ourRes[1000], expect[1000] = "1 0 1 2149056512";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(mul_1) {
  s21_decimal value_1 = {{15, 0, 0, 0}};
  s21_decimal value_2 = {{10, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal answer = {{150, 0, 0, 0}};
  s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(mul_2) {
  s21_decimal value_1 = {{0x26687e73, 0, 0, (4 << 16)}};
  s21_decimal value_2 = {{0xd3, 0, 0, (1 << 16)}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal answer = {{0xa82038c9, 0x1f, 0, (5 << 16)}};
  ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(mul_3) {
  s21_decimal value_1 = {{0x1, 0, 0, ((1 << 31) | (14 << 16))}};
  s21_decimal value_2 = {{0x1, 0, 0, ((1 << 31) | (14 << 16))}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal answer = {{0x1, 0, 0, (28 << 16)}};
  ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(mul_4) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0xffffffff, 0, 0, ((1 << 31) | (2 << 16))}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal answer = {{0, 0, 0, ((1 << 31) | (2 << 16))}};
  ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(mul_5) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{0xffffffff, 0, 0, ((1 << 31) | (2 << 16))}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal answer = {{0xffffffff, 0, 0, ((1 << 31) | (2 << 16))}};
  ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

// START_TEST(mul_6) {
//   s21_decimal value_1 = {
//       {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, ((1 << 31) | (28 << 16))}};
//   s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (28 << 16)}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_decimal answer = {
//       {0x96EE456, 0x359A3B3E, 0xCAD2F7F5, ((1 << 31) | (27 << 16))}};
//   ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));
//   ck_assert_int_eq(1, s21_is_equal(answer, result));
// }
// END_TEST
//
// START_TEST(mul_7) {
//   s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
//   s21_decimal value_2 = {{0x17565d3a, 0x1ade5f, 0, 0}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   // s21_decimal answer = {{0xebedb93d, 0x9c7bbf94, 0xb8cffbed, (17 << 16)}};
//
//   ck_assert_int_eq(1, s21_mul(value_1, value_2, &result));
// }
// END_TEST
//
// START_TEST(mul_8) {
//   s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
//   s21_decimal value_2 = {{
//       0x17565d3a,
//       0x1ade5f,
//       0,
//   }};
//   s21_decimal result = {{0, 0, 0, 0}};
//
//   ck_assert_int_eq(2, s21_mul(value_1, value_2, &result));
// }
// END_TEST
//
//  START_TEST(div3) {
//   s21_decimal var1 = {{4294967295, 4294967295, 4294967295, 196608}};
//   s21_decimal var2 = {{4294967295, 4294967295, 4294967295, 196608}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   int returned_var = s21_div(var1, var2, &result);
//   s21_decimal answer = {{1, 0, 0, 0}};
//   ck_assert_int_eq(0, returned_var);
//   ck_assert_int_eq(1, s21_is_equal(answer, result));
// }
//  END_TEST
//
//  START_TEST(div4) {
//   s21_decimal var1 = {{4294967295, 4294967295, 4294967295, 0}};
//   s21_decimal var2 = {{1, 0, 0, 65536}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   int returned_var = s21_div(var1, var2, &result);
//   ck_assert_int_eq(1, returned_var);
// }
//  END_TEST
//
//  START_TEST(div6) {
//   s21_decimal x = {{0xffffffff, 0xffffffff, 0xffffffff, 0}};
//   s21_decimal y = {{2, 0, 0, 28 << 16}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   int err = 0;
//   err = s21_div(x, y, &z);
//   ck_assert_int_eq(err, 1);
// }
//  END_TEST
//
//  START_TEST(div7) {
//   s21_decimal x = {{52525252, 0, 0, 0}};
//   s21_decimal y = {{0, 0, 0, 0}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   int err = 0;
//   err = s21_div(x, y, &z);
//   ck_assert_int_eq(err, 3);
// }
//  END_TEST
//
//  START_TEST(div8) {
//   s21_decimal x = {{52525252, 0, 0, 2147483648}};
//   s21_decimal y = {{0, 0, 0, 0}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   int err = 0;
//   err = s21_div(x, y, &z);
//   ck_assert_int_eq(err, 3);
// }
//  END_TEST
//
//  START_TEST(div9) {
//   s21_decimal x = {{52525252, 0, 0, 0}};
//   s21_decimal y = {{0, 0, 0, 2147483648}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   int err = 0;
//   err = s21_div(x, y, &z);
//   ck_assert_int_eq(err, 3);
// }
//  END_TEST
//
//  START_TEST(div10) {
//   s21_decimal x = {{52525252, 0, 0, 8845}};
//   s21_decimal y = {{0, 0, 0, 10}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   int err = 0;
//   err = s21_div(x, y, &z);
//   ck_assert_int_eq(err, 3);
// }
//  END_TEST
//
//  START_TEST(div11) {
//   s21_decimal x = {{52525252, 0, 0, 65465}};
//   s21_decimal y = {{0, 0, 0, 9598595}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   int err = 0;
//   err = s21_div(x, y, &z);
//   ck_assert_int_eq(err, 3);
// }
//  END_TEST
//
//  START_TEST(div12) {
//   s21_decimal x = {{0xffffffff, 0xffffffff, 0xffffffff, NEGATIVE}};
//   s21_decimal y = {{2, 0, 0, 28 << 16}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   int err = 0;
//   err = s21_div(x, y, &z);
//   ck_assert_int_eq(err, 2);
// }
//  END_TEST
//
//  START_TEST(div13) {
//   s21_decimal x = {{5, 0, 50, NEGATIVE}};
//   s21_decimal y = {{5, 0, 0, NEGATIVE}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   int err = 0;
//   err = s21_div(x, y, &z);
//   ck_assert_int_eq(err, 0);
// }
//  END_TEST
//
//  START_TEST(div14) {
//   s21_decimal x = {{1, 1, 1, 655360}};
//   s21_decimal y = {{1, 1, 1, 655360}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   s21_div(x, y, &z);
//   char ourRes[1000], expect[1000] = "1 0 0 0";
//   snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
//            z.bits[2], z.bits[3]);
//   ck_assert_str_eq(ourRes, expect);
// }
//  END_TEST
//
//  START_TEST(div15) {
//   s21_decimal x = {{1, 1, 1, 655360}};
//   s21_decimal y = {{1, 1, 1, 983040}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   s21_div(x, y, &z);
//   char ourRes[1000], expect[1000] = "100000 0 0 0";
//   snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
//            z.bits[2], z.bits[3]);
//   ck_assert_str_eq(ourRes, expect);
// }
//  END_TEST
//
//  START_TEST(div16) {
//   s21_decimal x = {{1, 1, 1, 10 << 16}};
//   s21_decimal y = {{1, 10, 1, NEGATIVE + (15 << 16)}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   s21_div(x, y, &z);
//   char ourRes[1000], expect[1000] = "1019311944 458670364 542101085
//   2148990976"; snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u",
//   z.bits[0], z.bits[1],
//            z.bits[2], z.bits[3]);
//   ck_assert_str_eq(ourRes, expect);
// }
//  END_TEST
//
//  START_TEST(div17) {
//   s21_decimal x = {{1, 1, 1, 983040}};
//   s21_decimal y = {{1, 1, 1, -2146500608}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   s21_div(x, y, &z);
//   char ourRes[1000], expect[1000] = "1 0 0 2147483648";
//   snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
//            z.bits[2], z.bits[3]);
//   ck_assert_str_eq(ourRes, expect);
// }
//  END_TEST
//
//  START_TEST(div_1_test) {
//   s21_decimal num1 = {{10, 0, 0, 0}};
//   s21_decimal num2 = {{2, 0, 0, 0}};
//   s21_decimal res = {{0, 0, 0, 0}};
//   int status = s21_div(num1, num2, &res);
//   ck_assert_int_eq(status, 0);
//   ck_assert_int_eq(res.bits[0], 5);
//   ck_assert_int_eq(res.bits[1], 0);
//   ck_assert_int_eq(res.bits[2], 0);
//   ck_assert_int_eq(res.bits[3], 0);
// }
//  END_TEST
//
//  START_TEST(div_2_test) {
//   s21_decimal num1 = {{10, 0, 0, 0}};
//   s21_decimal num2 = {{4, 0, 0, -2147483648}};
//   s21_decimal res = {{0, 0, 0, 0}};
//   int status = s21_div(num1, num2, &res);
//   ck_assert_int_eq(status, 0);
//   ck_assert_int_eq(res.bits[0], 25);
//   ck_assert_int_eq(res.bits[1], 0);
//   ck_assert_int_eq(res.bits[2], 0);
//   ck_assert_int_eq((int)res.bits[3], -2147418112);
// }
//  END_TEST
//
//  START_TEST(div_3_test) {
//   s21_decimal num1 = {{10, 0, 0, 0}};
//   s21_decimal num2 = {{3, 0, 0, 0}};
//   s21_decimal res = {{0, 0, 0, 0}};
//   int status = s21_div(num1, num2, &res);
//   ck_assert_int_eq(status, 0);
//   ck_assert_int_eq(res.bits[0], 894784853);
//   ck_assert_int_eq((int)res.bits[1], -819591186);
//   ck_assert_int_eq(res.bits[2], 1807003620);
//   ck_assert_int_eq(res.bits[3], 1835008);
// }
//  END_TEST
//
//  START_TEST(div_4_test) {
//   s21_decimal num1 = {{10, 0, 0, 0}};
//   s21_decimal num2 = {{22, 0, 0, 65536}};
//   s21_decimal res = {{0, 0, 0, 0}};
//   int status = s21_div(num1, num2, &res);
//   ck_assert_int_eq(status, 0);
//   ck_assert_int_eq(res.bits[0], 48806447);
//   ck_assert_int_eq((int)res.bits[1], -1898527489);
//   ck_assert_int_eq((int)res.bits[2], -1830871450);
//   ck_assert_int_eq(res.bits[3], 1835008);
// }
//  END_TEST
//
//  START_TEST(div_5_test) {
//   s21_decimal num1 = {{10, 0, 0, 0}};
//   s21_decimal num2 = {{1, 0, 0, 393216}};
//   s21_decimal res = {{0, 0, 0, 0}};
//   int status = s21_div(num1, num2, &res);
//   ck_assert_int_eq(status, 0);
//   ck_assert_int_eq(res.bits[0], 10000000);
//   ck_assert_int_eq(res.bits[1], 0);
//   ck_assert_int_eq(res.bits[2], 0);
//   ck_assert_int_eq(res.bits[3], 0);
// }
//  END_TEST
//
//  START_TEST(div_6_test) {
//   s21_decimal num1 = {{10, 0, 0, 0}};
//   s21_decimal num2 = {{6, 0, 0, 1835008}};
//   s21_decimal res = {{0, 0, 0, 0}};
//   int status = s21_div(num1, num2, &res);
//   ck_assert_int_eq(status, 0);
//   ck_assert_int_eq(res.bits[0], 447392427);
//   ck_assert_int_eq(res.bits[1], 1737688055);
//   ck_assert_int_eq(res.bits[2], 903501810);
//   ck_assert_int_eq(res.bits[3], 0);
// }
//  END_TEST
//
//  START_TEST(div_7_test) {
//   s21_decimal num1 = {{10, 0, 0, 0}};
//   s21_decimal num2 = {{658067456, 1164, 0, 0}};
//   s21_decimal res = {{0, 0, 0, 0}};
//   int status = s21_div(num1, num2, &res);
//   ck_assert_int_eq(status, 0);
//   ck_assert_int_eq(res.bits[0], 2);
//   ck_assert_int_eq(res.bits[1], 0);
//   ck_assert_int_eq(res.bits[2], 0);
//   ck_assert_int_eq(res.bits[3], 786432);
// }
//  END_TEST
//
//  START_TEST(div_8_test) {
//   s21_decimal num1 = {{10, 0, 0, 0}};
//   s21_decimal num2 = {{1879048192, -1291644761, -500259693, 0}};
//   s21_decimal res = {{0, 0, 0, 0}};
//   int status = s21_div(num1, num2, &res);
//   ck_assert_int_eq(status, 0);
//   ck_assert_int_eq(res.bits[0], 1);
//   ck_assert_int_eq(res.bits[1], 0);
//   ck_assert_int_eq(res.bits[2], 0);
//   ck_assert_int_eq(res.bits[3], 1835008);
// }
//  END_TEST
//
//  START_TEST(div_9_test) {
//   s21_decimal num1 = {{-1, -1, -1, 0}};
//   s21_decimal num2 = {{2, 0, 0, 0}};
//   s21_decimal res = {{0, 0, 0, 0}};
//   int status = s21_div(num1, num2, &res);
//   ck_assert_int_eq(status, 0);
//   ck_assert_int_eq(res.bits[0], 0);
//   ck_assert_int_eq(res.bits[1], 0);
//   ck_assert_int_eq((int)res.bits[2], -2147483648);
//   ck_assert_int_eq(res.bits[3], 0);
// }
//  END_TEST
//
//  START_TEST(div_10_test) {
//   s21_decimal num1 = {{-1, -1, -1, 0}};
//   s21_decimal num2 = {{4, 0, 0, -2147483648}};
//   s21_decimal res = {{0, 0, 0, 0}};
//   int status = s21_div(num1, num2, &res);
//   ck_assert_int_eq(status, 0);
//   ck_assert_int_eq(res.bits[0], 0);
//   ck_assert_int_eq(res.bits[1], 0);
//   ck_assert_int_eq(res.bits[2], 1073741824);
//   ck_assert_int_eq((int)res.bits[3], -2147483648);
// }
//  END_TEST
//
//  START_TEST(div_11_test) {
//   s21_decimal num1 = {{-1, -1, -1, 0}};
//   s21_decimal num2 = {{3, 0, 0, 0}};
//   s21_decimal res = {{0, 0, 0, 0}};
//   int status = s21_div(num1, num2, &res);
//   ck_assert_int_eq(status, 0);
//   ck_assert_int_eq(res.bits[0], 1431655765);
//   ck_assert_int_eq(res.bits[1], 1431655765);
//   ck_assert_int_eq(res.bits[2], 1431655765);
//   ck_assert_int_eq(res.bits[3], 0);
// }
//  END_TEST
//
//  START_TEST(div_12_test) {
//   s21_decimal num1 = {{-1, -1, -1, 0}};
//   s21_decimal num2 = {{22, 0, 0, 65536}};
//   s21_decimal res = {{0, 0, 0, 0}};
//   int status = s21_div(num1, num2, &res);
//   ck_assert_int_eq(status, 0);
//   ck_assert_int_eq(res.bits[0], 1171354717);
//   ck_assert_int_eq((int)res.bits[1], -780903145);
//   ck_assert_int_eq(res.bits[2], 1952257861);
//   ck_assert_int_eq(res.bits[3], 0);
// }
//  END_TEST
//
//  START_TEST(div_13_test) {
//   s21_decimal num1 = {{-1, -1, -1, 0}};
//   s21_decimal num2 = {{658067456, 1164, 0, 0}};
//   s21_decimal res = {{0, 0, 0, 0}};
//   int status = s21_div(num1, num2, &res);
//   ck_assert_int_eq(status, 0);
//   ck_assert_int_eq(res.bits[0], 858993459);
//   ck_assert_int_eq(res.bits[1], 858993459);
//   ck_assert_int_eq(res.bits[2], 858993459);
//   ck_assert_int_eq(res.bits[3], 786432);
// }
//  END_TEST
//
//  START_TEST(div_14_test) {
//   s21_decimal num1 = {{-1, -1, -1, 0}};
//   s21_decimal num2 = {{1879048192, -1291644761, -500259693, 0}};
//   s21_decimal res = {{0, 0, 0, 0}};
//   int status = s21_div(num1, num2, &res);
//   ck_assert_int_eq(status, 0);
//   ck_assert_int_eq(res.bits[0], 1227133513);
//   ck_assert_int_eq((int)res.bits[1], -1840700270);
//   ck_assert_int_eq(res.bits[2], 613566756);
//   ck_assert_int_eq(res.bits[3], 1835008);
// }
//  END_TEST
//
//// START_TEST(div_15_test) {
////   s21_decimal num1 = {{-1, -1, -1, 0}};
////   s21_decimal num2 = {{805306368, -1167128797, 1626303258, 0}};
////   s21_decimal res = {{0, 0, 0, 0}};
////   int status = s21_div(num1, num2, &res);
////   ck_assert_int_eq(status, 0);
////   ck_assert_int_eq((int)res.bits[0], 1431655766);
////   ck_assert_int_eq((int)res.bits[1], 1431655765);
////   ck_assert_int_eq((int)res.bits[2], 1431655765);
////   ck_assert_int_eq(res.bits[3], 1835008);
//// }
//// END_TEST
//
// START_TEST(div_16_test) {
//  s21_decimal num1 = {{-1, -1, -1, 1835008}};
//  s21_decimal num2 = {{2, 0, 0, 0}};
//  s21_decimal res = {{0, 0, 0, 0}};
//  int status = s21_div(num1, num2, &res);
//  ck_assert_int_eq(status, 0);
//  ck_assert_int_eq(res.bits[0], 0);
//  ck_assert_int_eq(res.bits[1], 0);
//  ck_assert_int_eq((int)res.bits[2], -2147483648);
//  ck_assert_int_eq(res.bits[3], 1835008);
//}
// END_TEST
//
// START_TEST(div_17_test) {
//  s21_decimal num1 = {{-1, -1, -1, 1835008}};
//  s21_decimal num2 = {{4, 0, 0, -2147483648}};
//  s21_decimal res = {{0, 0, 0, 0}};
//  int status = s21_div(num1, num2, &res);
//  ck_assert_int_eq(status, 0);
//  ck_assert_int_eq(res.bits[0], 0);
//  ck_assert_int_eq(res.bits[1], 0);
//  ck_assert_int_eq(res.bits[2], 1073741824);
//  ck_assert_int_eq((int)res.bits[3], -2145648640);
//}
// END_TEST
//
// START_TEST(div_18_test) {
//  s21_decimal num1 = {{1, 1, 1, 1835008}};
//  s21_decimal num2 = {{0, 0, 0, -2147483648}};
//  s21_decimal res = {{0, 0, 0, 0}};
//  int status = s21_div(num1, num2, &res);
//  ck_assert_int_eq(status, 3);
//}
// END_TEST
//
// START_TEST(div_19_test) {
//  s21_decimal num1 = {{-1, -1, -1, 0}};
//  s21_decimal num2 = {{1, 0, 0, 393216}};
//  s21_decimal res = {{0, 0, 0, 0}};
//  int status = s21_div(num1, num2, &res);
//  ck_assert_int_eq(status, 1);
//}
// END_TEST
//
// START_TEST(div_20_test) {
//  s21_decimal num1 = {{1, 0, 0, 1835008}};
//  s21_decimal num2 = {{4, 0, 0, -2147483648}};
//  s21_decimal res = {{0, 0, 0, 0}};
//  int status = s21_div(num1, num2, &res);
//  ck_assert_int_eq(status, 2);
//}
// END_TEST
//
// START_TEST(div_big_error) {
//  s21_decimal src1 = {{0, 0, 0, 0}};
//  s21_decimal src2 = {{0, 0, 0, 0}};
//  s21_decimal result_our = {{0, 0, 0, 0}};
//
//  src1.bits[0] = 0b11111111111111111111111111111110;
//  src1.bits[1] = 0b11111111111111111111111111111111;
//  src1.bits[2] = 0b11111111111111111111111111111111;
//  src1.bits[3] = 0b00000000000000000000000000000000;
//
//  src2.bits[0] = 0b00000000000000000000000000000001;
//  src2.bits[1] = 0b00000000000000000000000000000000;
//  src2.bits[2] = 0b00000000000000000000000000000000;
//  src2.bits[3] = 0b00000000000111000000000000000000;
//  int val = s21_div(src1, src2, &result_our);
//  ck_assert_int_eq(val, 1);
//}
// END_TEST
//
// START_TEST(div_error) {
//  s21_decimal src1 = {{0, 0, 0, 0}};
//  s21_decimal src2 = {{0, 0, 0, 0}};
//  s21_decimal *result_our = NULL;
//  int val = s21_div(src1, src2, result_our);
//  ck_assert_int_eq(val, 4);
//}
// END_TEST

Suite *s21_suite_arith() {
  Suite *s_test;
  TCase *tc_arith;

  s_test = suite_create("arithmetic");
  tc_arith = tcase_create("arith");
  tcase_add_test(tc_arith, s21_add_1);
  tcase_add_test(tc_arith, s21_add_2);
  tcase_add_test(tc_arith, s21_add_3);
  tcase_add_test(tc_arith, s21_add_4);
  tcase_add_test(tc_arith, s21_add_6);
  tcase_add_test(tc_arith, s21_add_7);
  tcase_add_test(tc_arith, s21_add_8);
  tcase_add_test(tc_arith, s21_add_9);
  tcase_add_test(tc_arith, s21_add_10);
  tcase_add_test(tc_arith, s21_add_11);
  tcase_add_test(tc_arith, s21_add_12);
  tcase_add_test(tc_arith, s21_add_13);
  tcase_add_test(tc_arith, s21_add_14);
  //  tcase_add_test(tc_arith, s21_add_15);
  tcase_add_test(tc_arith, s21_add_16);
  tcase_add_test(tc_arith, s21_add_18);
  tcase_add_test(tc_arith, s21_add_23);
  tcase_add_test(tc_arith, s21_add_24);
  tcase_add_test(tc_arith, s21_add_25);
  tcase_add_test(tc_arith, s21_add_27);
  tcase_add_test(tc_arith, s21_add_28);
  tcase_add_test(tc_arith, s21_add_29);
  tcase_add_test(tc_arith, s21_add_30);
  tcase_add_test(tc_arith, s21_add_31);
  tcase_add_test(tc_arith, s21_add_36);
  tcase_add_test(tc_arith, s21_add_40);
  tcase_add_test(tc_arith, s21_add_44);
  tcase_add_test(tc_arith, s21_add_45);
  tcase_add_test(tc_arith, s21_add_51);
  tcase_add_test(tc_arith, s21_add_52);
  tcase_add_test(tc_arith, add1);
  tcase_add_test(tc_arith, add2);
  tcase_add_test(tc_arith, add3);
  tcase_add_test(tc_arith, add4);
  tcase_add_test(tc_arith, add5);
  tcase_add_test(tc_arith, add6);
  tcase_add_test(tc_arith, add7);
  tcase_add_test(tc_arith, add8);
  tcase_add_test(tc_arith, add9);
  tcase_add_test(tc_arith, add10);
  tcase_add_test(tc_arith, add11);
  tcase_add_test(tc_arith, add12);
  tcase_add_test(tc_arith, add13);
  tcase_add_test(tc_arith, add14);
  tcase_add_test(tc_arith, add15);
  tcase_add_test(tc_arith, add16);
  tcase_add_test(tc_arith, add17);
  tcase_add_test(tc_arith, add18);
  tcase_add_test(tc_arith, add20);
  tcase_add_test(tc_arith, add22);
  tcase_add_test(tc_arith, add23);
  tcase_add_test(tc_arith, add24);
  tcase_add_test(tc_arith, add25);
  tcase_add_test(tc_arith, add26);
  tcase_add_test(tc_arith, add27);
  tcase_add_test(tc_arith, add28);
  tcase_add_test(tc_arith, add29);
  tcase_add_test(tc_arith, add30);

  tcase_add_test(tc_arith, s21_sub_1);
  tcase_add_test(tc_arith, s21_sub_2);
  tcase_add_test(tc_arith, s21_sub_3);
  tcase_add_test(tc_arith, s21_sub_4);
  tcase_add_test(tc_arith, s21_sub_6);
  tcase_add_test(tc_arith, s21_sub_7);
  tcase_add_test(tc_arith, s21_sub_8);
  tcase_add_test(tc_arith, s21_sub_9);
  tcase_add_test(tc_arith, s21_sub_10);
  tcase_add_test(tc_arith, s21_sub_11);
  //  tcase_add_test(tc_arith, s21_sub_15);
  tcase_add_test(tc_arith, s21_sub_16);
  tcase_add_test(tc_arith, s21_sub_17);
  tcase_add_test(tc_arith, s21_sub_22);
  tcase_add_test(tc_arith, s21_sub_23);
  tcase_add_test(tc_arith, s21_sub_24);
  tcase_add_test(tc_arith, s21_sub_26);
  tcase_add_test(tc_arith, s21_sub_28);
  tcase_add_test(tc_arith, s21_sub_30);
  tcase_add_test(tc_arith, s21_sub_35);
  tcase_add_test(tc_arith, s21_sub_36);
  tcase_add_test(tc_arith, s21_sub_39);
  tcase_add_test(tc_arith, s21_sub_51);
  tcase_add_test(tc_arith, s21_sub_52);
  tcase_add_test(tc_arith, s21_sub_53);
  tcase_add_test(tc_arith, sub1);
  tcase_add_test(tc_arith, sub2);
  tcase_add_test(tc_arith, sub3);
  tcase_add_test(tc_arith, sub4);
  tcase_add_test(tc_arith, sub5);
  tcase_add_test(tc_arith, sub6);
  tcase_add_test(tc_arith, sub7);
  tcase_add_test(tc_arith, sub8);
  tcase_add_test(tc_arith, sub9);
  tcase_add_test(tc_arith, sub10);
  tcase_add_test(tc_arith, sub11);
  tcase_add_test(tc_arith, sub12);
  tcase_add_test(tc_arith, sub13);
  tcase_add_test(tc_arith, sub14);
  tcase_add_test(tc_arith, sub15);
  tcase_add_test(tc_arith, sub16);

  tcase_add_test(tc_arith, s21_mul_1);
  tcase_add_test(tc_arith, s21_mul_2);
  tcase_add_test(tc_arith, s21_mul_3);
  tcase_add_test(tc_arith, s21_mul_4);
  tcase_add_test(tc_arith, s21_mul_6);
  tcase_add_test(tc_arith, s21_mul_7);
  tcase_add_test(tc_arith, s21_mul_8);
  tcase_add_test(tc_arith, s21_mul_9);
  tcase_add_test(tc_arith, s21_mul_69);
  tcase_add_test(tc_arith, s21_mul_11);
  tcase_add_test(tc_arith, s21_mul_12);
  tcase_add_test(tc_arith, s21_mul_13);
  tcase_add_test(tc_arith, s21_mul_14);
  tcase_add_test(tc_arith, s21_mul_23);
  tcase_add_test(tc_arith, s21_mul_24);
  tcase_add_test(tc_arith, s21_mul_25);
  tcase_add_test(tc_arith, s21_mul_26);
  // tcase_add_test(tc_arith, s21_mul_27);
  // tcase_add_test(tc_arith, s21_mul_28);
  tcase_add_test(tc_arith, s21_mul_33);
  tcase_add_test(tc_arith, mul1);
  tcase_add_test(tc_arith, mul2);
  tcase_add_test(tc_arith, mul3);
  //  tcase_add_test(tc_arith, mul4);
  //  tcase_add_test(tc_arith, mul5);
  tcase_add_test(tc_arith, mul6);
  tcase_add_test(tc_arith, mul7);
  tcase_add_test(tc_arith, mul8);
  tcase_add_test(tc_arith, mul9);
  tcase_add_test(tc_arith, mul10);
  tcase_add_test(tc_arith, mul11);
  tcase_add_test(tc_arith, mul12);
  tcase_add_test(tc_arith, mul13);
  //  tcase_add_test(tc_arith, mul14);
  tcase_add_test(tc_arith, mul15);
  tcase_add_test(tc_arith, mul16);
  tcase_add_test(tc_arith, mul17);
  tcase_add_test(tc_arith, mul_1);
  tcase_add_test(tc_arith, mul_2);
  tcase_add_test(tc_arith, mul_3);
  tcase_add_test(tc_arith, mul_4);
  tcase_add_test(tc_arith, mul_5);
  //  tcase_add_test(tc_arith, mul_6);
  //  tcase_add_test(tc_arith, mul_7);
  //  tcase_add_test(tc_arith, mul_8);

  //  tcase_add_test(tc_arith, div3);
  //  tcase_add_test(tc_arith, div4);
  //  tcase_add_test(tc_arith, div6);
  //  tcase_add_test(tc_arith, div7);
  //  tcase_add_test(tc_arith, div8);
  //  tcase_add_test(tc_arith, div9);
  //  tcase_add_test(tc_arith, div10);
  //  tcase_add_test(tc_arith, div11);
  //  tcase_add_test(tc_arith, div12);
  //  tcase_add_test(tc_arith, div13);
  //  tcase_add_test(tc_arith, div14);
  //  tcase_add_test(tc_arith, div15);
  //  tcase_add_test(tc_arith, div16);
  //  tcase_add_test(tc_arith, div17);
  //
  //  tcase_add_test(tc_arith, div_1_test);
  //  tcase_add_test(tc_arith, div_2_test);
  //  tcase_add_test(tc_arith, div_3_test);
  //  tcase_add_test(tc_arith, div_4_test);
  //  tcase_add_test(tc_arith, div_5_test);
  //  tcase_add_test(tc_arith, div_6_test);
  //  tcase_add_test(tc_arith, div_7_test);
  //  tcase_add_test(tc_arith, div_8_test);
  //  tcase_add_test(tc_arith, div_9_test);
  //  tcase_add_test(tc_arith, div_10_test);
  //  tcase_add_test(tc_arith, div_11_test);
  //  tcase_add_test(tc_arith, div_12_test);
  //  tcase_add_test(tc_arith, div_13_test);
  //  tcase_add_test(tc_arith, div_14_test);
  //  // tcase_add_test(tc_arith, div_15_test);
  //  tcase_add_test(tc_arith, div_16_test);
  //  tcase_add_test(tc_arith, div_17_test);
  //  tcase_add_test(tc_arith, div_18_test);
  //  tcase_add_test(tc_arith, div_19_test);
  //  tcase_add_test(tc_arith, div_20_test);
  //  tcase_add_test(tc_arith, div_big_error);
  //  tcase_add_test(tc_arith, div_error);

  suite_add_tcase(s_test, tc_arith);
  return s_test;
}
