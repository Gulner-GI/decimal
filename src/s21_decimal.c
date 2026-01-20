#include "s21_decimal.h"

int get_sign(s21_decimal dec) {
  int result = (dec.bits[3] >> 31) & 1;
  return result;
}

void set_sign(s21_decimal* dec, int sign) {
  if (sign) {
    dec->bits[3] |= (1 << 31);
  } else {
    dec->bits[3] &= ~(1 << 31);
  }
}

int get_scale(s21_decimal dec) {
  int result = (dec.bits[3] >> 16) & 0b11111111;
  return result;
}

void set_scale(s21_decimal* dec, int scale) {
  dec->bits[3] &= ~(0b11111111 << 16);
  dec->bits[3] |= (scale & 0b11111111) << 16;
}

int is_zero(s21_decimal dec) {
  return (dec.bits[0] == 0 && dec.bits[1] == 0 && dec.bits[2] == 0);
}

int is_valid_decimal(s21_decimal dec) {
  int scale = get_scale(dec);
  return (scale >= 0 && scale <= 28);
}

void reduce_scale(s21_decimal* dec) {
  while (get_scale(*dec) > 28) {
    int remainder = 0;
    for (int i = 2; i >= 0; i--) {
      uint64_t temp = ((uint64_t)remainder << 32) + dec->bits[i];
      dec->bits[i] = temp / 10;
      remainder = temp % 10;
    }
    set_scale(dec, get_scale(*dec) - 1);
  }
}

int increase_scale(s21_decimal* dec) {
  int result = 0;
  unsigned int carry = 0;

  int scale = get_scale(*dec);
  for (int i = 0; i < 3; i++) {
    uint64_t temp = (uint64_t)dec->bits[i] * 10 + carry;
    dec->bits[i] = (unsigned int)(temp & 0b11111111111111111111111111111111);
    carry = (unsigned int)(temp >> 32);
  }

  if (carry != 0) {
    result = 1;
  } else {
    scale++;
    set_scale(dec, scale);
  }

  return result;
}

void normalize_scale(s21_decimal* dec1, s21_decimal* dec2) {
  int scale1 = get_scale(*dec1);
  if (scale1 > 28) {
    reduce_scale(dec1);
    scale1 = get_scale(*dec1);
  }

  int scale2 = get_scale(*dec2);
  if (scale2 > 28) {
    reduce_scale(dec2);
    scale2 = get_scale(*dec2);
  }

  while (scale1 < scale2) {
    scale1++;
    increase_scale(dec1);
  }
  set_scale(dec1, scale1);

  while (scale2 < scale1) {
    scale2++;
    increase_scale(dec2);
  }
  set_scale(dec2, scale2);
}