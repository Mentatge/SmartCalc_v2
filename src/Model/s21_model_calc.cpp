#include "s21_model_calc.h"

/// @brief функция по проверки строки на валидность
/// @param str принимаемое значение строка
void s21::ModelCalc::string_validator(std::string str) {
  int count_open_bracket = 0;
  int count_close_braket = 0;
  int error = 0;
  for (size_t i = 0; i < str.length(); i++) {
    if (str[i] == '(') ++count_open_bracket;
    if (str[i] == ')') ++count_close_braket;
    if (std::strchr("+-*/", str[i])) {
      if ((!(std::strchr(SIGN_SYM, str[i + 1]) ||
             std::strchr(OPER_LET, str[i + 1])) ||
           (str[i + 1] == '\0'))) {
        throw std::invalid_argument(
            "error oper_let");  // или прописать гдет через энам ошибки и
                                // вызывать их тут??
      }
    }
    if (str[i] == '.') {
      if (!std::strchr(NUM, str[i + 1]) || str[i + 1] == '\0')
        throw std::invalid_argument("error .");
    }
    if (std::strchr(OPER_LET, str[i]) && !error) {
      error = check_function(str, i);
      if (!error) {
        throw std::invalid_argument("error with check_function");
      }
    }
    if (error != 0) error--;

    if (str[i] == '(') {
      if (std::strchr("+*/)", str[i + 1]))
        throw std::invalid_argument("error ( with +*/)");
    }
  }
  if (count_open_bracket - count_close_braket != 0)
    throw std::invalid_argument("error of count ( and )");
}
/// @brief проверка функции, трансформация строки
/// @param str строка
/// @param i из цикла фор текущая позиция
/// @return возвращает значение i
int s21::ModelCalc::check_function(std::string str, size_t i) {
  if (str[i] == 'c' && (i + 4 < str.length())) {
    if (str[i + 1] == 'o' && str[i + 2] == 's' && str[i + 3] == '(' &&
        (std::strchr(SIGN_SYM, str[i + 4]) ||
         std::strchr(OPER_LET, str[i + 4]))) {
      return 3;
    }
  }
  if (str[i] == 's' && (i + 4 < str.length())) {
    if (str[i + 1] == 'i' && str[i + 2] == 'n' && str[i + 3] == '(' &&
        (std::strchr(SIGN_SYM, str[i + 4]) ||
         std::strchr(OPER_LET, str[i + 4]))) {
      return 3;
    }
  }
  if (str[i] == 't' && (i + 4 < str.length())) {
    if (str[i + 1] == 'a' && str[i + 2] == 'n' && str[i + 3] == '(' &&
        (std::strchr(SIGN_SYM, str[i + 4]) ||
         std::strchr(OPER_LET, str[i + 4]))) {
      return 3;
    }
  }
  if (str[i] == 'a' && (i + 5 < str.length())) {
    if (str[i + 1] == 'c' && str[i + 2] == 'o' && str[i + 3] == 's' &&
        str[i + 4] == '(' &&
        (std::strchr(SIGN_SYM, str[i + 5]) ||
         std::strchr(OPER_LET, str[i + 5]))) {
      return 4;
    }
  }
  if (str[i] == 'a' && (i + 5 < str.length())) {
    if (str[i + 1] == 's' && str[i + 2] == 'i' && str[i + 3] == 'n' &&
        str[i + 4] == '(' &&
        (std::strchr(SIGN_SYM, str[i + 5]) ||
         std::strchr(OPER_LET, str[i + 5]))) {
      return 4;
    }
  }
  if (str[i] == 'a' && (i + 5 < str.length())) {
    if (str[i + 1] == 't' && str[i + 2] == 'a' && str[i + 3] == 'n' &&
        str[i + 4] == '(' &&
        (std::strchr(SIGN_SYM, str[i + 5]) ||
         std::strchr(OPER_LET, str[i + 5]))) {
      return 4;
    }
  }
  if (str[i] == 's' && (i + 5 < str.length())) {
    if (str[i + 1] == 'q' && str[i + 2] == 'r' && str[i + 3] == 't' &&
        str[i + 4] == '(' &&
        (std::strchr(SIGN_SYM, str[i + 5]) ||
         std::strchr(OPER_LET, str[i + 5]))) {
      return 4;
    }
  }
  if (str[i] == 'l' && (i + 3 < str.length())) {
    if (str[i + 1] == 'n' && str[i + 2] == '(' &&
        (std::strchr(SIGN_SYM, str[i + 3]) ||
         std::strchr(OPER_LET, str[i + 3]))) {
      return 2;
    }
  }
  if (str[i] == 'l' && (i + 4 < str.length())) {
    if (str[i + 1] == 'o' && str[i + 2] == 'g' && str[i + 3] == '(' &&
        (std::strchr(SIGN_SYM, str[i + 4]) ||
         std::strchr(OPER_LET, str[i + 4]))) {
      return 3;
    }
  }
  if (str[i] == 'm' && (i + 3 < str.length())) {
    if (str[i + 1] == 'o' && str[i + 2] == 'd' &&
        (std::strchr(SIGN_SYM, str[i + 3]) ||
         std::strchr(OPER_LET, str[i + 3]))) {
      return 3;
    }
  }

  return 0;
}
/// @brief трансормация строки в нормальное значение
/// @param str строка
/// @param i позиция в строке
/// @return возвращаем одну чар которая заменяет
char s21::ModelCalc::str_to_correct_str(std::string &str, size_t i) {
  if (str[i] == 'c' && (i + 4 < str.length())) {
    if (str[i + 1] == 'o' && str[i + 2] == 's' && str[i + 3] == '(' &&
        (std::strchr(SIGN_SYM, str[i + 4]) ||
         std::strchr(OPER_LET, str[i + 4]))) {  // замена всех стрсшр на стд
      return 'c';
    }
  }
  if (str[i] == 's' && (i + 4 < str.length())) {
    if (str[i + 1] == 'i' && str[i + 2] == 'n' && str[i + 3] == '(' &&
        (std::strchr(SIGN_SYM, str[i + 4]) ||
         std::strchr(OPER_LET, str[i + 4]))) {
      return 's';
    }
  }
  if (str[i] == 't' && (i + 4 < str.length())) {
    if (str[i + 1] == 'a' && str[i + 2] == 'n' && str[i + 3] == '(' &&
        (std::strchr(SIGN_SYM, str[i + 4]) ||
         std::strchr(OPER_LET, str[i + 4]))) {
      return 't';
    }
  }
  if (str[i] == 'a' && (i + 5 < str.length())) {
    if (str[i + 1] == 'c' && str[i + 2] == 'o' && str[i + 3] == 's' &&
        str[i + 4] == '(' &&
        (std::strchr(SIGN_SYM, str[i + 5]) ||
         std::strchr(OPER_LET, str[i + 5]))) {
      return 'C';
    }
  }
  if (str[i] == 'a' && (i + 5 < str.length())) {
    if (str[i + 1] == 's' && str[i + 2] == 'i' && str[i + 3] == 'n' &&
        str[i + 4] == '(' &&
        (std::strchr(SIGN_SYM, str[i + 5]) ||
         std::strchr(OPER_LET, str[i + 5]))) {
      return 'S';
    }
  }
  if (str[i] == 'a' && (i + 5 < str.length())) {
    if (str[i + 1] == 't' && str[i + 2] == 'a' && str[i + 3] == 'n' &&
        str[i + 4] == '(' &&
        (std::strchr(SIGN_SYM, str[i + 5]) ||
         std::strchr(OPER_LET, str[i + 5]))) {
      return 'T';
    }
  }
  if (str[i] == 's' && (i + 5 < str.length())) {
    if (str[i + 1] == 'q' && str[i + 2] == 'r' && str[i + 3] == 't' &&
        str[i + 4] == '(' &&
        (std::strchr(SIGN_SYM, str[i + 5]) ||
         std::strchr(OPER_LET, str[i + 5]))) {
      return 'K';
    }
  }
  if (str[i] == 'l' && (i + 3 < str.length())) {
    if (str[i + 1] == 'n' && str[i + 2] == '(' &&
        (std::strchr(SIGN_SYM, str[i + 3]) ||
         std::strchr(OPER_LET, str[i + 3]))) {
      return 'l';
    }
  }
  if (str[i] == 'l' && (i + 4 < str.length())) {
    if (str[i + 1] == 'o' && str[i + 2] == 'g' && str[i + 3] == '(' &&
        (std::strchr(SIGN_SYM, str[i + 4]) ||
         std::strchr(OPER_LET, str[i + 4]))) {
      return 'L';
    }
  }
  if (str[i] == 'm' && (i + 3 < str.length())) {
    if (str[i + 1] == 'o' && str[i + 2] == 'd' &&
        (std::strchr(SIGN_SYM, str[i + 3]) ||
         std::strchr(OPER_LET, str[i + 3]))) {
      return '%';
    }
  }
  if ((str[i] == '-' && i == 0) ||
      (i > 0 && str[i] == '-' && str[i - 1] == '(')) {
    return '~';
  }
  return '\0';
}
/// @brief подготовка строки
/// @param str1 текущая строка
/// @param str2 строка после преобразования
void s21::ModelCalc::prepare_str(std::string str1, std::string &str2) {
  char value;
  for (std::string::size_type i = 0; i < str1.size(); i++) {
    value = str_to_correct_str(str1, i);
    if (value) {
      str2.push_back(value);
      if (value == 'c') i = i + 2;
      if (value == 's') i = i + 2;
      if (value == 't') i = i + 2;
      if (value == 'C') i = i + 3;
      if (value == 'S') i = i + 3;
      if (value == 'T') i = i + 3;
      if (value == 'K') i = i + 3;
      if (value == 'l') i++;
      if (value == 'L') i = i + 2;
      if (value == '%') i = i + 2;
      value = 0;  // >>>
    } else {
      str2.push_back(str1[i]);
    }
  }
  //  str2[j] = '\0';
}
/// @brief парсер
/// @param stroka строка
/// @param x обычный х
/// @param stack_ стэк
void s21::ModelCalc::parser(std::string stroka, double x,
                            std::stack<s21::Nodevalue> &stack_) {
  s21::ModelCalc::string_validator(stroka);
  std::string stroka2;
  prepare_str(stroka, stroka2);
  for (std::string::size_type i = 0; i < stroka2.length(); i++) {
    if (std::strchr("0123456789", stroka2[i])) {  // чет ругается
      double d = atof(&stroka2[i]);
      for (std::string::size_type k = i;
           std::strchr(".0123456789eE", stroka2[i]); i++, k++) {
        continue;
      }
      stack_.push({d, NUMBERS, 1});
    }
    if (stroka2[i] == '+') {
      stack_.push(Nodevalue({0, Plus, 2}));
    }
    if (stroka2[i] == '-') {
      stack_.push({0, Minus, 2});
    }
    if (stroka2[i] == '(') {
      stack_.push({0, Bracket_0, 1});
    }
    if (stroka2[i] == ')') {
      stack_.push({0, Bracket_1, 1});
    }
    if (stroka2[i] == '^') {
      stack_.push({0, Pow, 4});
    }
    if (stroka2[i] == '/') {
      stack_.push({0, Div, 3});
    }
    if (stroka2[i] == '*') {
      stack_.push({0, Mul, 3});
    }
    if (stroka2[i] == 'L') {  // деятичный логарифм
      stack_.push({0, Log, 3});
    }
    if (stroka2[i] == 'l') {  // обычный логарифм
      stack_.push({0, Ln, 3});
    }
    if (stroka2[i] == 'c') {  // cos
      stack_.push({0, Cos, 3});
    }
    if (stroka2[i] == 'C') {  // acos
      stack_.push({0, ACos, 3});
    }
    if (stroka2[i] == 's') {
      stack_.push({0, Sin, 3});
    }
    if (stroka2[i] == 'S') {
      stack_.push({0, ASin, 3});
    }
    if (stroka2[i] == 't') {
      stack_.push({0, Tan, 3});
    }
    if (stroka2[i] == 'T') {
      stack_.push({0, Atan, 3});
    }
    if (stroka2[i] == 'K') {
      stack_.push({0, Sqrt, 3});
    }
    if (stroka2[i] == 'x') {
      stack_.push({x, X, 0});
    }
    if (stroka2[i] == '~') {
      stack_.push({0, Umin, 4});
    }
    if (stroka2[i] == '!') {
      stack_.push({0, Umax, 4});
    }
    if (stroka2[i] == '%') {
      stack_.push({0, MOOD, 3});
    }
  }
}
/// @brief перевод в польскую нотацию
/// @param stack_ стэк
void s21::ModelCalc::polish(std::stack<Nodevalue> &stack_) {
  std::stack<Nodevalue> revese_head;  // реверсный где будем раздирать
  std::stack<Nodevalue> stack_for_pop;  // знаки и числа
  std::stack<Nodevalue> stack_result;
  while (stack_.size() != 0) {
    revese_head.push(stack_.top());  // надо проверить будет
    stack_.pop();
  }

  while (revese_head.size() != 0) {
    if (revese_head.top().codeOfValue == NUMBERS ||
        revese_head.top().codeOfValue == X) {
      stack_result.push({revese_head.top().number,
                         revese_head.top().codeOfValue,
                         revese_head.top().priority});
    } else if (revese_head.top().codeOfValue != NUMBERS ||
               revese_head.top().codeOfValue != X) {
      if (stack_for_pop.size() == 0) {  // а нахуя я это делал?? работает кекв
        stack_for_pop.push({revese_head.top().number,
                            revese_head.top().codeOfValue,
                            revese_head.top().priority});
      } else if (revese_head.top().codeOfValue) {
        if (revese_head.top().codeOfValue == Sin ||
            revese_head.top().codeOfValue == ASin ||
            revese_head.top().codeOfValue == Cos ||
            revese_head.top().codeOfValue == ACos ||
            revese_head.top().codeOfValue == Tan ||
            revese_head.top().codeOfValue == Atan ||
            revese_head.top().codeOfValue == Ln ||
            revese_head.top().codeOfValue == Log ||
            revese_head.top().codeOfValue == Sqrt) {
          stack_for_pop.push({revese_head.top().number,
                              revese_head.top().codeOfValue,
                              revese_head.top().priority});
        } else if (revese_head.top().codeOfValue == Bracket_0) {
          stack_for_pop.push({revese_head.top().number,
                              revese_head.top().codeOfValue,
                              revese_head.top().priority});
        } else {
          if (revese_head.top().codeOfValue == Bracket_1) {
            while (stack_for_pop.size() != 0 &&
                   stack_for_pop.top().codeOfValue != Bracket_0) {
              stack_result.push({stack_for_pop.top().number,
                                 stack_for_pop.top().codeOfValue,
                                 stack_for_pop.top().priority});
              stack_for_pop.pop();
            }
            stack_for_pop.pop();  // выкидываем скобочку
          } else {
            while (stack_for_pop.size() != 0 &&
                   stack_for_pop.top().priority >= revese_head.top().priority) {
              stack_result.push(stack_for_pop.top());
              stack_for_pop.pop();
            }
            stack_for_pop.push({revese_head.top().number,
                                revese_head.top().codeOfValue,
                                revese_head.top().priority});
          }
        }
      }
    }
    revese_head.pop();
  }
  while (stack_for_pop.size() != 0) {
    stack_result.push(stack_for_pop.top());
    stack_for_pop.pop();
  }
  while (stack_result.size() != 0) {
    stack_.push(stack_result.top());  // надо проверить будет
    stack_result.pop();
  }
}
/// @brief калькулятор
/// @param str строка
/// @param result_new результат вычислений
/// @param x икс
/// @return
void s21::ModelCalc::calculator(std::string str, double *result_new, double x) {
  s21::ModelCalc f;
  std::stack<s21::Nodevalue> stack;
  f.parser(str, x, stack);  // блок трай кетч
  f.polish(stack);
  double result = 0;
  std::stack<s21::Nodevalue> stack_for_operation;
  std::stack<s21::Nodevalue> stack_for_numbers;
  while (stack.size() != 0) {
    if (stack.top().codeOfValue == NUMBERS || stack.top().codeOfValue == X) {
      stack_for_numbers.push(stack.top());
    } else if (stack.top().codeOfValue != NUMBERS ||
               stack.top().codeOfValue != X) {
      if (stack.top().codeOfValue == Plus) {
        double a = stack_for_numbers.top().number;
        stack_for_numbers.pop();
        double b = stack_for_numbers.top().number;
        stack_for_numbers.pop();
        result = a + b;
        stack_for_numbers.push({result, 18, 0});
      }
      if (stack.top().codeOfValue == Minus) {
        double a = stack_for_numbers.top().number;
        stack_for_numbers.pop();
        double b = stack_for_numbers.top().number;
        stack_for_numbers.pop();
        result = b - a;
        stack_for_numbers.push({result, 18, 0});
      }
      if (stack.top().codeOfValue == Mul) {
        double a = stack_for_numbers.top().number;
        stack_for_numbers.pop();
        double b = stack_for_numbers.top().number;
        stack_for_numbers.pop();
        result = b * a;
        stack_for_numbers.push({result, 18, 0});
      }
      if (stack.top().codeOfValue == Div) {
        const double a = stack_for_numbers.top().number;
        stack_for_numbers.pop();
        const double b = stack_for_numbers.top().number;
        stack_for_numbers.pop();
        if (a != 0) {
          result = b / a;
          stack_for_numbers.push({result, 18, 0});
        } else {
          throw std::invalid_argument("del in 0");
        }
      }
      if (stack.top().codeOfValue == Pow) {
        double a = stack_for_numbers.top().number;
        stack_for_numbers.pop();
        double b = stack_for_numbers.top().number;
        stack_for_numbers.pop();
        result = pow(b, a);
        stack_for_numbers.push({result, 18, 0});
      }
      if (stack.top().codeOfValue == Sin) {
        double a = stack_for_numbers.top().number;
        stack_for_numbers.pop();
        result = sin(a);
        stack_for_numbers.push({result, 18, 0});
      }
      if (stack.top().codeOfValue == ASin) {
        double a = stack_for_numbers.top().number;
        stack_for_numbers.pop();
        result = asin(a);
        stack_for_numbers.push({result, 18, 0});
      }
      if (stack.top().codeOfValue == Cos) {
        double a = stack_for_numbers.top().number;
        stack_for_numbers.pop();
        result = cos(a);
        stack_for_numbers.push({result, 18, 0});
      }

      if (stack.top().codeOfValue == ACos) {
        double a = stack_for_numbers.top().number;
        stack_for_numbers.pop();
        result = acos(a);
        stack_for_numbers.push({result, 18, 0});
      }
      if (stack.top().codeOfValue == Tan) {
        double a = stack_for_numbers.top().number;
        stack_for_numbers.pop();
        result = tan(a);
        stack_for_numbers.push({result, 18, 0});
      }
      if (stack.top().codeOfValue == Atan) {
        double a = stack_for_numbers.top().number;
        stack_for_numbers.pop();
        result = atan(a);
        stack_for_numbers.push({result, 18, 0});
      }
      if (stack.top().codeOfValue == Log) {
        double a = stack_for_numbers.top().number;
        stack_for_numbers.pop();
        if (a > 0) {
          result = log10(a);
          stack_for_numbers.push({result, 18, 0});
        } else {
          throw std::invalid_argument("- in log");
        }
      }
      if (stack.top().codeOfValue == Ln) {
        double a = stack_for_numbers.top().number;
        stack_for_numbers.pop();
        if (a > 0) {
          result = log(a);
          stack_for_numbers.push({result, 18, 0});
        } else {
          throw std::invalid_argument("- in ln");
        }
      }
      if (stack.top().codeOfValue == Sqrt) {
        double a = stack_for_numbers.top().number;
        stack_for_numbers.pop();
        if (a > 0) {
          result = sqrt(a);
          stack_for_numbers.push({result, 18, 0});
        } else {
          throw std::invalid_argument("- in sqrt");
        }
      }
      if (stack.top().codeOfValue == MOOD) {
        double a = stack_for_numbers.top().number;
        stack_for_numbers.pop();
        double b = stack_for_numbers.top().number;
        stack_for_numbers.pop();
        if (a != 0) {
          result = fmod(b, a);
          stack_for_numbers.push({result, 18, 0});
        }
      }
      if (stack.top().codeOfValue == Umin) {
        double a = stack_for_numbers.top().number;
        stack_for_numbers.pop();
        result = a * -1;
        stack_for_numbers.push({result, 18, 0});
      }
    }
    if (stack.size() == 0) {
      break;
    }
    stack.pop();
  }
  if (stack_for_numbers.size() != 0) {
    *result_new = stack_for_numbers.top().number;
  }
}
