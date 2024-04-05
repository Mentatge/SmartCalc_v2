#include "s21_model_calc.h"

/// @brief аннуитетный кредитный калькулятор
/// @param sum сумма кредита
/// @param persent процент кредита
/// @param time время кредита
/// @param result возвращаемое значени суммы выплаты
void s21::ModelCalc::s21_credit_calc_anu(double sum, double persent, int time,
                                         double *result) {
  double koif = 0;
  double i = persent / 1200;
  koif = i * pow((1 + i), time) / (pow((1 + i), time) - 1);
  *result = koif * sum;
}

/// @brief дифферциальный калькулятор
/// @param sum сумма кредита
/// @param persent процент кредита
/// @param time время
/// @param result возвращаемое значение суммы
/// @param result2 результат функции два аннуитетный процента
/// @param result_persent суммарный процент
void s21::ModelCalc::s21_credit_calc_diff(double sum, double persent, int time,
                                          double *result, double *result2,
                                          double *result_persent) {
  double month_pay = sum / time;
  *result = month_pay + sum * persent / 1200;
  for (int i = 0; i < time; i++) {
    *result_persent += sum * persent / 1200;
    *result2 = sum * persent / 1200 + month_pay;
    sum -= month_pay;
  }
}
