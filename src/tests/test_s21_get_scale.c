#include <check.h>

#include "../s21_decimal.h"

START_TEST(test_scale_0) {
  s21_decimal d = {10, 10, 10, 0b00000000000000000000000000000000};
  ck_assert_int_eq(get_scale(d), 0);
}
END_TEST

START_TEST(test_scale_1) {
  s21_decimal d = {10, 10, 10, 0b00000000000000010000000000000000};
  ck_assert_int_eq(get_scale(d), 1);
}
END_TEST

START_TEST(test_scale_2) {
  s21_decimal d = {10, 10, 10, 0b00000000000000100000000000000000};
  ck_assert_int_eq(get_scale(d), 2);
}
END_TEST

START_TEST(test_scale_3) {
  s21_decimal d = {10, 10, 10, 0b00000000000000110000000000000000};
  ck_assert_int_eq(get_scale(d), 3);
}
END_TEST

START_TEST(test_scale_4) {
  s21_decimal d = {10, 10, 10, 0b00000000000001000000000000000000};
  ck_assert_int_eq(get_scale(d), 4);
}
END_TEST

START_TEST(test_scale_5) {
  s21_decimal d = {10, 10, 10, 0b00000000000001010000000000000000};
  ck_assert_int_eq(get_scale(d), 5);
}
END_TEST

START_TEST(test_scale_6) {
  s21_decimal d = {10, 10, 10, 0b00000000000001100000000000000000};
  ck_assert_int_eq(get_scale(d), 6);
}
END_TEST

START_TEST(test_scale_7) {
  s21_decimal d = {10, 10, 10, 0b00000000000001110000000000000000};
  ck_assert_int_eq(get_scale(d), 7);
}
END_TEST

START_TEST(test_scale_8) {
  s21_decimal d = {10, 10, 10, 0b00000000000010000000000000000000};
  ck_assert_int_eq(get_scale(d), 8);
}
END_TEST

START_TEST(test_scale_9) {
  s21_decimal d = {10, 10, 10, 0b00000000000010010000000000000000};
  ck_assert_int_eq(get_scale(d), 9);
}
END_TEST

START_TEST(test_scale_10) {
  s21_decimal d = {10, 10, 10, 0b00000000000010100000000000000000};
  ck_assert_int_eq(get_scale(d), 10);
}
END_TEST

START_TEST(test_scale_11) {
  s21_decimal d = {10, 10, 10, 0b00000000000010110000000000000000};
  ck_assert_int_eq(get_scale(d), 11);
}
END_TEST

START_TEST(test_scale_12) {
  s21_decimal d = {10, 10, 10, 0b00000000000011000000000000000000};
  ck_assert_int_eq(get_scale(d), 12);
}
END_TEST

START_TEST(test_scale_13) {
  s21_decimal d = {10, 10, 10, 0b00000000000011010000000000000000};
  ck_assert_int_eq(get_scale(d), 13);
}
END_TEST

START_TEST(test_scale_14) {
  s21_decimal d = {10, 10, 10, 0b00000000000011100000000000000000};
  ck_assert_int_eq(get_scale(d), 14);
}
END_TEST

START_TEST(test_scale_15) {
  s21_decimal d = {10, 10, 10, 0b00000000000011110000000000000000};
  ck_assert_int_eq(get_scale(d), 15);
}
END_TEST

START_TEST(test_scale_16) {
  s21_decimal d = {10, 10, 10, 0b00000000000100000000000000000000};
  ck_assert_int_eq(get_scale(d), 16);
}
END_TEST

START_TEST(test_scale_17) {
  s21_decimal d = {10, 10, 10, 0b00000000000100010000000000000000};
  ck_assert_int_eq(get_scale(d), 17);
}
END_TEST

START_TEST(test_scale_18) {
  s21_decimal d = {10, 10, 10, 0b00000000000100100000000000000000};
  ck_assert_int_eq(get_scale(d), 18);
}
END_TEST

START_TEST(test_scale_19) {
  s21_decimal d = {10, 10, 10, 0b00000000000100110000000000000000};
  ck_assert_int_eq(get_scale(d), 19);
}
END_TEST

START_TEST(test_scale_20) {
  s21_decimal d = {10, 10, 10, 0b00000000000101000000000000000000};
  ck_assert_int_eq(get_scale(d), 20);
}
END_TEST

START_TEST(test_scale_21) {
  s21_decimal d = {10, 10, 10, 0b00000000000101010000000000000000};
  ck_assert_int_eq(get_scale(d), 21);
}
END_TEST

START_TEST(test_scale_22) {
  s21_decimal d = {10, 10, 10, 0b00000000000101100000000000000000};
  ck_assert_int_eq(get_scale(d), 22);
}
END_TEST

START_TEST(test_scale_23) {
  s21_decimal d = {10, 10, 10, 0b00000000000101110000000000000000};
  ck_assert_int_eq(get_scale(d), 23);
}
END_TEST

START_TEST(test_scale_24) {
  s21_decimal d = {10, 10, 10, 0b00000000000110000000000000000000};
  ck_assert_int_eq(get_scale(d), 24);
}
END_TEST

START_TEST(test_scale_25) {
  s21_decimal d = {10, 10, 10, 0b00000000000110010000000000000000};
  ck_assert_int_eq(get_scale(d), 25);
}
END_TEST

START_TEST(test_scale_26) {
  s21_decimal d = {10, 10, 10, 0b00000000000110100000000000000000};
  ck_assert_int_eq(get_scale(d), 26);
}
END_TEST

START_TEST(test_scale_27) {
  s21_decimal d = {10, 10, 10, 0b00000000000110110000000000000000};
  ck_assert_int_eq(get_scale(d), 27);
}
END_TEST

START_TEST(test_scale_28) {
  s21_decimal d = {10, 10, 10, 0b00000000000111000000000000000000};
  ck_assert_int_eq(get_scale(d), 28);
}
END_TEST

Suite *get_scale_suite(void) {
  Suite *s = suite_create("s21_get_scale");
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