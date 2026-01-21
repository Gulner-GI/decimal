#include <check.h>

#include "../s21_decimal.h"

START_TEST(test_scale_0) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000010000000000000000};
  set_scale(&d, 0);
  ck_assert_int_eq(get_scale(d), 0);
}
END_TEST

START_TEST(test_scale_1) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 1);
  ck_assert_int_eq(get_scale(d), 1);
}
END_TEST

START_TEST(test_scale_2) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 2);
  ck_assert_int_eq(get_scale(d), 2);
}
END_TEST

START_TEST(test_scale_3) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 3);
  ck_assert_int_eq(get_scale(d), 3);
}
END_TEST

START_TEST(test_scale_4) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 4);
  ck_assert_int_eq(get_scale(d), 4);
}
END_TEST

START_TEST(test_scale_5) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 5);
  ck_assert_int_eq(get_scale(d), 5);
}
END_TEST

START_TEST(test_scale_6) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 6);
  ck_assert_int_eq(get_scale(d), 6);
}
END_TEST

START_TEST(test_scale_7) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 7);
  ck_assert_int_eq(get_scale(d), 7);
}
END_TEST

START_TEST(test_scale_8) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 8);
  ck_assert_int_eq(get_scale(d), 8);
}
END_TEST

START_TEST(test_scale_9) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 9);
  ck_assert_int_eq(get_scale(d), 9);
}
END_TEST

START_TEST(test_scale_10) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 10);
  ck_assert_int_eq(get_scale(d), 10);
}
END_TEST

START_TEST(test_scale_11) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 11);
  ck_assert_int_eq(get_scale(d), 11);
}
END_TEST

START_TEST(test_scale_12) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 12);
  ck_assert_int_eq(get_scale(d), 12);
}
END_TEST

START_TEST(test_scale_13) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 13);
  ck_assert_int_eq(get_scale(d), 13);
}
END_TEST

START_TEST(test_scale_14) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 14);
  ck_assert_int_eq(get_scale(d), 14);
}
END_TEST

START_TEST(test_scale_15) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 15);
  ck_assert_int_eq(get_scale(d), 15);
}
END_TEST

START_TEST(test_scale_16) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 16);
  ck_assert_int_eq(get_scale(d), 16);
}
END_TEST

START_TEST(test_scale_17) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 17);
  ck_assert_int_eq(get_scale(d), 17);
}
END_TEST

START_TEST(test_scale_18) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 18);
  ck_assert_int_eq(get_scale(d), 18);
}
END_TEST

START_TEST(test_scale_19) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 19);
  ck_assert_int_eq(get_scale(d), 19);
}
END_TEST

START_TEST(test_scale_20) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 20);
  ck_assert_int_eq(get_scale(d), 20);
}
END_TEST

START_TEST(test_scale_21) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 21);
  ck_assert_int_eq(get_scale(d), 21);
}
END_TEST

START_TEST(test_scale_22) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 22);
  ck_assert_int_eq(get_scale(d), 22);
}
END_TEST

START_TEST(test_scale_23) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 23);
  ck_assert_int_eq(get_scale(d), 23);
}
END_TEST

START_TEST(test_scale_24) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 24);
  ck_assert_int_eq(get_scale(d), 24);
}
END_TEST

START_TEST(test_scale_25) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 25);
  ck_assert_int_eq(get_scale(d), 25);
}
END_TEST

START_TEST(test_scale_26) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 26);
  ck_assert_int_eq(get_scale(d), 26);
}
END_TEST

START_TEST(test_scale_27) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 27);
  ck_assert_int_eq(get_scale(d), 27);
}
END_TEST

START_TEST(test_scale_28) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  set_scale(&d, 28);
  ck_assert_int_eq(get_scale(d), 28);
}
END_TEST

Suite *set_scale_suite(void) {
  Suite *s = suite_create("s21_set_scale");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_scale_0);
  tcase_add_test(tc_core, test_scale_1);
  tcase_add_test(tc_core, test_scale_2);
  tcase_add_test(tc_core, test_scale_3);
  tcase_add_test(tc_core, test_scale_4);
  tcase_add_test(tc_core, test_scale_5);
  tcase_add_test(tc_core, test_scale_6);
  tcase_add_test(tc_core, test_scale_7);
  tcase_add_test(tc_core, test_scale_8);
  tcase_add_test(tc_core, test_scale_9);
  tcase_add_test(tc_core, test_scale_10);
  tcase_add_test(tc_core, test_scale_11);
  tcase_add_test(tc_core, test_scale_12);
  tcase_add_test(tc_core, test_scale_13);
  tcase_add_test(tc_core, test_scale_14);
  tcase_add_test(tc_core, test_scale_15);
  tcase_add_test(tc_core, test_scale_16);
  tcase_add_test(tc_core, test_scale_17);
  tcase_add_test(tc_core, test_scale_18);
  tcase_add_test(tc_core, test_scale_19);
  tcase_add_test(tc_core, test_scale_20);
  tcase_add_test(tc_core, test_scale_21);
  tcase_add_test(tc_core, test_scale_22);
  tcase_add_test(tc_core, test_scale_23);
  tcase_add_test(tc_core, test_scale_24);
  tcase_add_test(tc_core, test_scale_25);
  tcase_add_test(tc_core, test_scale_26);
  tcase_add_test(tc_core, test_scale_27);
  tcase_add_test(tc_core, test_scale_28);

  suite_add_tcase(s, tc_core);
  return s;
}