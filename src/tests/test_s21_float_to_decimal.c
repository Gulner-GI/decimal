#include <check.h>

#include "s21_decimal.h"

START_TEST(test_s21_from_float_to_decimal_positive) {
  s21_decimal dst = {{0, 0, 0, 0}};
  float src = 893;
  int result = s21_from_float_to_decimal(src, &dst);
  int scale = get_scale(dst);
  int sign = get_sign(dst);
  ck_assert_int_eq(result, 0);
  ck_assert_uint_eq(src, dst.bits[0]);
  ck_assert_uint_eq(0, dst.bits[1]);
  ck_assert_uint_eq(0, dst.bits[2]);
  ck_assert_int_eq(0, scale);
  ck_assert_int_eq(0, sign);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_negative) {
  s21_decimal dst = {{0, 0, 0, 0}};
  float src = -1351;
  int result = s21_from_float_to_decimal(src, &dst);
  int scale = get_scale(dst);
  int sign = get_sign(dst);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(scale, 0);
  ck_assert_int_eq(sign, 1);
  ck_assert_uint_eq(dst.bits[0], -src);
  ck_assert_uint_eq(dst.bits[1], 0);
  ck_assert_uint_eq(dst.bits[2], 0);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_zero) {
  s21_decimal dst = {{0, 0, 0, 0}};
  float src = 0;
  int result = s21_from_float_to_decimal(src, &dst);
  int scale = get_scale(dst);
  int sign = get_sign(dst);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(scale, 0);
  ck_assert_int_eq(sign, 0);
  ck_assert_uint_eq(dst.bits[0], 0);
  ck_assert_uint_eq(dst.bits[1], 0);
  ck_assert_uint_eq(dst.bits[2], 0);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_with_scale_positive) {
    s21_decimal dst = {{0, 0, 0, 0}};
    float src = 132.425;
    int result = s21_from_float_to_decimal(src, &dst);
    int scale = get_scale(dst);
    int sign = get_sign(dst);
    ck_assert_int_eq(result, 0);
    ck_assert_int_eq(scale, 3);
    ck_assert_int_eq(sign, 0);
    ck_assert_uint_eq(dst.bits[0], 132425);
    ck_asser_uint_eq(dst.bits[1], 0);
    ck_asser_uint_eq(dst.bits[2], 0);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_with_scale_negative) {

}
END_TEST

START_TEST(test_s21_from_float_to_decimal_min) {

}
END_TEST

START_TEST(test_s21_from_float_to_decimal_error) {
  float src = 12.0;
  int result = s21_from_float_to_decimal(src, NULL);
  ck_assert_int_eq(result, 1);
}
END_TEST

Suite *float_to_decimal_suite() {
  Suite *s = suite_create("s21_float_to_decimal");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_from_float_to_decimal_positive);
  tcase_add_test(tc_core, test_s21_from_float_to_decimal_negative);
  tcase_add_test(tc_core, test_s21_from_float_to_decimal_zero);
  tcase_add_test(tc_core, test_s21_from_float_to_decimal_min);
  tcase_add_test(tc_core, test_s21_from_float_to_decimal_error);
  tcase_add_test(tc_core, test_s21_from_float_to_decimal_with_scale_positive);
  tcase_add_test(tc_core, test_s21_from_float_to_decimal_with_scale_negative);
}