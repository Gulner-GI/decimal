#include <check.h>

#include "../s21_decimal.h"

START_TEST(test_0) {
  s21_decimal d = {{0, 0, 0, 0b10000000111111110000000000000000}};
  ck_assert_int_eq(is_zero(d), 1);
}
END_TEST

START_TEST(test_1) {
  s21_decimal d = {{10, 10, 10, 0b00000000111111110000000000000000}};
  ck_assert_int_eq(is_zero(d), 0);
}
END_TEST

START_TEST(test_2) {
  s21_decimal d = {{0, 10, 10, 0b00000000111111110000000000000000}};
  ck_assert_int_eq(is_zero(d), 0);
}
END_TEST

START_TEST(test_3) {
  s21_decimal d = {{10, 0, 10, 0b00000000111111110000000000000000}};
  ck_assert_int_eq(is_zero(d), 0);
}
END_TEST

START_TEST(test_4) {
  s21_decimal d = {{10, 10, 0, 0b00000000111111110000000000000000}};
  ck_assert_int_eq(is_zero(d), 0);
}
END_TEST

START_TEST(test_5) {
  s21_decimal d = {{0, 0, 10, 0b00000000111111110000000000000000}};
  ck_assert_int_eq(is_zero(d), 0);
}
END_TEST

START_TEST(test_6) {
  s21_decimal d = {{0, 10, 0, 0b00000000111111110000000000000000}};
  ck_assert_int_eq(is_zero(d), 0);
}
END_TEST

START_TEST(test_7) {
  s21_decimal d = {{10, 0, 0, 0b00000000111111110000000000000000}};
  ck_assert_int_eq(is_zero(d), 0);
}
END_TEST

Suite *is_zero_suite(void) {
  Suite *s = suite_create("s21_is_zero");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_0);
  tcase_add_test(tc_core, test_1);
  tcase_add_test(tc_core, test_2);
  tcase_add_test(tc_core, test_3);
  tcase_add_test(tc_core, test_4);
  tcase_add_test(tc_core, test_5);
  tcase_add_test(tc_core, test_6);
  tcase_add_test(tc_core, test_7);

  suite_add_tcase(s, tc_core);
  return s;
}