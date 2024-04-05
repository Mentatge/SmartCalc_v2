#include "s21_Controller.h"

void s21::Controller::calculator_controller(std::string str, double *result_new,
                                            double x) {
  model_.calculator(str, result_new, x);
}

void s21::Controller::credit_controller_credit_calc_anu(double sum,
                                                        double persent,
                                                        int time,
                                                        double *result) {
  model_.s21_credit_calc_anu(sum, persent, time, result);
}
void s21::Controller::credit_controller_credit_calc_diff(
    double sum, double persent, int time, double *result, double *result2,
    double *result_persent) {
  model_.s21_credit_calc_diff(sum, persent, time, result, result2,
                              result_persent);
}
void s21::Controller::vklad_controller(double sum, int time, double persent,
                                       double *result, double *nalog_na_vklad,
                                       double *persent_na_vkald) {
  model_.s21_vklad_calc(sum, time, persent, result, nalog_na_vklad,
                        persent_na_vkald);
}
