#include "s21_model_calc.h"

void s21::ModelCalc::s21_vklad_calc(double sum, int time, double persent,
                                    double *result, double *nalog_na_vklad,
                                    double *persent_na_vkald) {
  *result = sum + (sum * persent / 1200 * time);
  if (persent > 18.) {
    *nalog_na_vklad = (*result - sum) * 0.35;
  } else {
    *nalog_na_vklad = 0;
  }
  *persent_na_vkald = *result - sum;
}
