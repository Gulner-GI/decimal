#include <stdint.h>

typedef struct {
  unsigned int bits[4];
} s21_decimal;

int get_sign(s21_decimal);
void set_sign(s21_decimal*, int);
int get_scale(s21_decimal);
void set_scale(s21_decimal*, int);
int is_zero(s21_decimal);
int is_valid_decimal(s21_decimal);
void reduce_scale(s21_decimal*);
int increase_scale(s21_decimal*);
void normalize_scale(s21_decimal*, s21_decimal*);