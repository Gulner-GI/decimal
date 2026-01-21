#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int status = OK;
  if (!dst) {
    status = ERROR;
  } else {
    unsigned long int src_abs;
    if (src < 0) {
      set_sign(dst, 1);
      src_abs = (unsigned long int)(-(long)src);
    } else {
      set_sign(dst, 0);
      src_abs = src;
    }
    dst->bits[0] = src_abs;
    dst->bits[1] = 0;
    dst->bits[2] = 0;
    set_scale(dst, 0);
  }
  return status;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int status = OK;
  if (!dst) {
    status = ERROR;
  } else {
    int scale = 0;
    double src_abs = src;
    if (src < 0) {
      set_sign(dst, 1);
    } else {
      set_sign(dst, 0);
    }
    while (src_abs - (long)src_abs > 0 && scale < 28) {
      src_abs *= 10;
      scale++;
    }
    dst->bits[0] = (unsigned int)src_abs;
    dst->bits[1] = 0;
    dst->bits[2] = 0;
    set_scale(dst, scale);
  }
  return status;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int status = OK;
  return status;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int status = OK;
  return status;
}