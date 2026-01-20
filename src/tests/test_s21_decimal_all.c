#include <check.h>
#include <stdlib.h>

#include "../s21_decimal.h"

Suite* get_sign_suite(void);
Suite* set_sign_suite(void);
Suite* get_scale_suite(void);
Suite* set_scale_suite(void);
Suite* is_zero_suite(void);
Suite* is_valid_decimal_suite(void);
Suite* reduce_scale_suite(void);

int main(void) {
  int failed = 0;

  Suite* s21_string_tests[] = {get_sign_suite(),     set_sign_suite(),
                               get_scale_suite(),    set_scale_suite(),
                               is_zero_suite(),      is_valid_decimal_suite(),
                               reduce_scale_suite(), NULL};

  for (int i = 0; s21_string_tests[i] != NULL; i++) {
    SRunner* sr = srunner_create(s21_string_tests[i]);

    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }

  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}