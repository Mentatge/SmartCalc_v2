#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Model/s21_model_calc.h"

namespace s21 {

class Controller {
 public:
  Controller(){};
  ~Controller(){};
  void calculator_controller(std::string str, double *result_new, double x);
  void credit_controller_credit_calc_anu(double sum, double persent, int time,
                                         double *result);
  void credit_controller_credit_calc_diff(double sum, double persent, int time,
                                          double *result, double *result2,
                                          double *result_persent);
  void vklad_controller(double sum, int time, double persent, double *result,
                        double *nalog_na_vklad, double *persent_na_vkald);

 private:
  s21::ModelCalc model_;
};
}  // namespace s21

#endif
