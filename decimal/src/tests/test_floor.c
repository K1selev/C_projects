#include "s21_decimal_tst.h"

START_TEST(floor_1) {
  s21_decimal num = {{15, 0, 0, 65536}};
  s21_decimal res = {{1, 0, 0, 0}};
  int error = 0;
  error = s21_floor(num, &num);
  ck_assert_int_eq(num.bits[0], res.bits[0]);
  ck_assert_int_eq(num.bits[1], res.bits[1]);
  ck_assert_int_eq(num.bits[2], res.bits[2]);
  ck_assert_int_eq(num.bits[3], res.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(floor_2) {
  s21_decimal num = {{19, 0, 0, 65536}};
  s21_decimal res = {{1, 0, 0, 0}};
  int error = 0;
  error = s21_floor(num, &num);
  ck_assert_int_eq(num.bits[0], res.bits[0]);
  ck_assert_int_eq(num.bits[1], res.bits[1]);
  ck_assert_int_eq(num.bits[2], res.bits[2]);
  ck_assert_int_eq(num.bits[3], res.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(floor_3) {
  s21_decimal num = {{155, 0, 0, 131072}};
  s21_decimal res = {{1, 0, 0, 0}};
  int error = 0;
  error = s21_floor(num, &num);
  ck_assert_int_eq(num.bits[0], res.bits[0]);
  ck_assert_int_eq(num.bits[1], res.bits[1]);
  ck_assert_int_eq(num.bits[2], res.bits[2]);
  ck_assert_int_eq(num.bits[3], res.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(floor_4) {
  s21_decimal num = {{15, 0, 0, 2147549184u}};
  s21_decimal res = {{2, 0, 0, 2147483648u}};
  int error = 0;
  error = s21_floor(num, &num);
  ck_assert_int_eq(num.bits[0], res.bits[0]);
  ck_assert_int_eq(num.bits[1], res.bits[1]);
  ck_assert_int_eq(num.bits[2], res.bits[2]);
  ck_assert_int_eq(num.bits[3], res.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(floor_5) {
  s21_decimal num = {{268435457, 1042612833, 542101086, 2149318656u}};
  s21_decimal res = {{2, 0, 0, 2147483648u}};
  int error = 0;
  error = s21_floor(num, &num);
  ck_assert_int_eq(num.bits[0], res.bits[0]);
  ck_assert_int_eq(num.bits[1], res.bits[1]);
  ck_assert_int_eq(num.bits[2], res.bits[2]);
  ck_assert_int_eq(num.bits[3], res.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(floor_6) {
  s21_decimal num = {{0, 0, 0, 0}};
  int error = 0;
  error = s21_floor(num, NULL);
  ck_assert_int_eq(error, 0);
}
END_TEST

// START_TEST(floor_7) {
//   s21_decimal num = {{21, 0, 0, NEGATIVE}};
//   s21_decimal res = {{3, 0, 0, NEGATIVE}};
//   s21_get_fraction(&num, 1);
//   int error = 0;
//   error = s21_floor(num, &num);
//   ck_assert_int_eq(num.bits[0], res.bits[0]);
//   ck_assert_int_eq(num.bits[1], res.bits[1]);
//   ck_assert_int_eq(num.bits[2], res.bits[2]);
//   ck_assert_int_eq(num.bits[3], res.bits[3]);
//   ck_assert_int_eq(error, 0);
// }
// END_TEST

START_TEST(floor_8) {
  s21_decimal x = {{1, 2, 3, 917504}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_floor(x, &z);
  char ourRes[1000], expect[1000] = "553402 0 0 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(floor_9) {
  s21_decimal x = {{1, 2, 3, -2146566144}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_floor(x, &z);
  char ourRes[1000], expect[1000] = "553403 0 0 2147483648";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(floor_10) {
  s21_decimal x = {{33, 2, 3000, -2146107392}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_floor(x, &z);
  char ourRes[1000], expect[1000] = "56 0 0 2147483648";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(floor_11) {
  s21_decimal src, origin, result;
  // src = 5.0;
  src.bits[0] = 0b00000000000000000000000000110010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 5;
  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(floor_12) {
  s21_decimal src, origin, result;
  // src = 3.4;
  src.bits[0] = 0b00000000000000000000000000100010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(floor_13) {
  s21_decimal src, origin, result;
  // src = 0.0;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(floor_14) {
  s21_decimal src, origin, result;
  // src = -2.4363463;
  src.bits[0] = 0b00000001011100111100000111000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000001110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

// START_TEST(floor_15) {
//   s21_decimal src, origin, result;
//   // src = -0.0;
//   src.bits[0] = 0b00000000000000000000000000000000;
//   src.bits[1] = 0b00000000000000000000000000000000;
//   src.bits[2] = 0b00000000000000000000000000000000;
//   src.bits[3] = 0b10000000000000010000000000000000;
//   int check = s21_floor(src, &result);
//   int check_origin = 0;
//   // origin = 0;
//   origin.bits[0] = 0b00000000000000000000000000000000;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
//   ck_assert_int_eq(check, check_origin);
// }
// END_TEST

START_TEST(floor_16) {
  s21_decimal src, origin, result;
  // src = -0.45;
  src.bits[0] = 0b00000000000000000000000000101101;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000100000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(floor_17) {
  s21_decimal src, origin, result;
  // src = 652.34631;
  src.bits[0] = 0b00000011111000110110011011000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 652;
  origin.bits[0] = 0b00000000000000000000001010001100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(floor_18) {
  s21_decimal src, origin, result;
  // src = 4.97623323;
  src.bits[0] = 0b00011101101010010010000100011011;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000010000000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 4;
  origin.bits[0] = 0b00000000000000000000000000000100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(floor_19) {
  s21_decimal src, origin, result;
  // src = 65658654.59;
  src.bits[0] = 0b10000111010110110010011111110011;
  src.bits[1] = 0b00000000000000000000000000000001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000100000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 65658654;
  origin.bits[0] = 0b00000011111010011101111100011110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(floor_20) {
  s21_decimal src, origin, result;
  // src = -364748.110;
  src.bits[0] = 0b00010101101111011001110101001110;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -364749;
  origin.bits[0] = 0b00000000000001011001000011001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(floor_21) {
  s21_decimal src, origin, result;
  // src = 1.9874565432111;
  src.bits[0] = 0b01101000011010011010001100101111;
  src.bits[1] = 0b00000000000000000001001000010011;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000011010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(floor_22) {
  s21_decimal src, origin, result;
  // src = -98.78798789312;
  src.bits[0] = 0b00010110010010101110101011000000;
  src.bits[1] = 0b00000000000000000000100011111100;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000010110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -99;
  origin.bits[0] = 0b00000000000000000000000001100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(floor_23) {
  s21_decimal src, origin, result;
  // src = 999999999999999999911.3;
  src.bits[0] = 0b10110010001111111111110010001001;
  src.bits[1] = 0b00011001111000001100100110111010;
  src.bits[2] = 0b00000000000000000000001000011110;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 999999999999999999911;
  origin.bits[0] = 0b11011110100111111111111110100111;
  origin.bits[1] = 0b00110101110010011010110111000101;
  origin.bits[2] = 0b00000000000000000000000000110110;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(floor_24) {
  s21_decimal src, origin, result;
  // src = -545454512454545.35265454545645;
  src.bits[0] = 0b10000010111000100101101011101101;
  src.bits[1] = 0b11111001111010000010010110101101;
  src.bits[2] = 0b10110000001111101111000010010100;
  src.bits[3] = 0b10000000000011100000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -545454512454546;
  origin.bits[0] = 0b10000110011101001011101110010010;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(floor_25) {
  s21_decimal src, origin, result;
  // src = 545454512454545.35265454545645;
  src.bits[0] = 0b10000010111000100101101011101101;
  src.bits[1] = 0b11111001111010000010010110101101;
  src.bits[2] = 0b10110000001111101111000010010100;
  src.bits[3] = 0b00000000000011100000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 545454512454545;
  origin.bits[0] = 0b10000110011101001011101110010001;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(floor_26) {
  s21_decimal src, origin, result;
  // src = 7961327845421.879754123131254;
  src.bits[0] = 0b01001110111001000011100101110110;
  src.bits[1] = 0b01001011001101011010000111011001;
  src.bits[2] = 0b00011001101110010111010010111111;
  src.bits[3] = 0b00000000000011110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 7961327845421;
  origin.bits[0] = 0b10100100000111100100000000101101;
  origin.bits[1] = 0b00000000000000000000011100111101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(floor_27) {
  s21_decimal src, origin, result;
  // src = 12345677.987654345678987654346;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b00000000000101010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 12345677;
  origin.bits[0] = 0b00000000101111000110000101001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(floor_28) {
  s21_decimal src, origin, result;
  // src = -12345677.987654345678987654346;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b10000000000101010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -12345678;
  origin.bits[0] = 0b00000000101111000110000101001110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(floor_29) {
  s21_decimal src, origin, result;
  // src = 87654323456.9876545678987653;
  src.bits[0] = 0b00010001110011011101000110000101;
  src.bits[1] = 0b11110101101111000110111111000000;
  src.bits[2] = 0b00000010110101010000111100111111;
  src.bits[3] = 0b00000000000100000000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 87654323456;
  origin.bits[0] = 0b01101000100110101101010100000000;
  origin.bits[1] = 0b00000000000000000000000000010100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(floor_30) {
  s21_decimal src, origin, result;
  // src = 336565445454313.859865545;
  src.bits[0] = 0b00111110111111000101101111001001;
  src.bits[1] = 0b00111111110101011110000010001011;
  src.bits[2] = 0b00000000000000000100011101000101;
  src.bits[3] = 0b00000000000010010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 336565445454313;
  origin.bits[0] = 0b10111111110100011110100111101001;
  origin.bits[1] = 0b00000000000000010011001000011010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

// START_TEST(floor_31) {
//   s21_decimal src, origin, result;
//   // src = -15456451234534;
//   src.bits[0] = 0b10111100010010010000101011100110;
//   src.bits[1] = 0b00000000000000000000111000001110;
//   src.bits[2] = 0b00000000000000000000000000000000;
//   src.bits[3] = 0b10000000000000000000000000000000;
//   int check = s21_floor(src, &result);
//   int check_origin = 0;
//   // origin = -15456451234534;
//   origin.bits[0] = 0b10111100010010010000101011100110;
//   origin.bits[1] = 0b00000000000000000000111000001110;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
//   ck_assert_int_eq(check, check_origin);
// }
// END_TEST

START_TEST(floor_32) {
  s21_decimal src, origin, result;
  // src = -0.42354543545;
  src.bits[0] = 0b11011100100001110000101110111001;
  src.bits[1] = 0b00000000000000000000000000001001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000010110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

// START_TEST(floor_33) {
//   s21_decimal src, origin, result;
//   // src = 79228162514264337593543950335;
//   src.bits[0] = 0b11111111111111111111111111111111;
//   src.bits[1] = 0b11111111111111111111111111111111;
//   src.bits[2] = 0b11111111111111111111111111111111;
//   src.bits[3] = 0;
//   int check = s21_floor(src, &result);
//   int check_origin = 0;
//   // origin = 79228162514264337593543950335;
//   origin.bits[0] = 0b11111111111111111111111111111111;
//   origin.bits[1] = 0b11111111111111111111111111111111;
//   origin.bits[2] = 0b11111111111111111111111111111111;
//   origin.bits[3] = 0;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
//   ck_assert_int_eq(check, check_origin);
// }
// END_TEST

START_TEST(floor_34) {
  s21_decimal src, origin, result;
  // src = 2.7986531268974139743;
  src.bits[0] = 0b11111110100100001101100101011111;
  src.bits[1] = 0b10000100011001000010000111101000;
  src.bits[2] = 0b00000000000000000000000000000001;
  src.bits[3] = 0b00000000000100110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_1) {
  s21_decimal src, origin, result;
  // src = 5.0;
  src.bits[0] = 0b00000000000000000000000000110010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 5;
  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_2) {
  s21_decimal src, origin, result;
  // src = 3.4;
  src.bits[0] = 0b00000000000000000000000000100010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_3) {
  s21_decimal src, origin, result;
  // src = 0.0;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_4) {
  s21_decimal src, origin, result;
  // src = -2.4363463;
  src.bits[0] = 0b00000001011100111100000111000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000001110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_6) {
  s21_decimal src, origin, result;
  // src = -0.45;
  src.bits[0] = 0b00000000000000000000000000101101;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000100000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_7) {
  s21_decimal src, origin, result;
  // src = 652.34631;
  src.bits[0] = 0b00000011111000110110011011000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 652;
  origin.bits[0] = 0b00000000000000000000001010001100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_8) {
  s21_decimal src, origin, result;
  // src = 4.97623323;
  src.bits[0] = 0b00011101101010010010000100011011;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000010000000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 4;
  origin.bits[0] = 0b00000000000000000000000000000100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_9) {
  s21_decimal src, origin, result;
  // src = 65658654.59;
  src.bits[0] = 0b10000111010110110010011111110011;
  src.bits[1] = 0b00000000000000000000000000000001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000100000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 65658654;
  origin.bits[0] = 0b00000011111010011101111100011110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_10) {
  s21_decimal src, origin, result;
  // src = -364748.110;
  src.bits[0] = 0b00010101101111011001110101001110;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -364749;
  origin.bits[0] = 0b00000000000001011001000011001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_11) {
  s21_decimal src, origin, result;
  // src = 1.9874565432111;
  src.bits[0] = 0b01101000011010011010001100101111;
  src.bits[1] = 0b00000000000000000001001000010011;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000011010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_12) {
  s21_decimal src, origin, result;
  // src = -98.78798789312;
  src.bits[0] = 0b00010110010010101110101011000000;
  src.bits[1] = 0b00000000000000000000100011111100;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000010110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -99;
  origin.bits[0] = 0b00000000000000000000000001100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_13) {
  s21_decimal src, origin, result;
  // src = 999999999999999999911.3;
  src.bits[0] = 0b10110010001111111111110010001001;
  src.bits[1] = 0b00011001111000001100100110111010;
  src.bits[2] = 0b00000000000000000000001000011110;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 999999999999999999911;
  origin.bits[0] = 0b11011110100111111111111110100111;
  origin.bits[1] = 0b00110101110010011010110111000101;
  origin.bits[2] = 0b00000000000000000000000000110110;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_14) {
  s21_decimal src, origin, result;
  // src = -545454512454545.35265454545645;
  src.bits[0] = 0b10000010111000100101101011101101;
  src.bits[1] = 0b11111001111010000010010110101101;
  src.bits[2] = 0b10110000001111101111000010010100;
  src.bits[3] = 0b10000000000011100000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -545454512454546;
  origin.bits[0] = 0b10000110011101001011101110010010;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_15) {
  s21_decimal src, origin, result;
  // src = 545454512454545.35265454545645;
  src.bits[0] = 0b10000010111000100101101011101101;
  src.bits[1] = 0b11111001111010000010010110101101;
  src.bits[2] = 0b10110000001111101111000010010100;
  src.bits[3] = 0b00000000000011100000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 545454512454545;
  origin.bits[0] = 0b10000110011101001011101110010001;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_16) {
  s21_decimal src, origin, result;
  // src = 7961327845421.879754123131254;
  src.bits[0] = 0b01001110111001000011100101110110;
  src.bits[1] = 0b01001011001101011010000111011001;
  src.bits[2] = 0b00011001101110010111010010111111;
  src.bits[3] = 0b00000000000011110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 7961327845421;
  origin.bits[0] = 0b10100100000111100100000000101101;
  origin.bits[1] = 0b00000000000000000000011100111101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_17) {
  s21_decimal src, origin, result;
  // src = 12345677.987654345678987654346;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b00000000000101010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 12345677;
  origin.bits[0] = 0b00000000101111000110000101001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_18) {
  s21_decimal src, origin, result;
  // src = -12345677.987654345678987654346;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b10000000000101010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -12345678;
  origin.bits[0] = 0b00000000101111000110000101001110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_19) {
  s21_decimal src, origin, result;
  // src = 87654323456.9876545678987653;
  src.bits[0] = 0b00010001110011011101000110000101;
  src.bits[1] = 0b11110101101111000110111111000000;
  src.bits[2] = 0b00000010110101010000111100111111;
  src.bits[3] = 0b00000000000100000000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 87654323456;
  origin.bits[0] = 0b01101000100110101101010100000000;
  origin.bits[1] = 0b00000000000000000000000000010100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_20) {
  s21_decimal src, origin, result;
  // src = 336565445454313.859865545;
  src.bits[0] = 0b00111110111111000101101111001001;
  src.bits[1] = 0b00111111110101011110000010001011;
  src.bits[2] = 0b00000000000000000100011101000101;
  src.bits[3] = 0b00000000000010010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 336565445454313;
  origin.bits[0] = 0b10111111110100011110100111101001;
  origin.bits[1] = 0b00000000000000010011001000011010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

// START_TEST(s21_floor_21) {
//   s21_decimal src, origin, result;
//   // src = -15456451234534;
//   src.bits[0] = 0b10111100010010010000101011100110;
//   src.bits[1] = 0b00000000000000000000111000001110;
//   src.bits[2] = 0b00000000000000000000000000000000;
//   src.bits[3] = 0b10000000000000000000000000000000;
//   int check = s21_floor(src, &result);
//   int check_origin = 0;
//   // origin = -15456451234534;
//   origin.bits[0] = 0b10111100010010010000101011100110;
//   origin.bits[1] = 0b00000000000000000000111000001110;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
//   ck_assert_int_eq(check, check_origin);
// }
// END_TEST

START_TEST(s21_floor_22) {
  s21_decimal src, origin, result;
  // src = -0.42354543545;
  src.bits[0] = 0b11011100100001110000101110111001;
  src.bits[1] = 0b00000000000000000000000000001001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000010110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

// START_TEST(s21_floor_23) {
//   s21_decimal src, origin, result;
//   // src = 79228162514264337593543950335;
//   src.bits[0] = 0b11111111111111111111111111111111;
//   src.bits[1] = 0b11111111111111111111111111111111;
//   src.bits[2] = 0b11111111111111111111111111111111;
//   src.bits[3] = 0b00000000000000000000000000000000;
//   int check = s21_floor(src, &result);
//   int check_origin = 0;
//   // origin = 79228162514264337593543950335;
//   origin.bits[0] = 0b11111111111111111111111111111111;
//   origin.bits[1] = 0b11111111111111111111111111111111;
//   origin.bits[2] = 0b11111111111111111111111111111111;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
//   ck_assert_int_eq(check, check_origin);
// }
// END_TEST

START_TEST(s21_floor_24) {
  s21_decimal src, origin, result;
  // src = 2.7986531268974139743;
  src.bits[0] = 0b11111110100100001101100101011111;
  src.bits[1] = 0b10000100011001000010000111101000;
  src.bits[2] = 0b00000000000000000000000000000001;
  src.bits[3] = 0b00000000000100110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

Suite *suite_floor(void) {
  Suite *s = suite_create("floor");
  TCase *tc = tcase_create("insert_tc");

  tcase_add_test(tc, floor_1);
  tcase_add_test(tc, floor_2);
  tcase_add_test(tc, floor_3);
  tcase_add_test(tc, floor_4);
  tcase_add_test(tc, floor_5);
  tcase_add_test(tc, floor_6);
  // tcase_add_test(tc, floor_7);
  tcase_add_test(tc, floor_8);
  tcase_add_test(tc, floor_9);
  tcase_add_test(tc, floor_10);
  tcase_add_test(tc, floor_11);
  tcase_add_test(tc, floor_12);
  tcase_add_test(tc, floor_13);
  tcase_add_test(tc, floor_14);
  // tcase_add_test(tc, floor_15);
  tcase_add_test(tc, floor_16);
  tcase_add_test(tc, floor_17);
  tcase_add_test(tc, floor_18);
  tcase_add_test(tc, floor_19);
  tcase_add_test(tc, floor_20);
  tcase_add_test(tc, floor_21);
  tcase_add_test(tc, floor_22);
  tcase_add_test(tc, floor_23);
  tcase_add_test(tc, floor_24);
  tcase_add_test(tc, floor_25);
  tcase_add_test(tc, floor_26);
  tcase_add_test(tc, floor_27);
  tcase_add_test(tc, floor_28);
  tcase_add_test(tc, floor_29);
  tcase_add_test(tc, floor_30);
  // tcase_add_test(tc, floor_31);
  tcase_add_test(tc, floor_32);
  //  tcase_add_test(tc, floor_33);
  tcase_add_test(tc, floor_34);

  tcase_add_test(tc, s21_floor_1);
  tcase_add_test(tc, s21_floor_2);
  tcase_add_test(tc, s21_floor_3);
  tcase_add_test(tc, s21_floor_4);
  tcase_add_test(tc, s21_floor_6);
  tcase_add_test(tc, s21_floor_7);
  tcase_add_test(tc, s21_floor_8);
  tcase_add_test(tc, s21_floor_9);
  tcase_add_test(tc, s21_floor_10);
  tcase_add_test(tc, s21_floor_11);
  tcase_add_test(tc, s21_floor_12);
  tcase_add_test(tc, s21_floor_13);
  tcase_add_test(tc, s21_floor_14);
  tcase_add_test(tc, s21_floor_15);
  tcase_add_test(tc, s21_floor_16);
  tcase_add_test(tc, s21_floor_17);
  tcase_add_test(tc, s21_floor_18);
  tcase_add_test(tc, s21_floor_19);
  tcase_add_test(tc, s21_floor_20);
  //  tcase_add_test(tc, s21_floor_21);
  tcase_add_test(tc, s21_floor_22);
  //  tcase_add_test(tc, s21_floor_23);
  tcase_add_test(tc, s21_floor_24);
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
