#include <stdio.h>

#include "s21_decimal.h"

void print_decimal(s21_decimal dec);

int main(void) {
  s21_decimal d = {
      0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
      0b11111111111111111111111111111111, 0b10000000111111110000000000000000};

  print_decimal(d);

  printf("Sign: %d\n", get_sign(d));
  printf("Scale: %d\n", get_scale(d));

  printf("is valid scale: %d\n", is_valid_decimal(d));
  set_scale(&d, 5);
  printf("Scale: %d\n", get_scale(d));
  printf("is valid scale: %d\n", is_valid_decimal(d));

  return 0;
}

void print_decimal(s21_decimal dec) {
  for (int i = 0; i < 4; i++) {
    for (int j = 31; j >= 0; j--) {
      int bit = (dec.bits[i] >> j) & 1;
      printf("%d", bit);

      if (j % 8 == 0 && j != 0) {
        printf(" ");
      }
    }

    printf("\n");
  }

  printf("\n\n");

  for (int i = 0; i < 4; i++) {
    printf("%u", dec.bits[i]);

    if (i < 3) {
      printf(" ");
    }
  }

  printf("\n");
}