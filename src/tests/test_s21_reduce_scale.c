#include <check.h>

#include "../s21_decimal.h"

// test_reduce_scale_with_remainder
// test_reduce_scale_zero_value
// test_reduce_scale_preserves_sign

START_TEST(test_reduce_scale_no_change_when_scale_valid) {
  s21_decimal d = {{100, 0, 0, 0b00000000000111000000000000000000}};
  s21_decimal original = {{100, 0, 0, 0b00000000000111000000000000000000}};

  reduce_scale(&d);

  ck_assert_uint_eq(d.bits[0], original.bits[0]);
  ck_assert_uint_eq(d.bits[1], original.bits[1]);
  ck_assert_uint_eq(d.bits[2], original.bits[2]);
  ck_assert_uint_eq(d.bits[3], original.bits[3]);
}
END_TEST

START_TEST(test_reduce_scale_reduce_by_one) {
  s21_decimal d = {{20, 0, 0, 0b00000000000111010000000000000000}};
  s21_decimal original = {{2, 0, 0, 0b00000000000111000000000000000000}};

  reduce_scale(&d);

  ck_assert_uint_eq(d.bits[0], original.bits[0]);
  ck_assert_uint_eq(d.bits[1], original.bits[1]);
  ck_assert_uint_eq(d.bits[2], original.bits[2]);
  ck_assert_uint_eq(d.bits[3], original.bits[3]);
}
END_TEST

START_TEST(test_reduce_scale_with_carry_from_middle) {
  s21_decimal d = {{0, 1, 0, 0b00000000000111010000000000000000}};
  s21_decimal original = {
      {429496729, 0, 0, 0b00000000000111000000000000000000}};

  reduce_scale(&d);

  ck_assert_uint_eq(d.bits[0], original.bits[0]);
  ck_assert_uint_eq(d.bits[1], original.bits[1]);
  ck_assert_uint_eq(d.bits[2], original.bits[2]);
  ck_assert_uint_eq(d.bits[3], original.bits[3]);
}
END_TEST

START_TEST(test_reduce_scale_with_carry_from_high) {
  s21_decimal d = {{0, 0, 1, 0b00000000000111010000000000000000}};
  s21_decimal original = {
      {2576980377, 429496729, 0, 0b00000000000111000000000000000000}};

  reduce_scale(&d);

  ck_assert_uint_eq(d.bits[0], original.bits[0]);
  ck_assert_uint_eq(d.bits[1], original.bits[1]);
  ck_assert_uint_eq(d.bits[2], original.bits[2]);
  ck_assert_uint_eq(d.bits[3], original.bits[3]);
}
END_TEST

START_TEST(test_reduce_scale_reduce_multiple_times) {
  s21_decimal d = {{1000000000, 0, 0, 0b00000000000111110000000000000000}};
  s21_decimal original = {{1000000, 0, 0, 0b00000000000111000000000000000000}};

  reduce_scale(&d);

  ck_assert_uint_eq(d.bits[0], original.bits[0]);
  ck_assert_uint_eq(d.bits[1], original.bits[1]);
  ck_assert_uint_eq(d.bits[2], original.bits[2]);
  ck_assert_uint_eq(d.bits[3], original.bits[3]);
}
END_TEST

Suite *reduce_scale_suite(void) {
  Suite *s = suite_create("s21_reduce_scale");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_reduce_scale_no_change_when_scale_valid);
  tcase_add_test(tc_core, test_reduce_scale_reduce_by_one);
  tcase_add_test(tc_core, test_reduce_scale_with_carry_from_middle);
  tcase_add_test(tc_core, test_reduce_scale_with_carry_from_high);
  tcase_add_test(tc_core, test_reduce_scale_reduce_multiple_times);

  suite_add_tcase(s, tc_core);
  return s;
}