#include <stdint.h>

typedef struct {
  unsigned int bits[4];
} s21_decimal;

#define OK 0
#define ERROR 1

int get_sign(s21_decimal);
void set_sign(s21_decimal *, int);
int get_scale(s21_decimal);
void set_scale(s21_decimal *, int);
int is_zero(s21_decimal);
int is_valid_decimal(s21_decimal);
void reduce_scale(s21_decimal *);
int increase_scale(s21_decimal *);
void normalize_scale(s21_decimal *, s21_decimal *);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);