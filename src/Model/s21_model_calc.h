#ifndef S21_MODEL_CALC
#define S21_MODEL_CALC

#include <cstring>
#include <iostream>
#include <stack>
#include <string>

#define STACK_MAX_SIZE = 256;
#define SIGN_SYM "x1234567890(-"
#define OPER_LET "cstal"
#define NUM "1234567890"

enum codeOfValue {
  X,          // 0
  Plus,       // 1 +
  Minus,      // 2 -
  Div,        // 3 /
  Mul,        // 4 *
  Pow,        // 5 ^
  Bracket_0,  // 6 (
  Bracket_1,  // 7 )
  Sin,        // 8 sin
  Cos,        // 9 cos
  Tan,        // 10 tan
  Atan,       // 11 atan
  Ln,         // 12 ln
  Log,        // 13 log
  Umin,       // 14 tilda
  Sqrt,       // 15 корень
  ASin,       // 16 asin
  ACos,       // 17 acos
  NUMBERS,    // 18 числа
  MOOD,       // 19 MOOD
  Umax,       //  20 unar+
};

namespace s21 {

struct Nodevalue {
  double number;    // число?
  int codeOfValue;  // код значения?
  int priority;     // приоритет
};

class ModelCalc {
 private:
  double value_;

 public:
  void string_validator(std::string str);
  int check_function(std::string str, size_t i);
  char str_to_correct_str(std::string &str, size_t i);
  void prepare_str(std::string str1, std::string &str2);
  void parser(std::string stroka, double x, std::stack<s21::Nodevalue> &stack_);
  void polish(std::stack<Nodevalue> &stack_);
  void calculator(std::string str, double *result_new, double x);
  void s21_credit_calc_anu(double sum, double persent, int time,
                           double *result);
  void s21_credit_calc_diff(double sum, double persent, int time,
                            double *result, double *result2,
                            double *result_persent);
  void s21_vklad_calc(double sum, int time, double persent, double *result,
                      double *nalog_na_vklad, double *persent_na_vkald);
  ModelCalc(){};
  ~ModelCalc(){};
};
}  // namespace s21

#endif
