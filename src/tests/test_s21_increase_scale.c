#include <check.h>

#include "../s21_decimal.h"

START_TEST(test_increase_scale_1) {
  s21_decimal test = {{123, 0, 0, 0b00000000000000000000000000000000}};
  set_scale(&test, 1);
  s21_decimal target = {{1230, 0, 0, 0b00000000000000000000000000000000}};
  set_scale(&target, 2);
  increase_scale(&test);
  ck_assert_uint_eq(test.bits[0], target.bits[0]);
  ck_assert_uint_eq(test.bits[1], target.bits[1]);
  ck_assert_uint_eq(test.bits[2], target.bits[2]);
  ck_assert_uint_eq(test.bits[3], target.bits[3]);
}
END_TEST

Suite *increase_scale_suite() {
  Suite *s = suite_create("s21_increase_scale");
  TCase *tc_core = tcase_create("create");
  tcase_add_test(tc_core, test_increase_scale_1);

  suite_add_tcase(s, tc_core);
  return s;
}