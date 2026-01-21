#include <check.h>

#include "s21_decimal.h"

START_TEST(test_s21_from_int_to_decimal_positive) {
  s21_decimal dst = {{0, 0, 0, 0}};
  int src = 893;
  int result = s21_from_int_to_decimal(src, &dst);
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

START_TEST(test_s21_from_int_to_decimal_negative) {
  s21_decimal dst = {{0, 0, 0, 0}};
  int src = -43108;
  int result = s21_from_int_to_decimal(src, &dst);
  int scale = get_scale(dst);
  int sign = get_sign(dst);
  ck_assert_int_eq(result, 0);
  ck_assert_uint_eq(-src, dst.bits[0]);
  ck_assert_uint_eq(0, dst.bits[1]);
  ck_assert_uint_eq(0, dst.bits[2]);
  ck_assert_int_eq(0, scale);
  ck_assert_int_eq(1, sign);
}
END_TEST

START_TEST(test_s21_from_int_to_decimal_zero) {
  s21_decimal dst = {{0, 0, 0, 0}};
  int src = 0;
  int result = s21_from_int_to_decimal(src, &dst);
  int scale = get_scale(dst);
  int sign = get_sign(dst);
  ck_assert_int_eq(result, 0);
  ck_assert_uint_eq(0, dst.bits[0]);
  ck_assert_uint_eq(0, dst.bits[1]);
  ck_assert_uint_eq(0, dst.bits[2]);
  ck_assert_int_eq(0, scale);
  ck_assert_int_eq(0, sign);
}
END_TEST

START_TEST(test_s21_from_int_to_decimal_min) {
  s21_decimal dst = {{0, 0, 0, 0}};
  int src = INT32_MIN;
  int result = s21_from_int_to_decimal(src, &dst);
  int scale = get_scale(dst);
  int sign = get_sign(dst);
  ck_assert_int_eq(result, 0);
  ck_assert_uint_eq(2147483648u, dst.bits[0]);
  ck_assert_uint_eq(0, dst.bits[1]);
  ck_assert_uint_eq(0, dst.bits[2]);
  ck_assert_int_eq(0, scale);
  ck_assert_int_eq(1, sign);
}
END_TEST

START_TEST(test_s21_from_int_to_decimal_error) {
  int src = 12;
  int result = s21_from_int_to_decimal(src, NULL);
  ck_assert_int_eq(result, 1);
}
END_TEST

Suite *int_to_decimal_suite() {
  Suite *s = suite_create("s21_int_to_decimal");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_from_int_to_decimal_positive);
  tcase_add_test(tc_core, test_s21_from_int_to_decimal_negative);
  tcase_add_test(tc_core, test_s21_from_int_to_decimal_zero);
  tcase_add_test(tc_core, test_s21_from_int_to_decimal_min);
  tcase_add_test(tc_core, test_s21_from_int_to_decimal_error);
}