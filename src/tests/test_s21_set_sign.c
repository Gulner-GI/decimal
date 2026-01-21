#include <check.h>

#include "../s21_decimal.h"

START_TEST(test_positive_sign) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b10000000111111110000000000000000};
  set_sign(&d, 0);
  ck_assert_int_eq(get_sign(d), 0);
}
END_TEST

START_TEST(test_negative_sign) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000111111110000000000000000};
  set_sign(&d, 1);
  ck_assert_int_eq(get_sign(d), 1);
}
END_TEST

Suite *set_sign_suite(void) {
  Suite *s = suite_create("s21_set_sign");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_positive_sign);
  tcase_add_test(tc_core, test_negative_sign);

  suite_add_tcase(s, tc_core);
  return s;
}