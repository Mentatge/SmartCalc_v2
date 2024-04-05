#include <gtest/gtest.h>

#include <iostream>

#include "../Model/s21_model_calc.h"

TEST(SmartCalculator, Test1) {
  s21::ModelCalc example;
  std::string str = "sin(cos(tan(atan(acos(asin(0.5^(5+2*10/3^4+7+2-3)))))))";
  double value_x = 0;
  double result;
  example.calculator(str, &result, value_x);
  EXPECT_NEAR(result, 0.000411473, 0.00000001);
}

TEST(SmartCalculator, Test2) {
  s21::ModelCalc example;
  std::string str = "sqrt(2^2)";
  double value_x = 0;
  double result;
  example.calculator(str, &result, value_x);
  EXPECT_EQ(result, 2);
}

TEST(SmartCalculator, Test3) {
  s21::ModelCalc example;
  std::string str = "2+3";
  double value_x = 0;
  double result;
  example.calculator(str, &result, value_x);
  EXPECT_EQ(result, 5);
}

TEST(SmartCalculator, Test4) {
  s21::ModelCalc example;
  std::string str = "4mod3";
  double value_x = 0;
  double result;
  example.calculator(str, &result, value_x);
  EXPECT_EQ(result, fmod(4, 3));
}

TEST(SmartCalculator, Test5) {
  s21::ModelCalc example;
  std::string str = "ln(1357-245)";
  double value_x = 0;
  double result;
  example.calculator(str, &result, value_x);
  EXPECT_EQ(result, log(1357 - 245));
}

TEST(SmartCalculator, Test6) {
  s21::ModelCalc example;
  std::string str = "-3+(-3)";
  double value_x = 0;
  double result;
  example.calculator(str, &result, value_x);
  EXPECT_EQ(result, -6);
}

TEST(SmartCalculator, Test7) {
  s21::ModelCalc example;
  std::string str = "x+3";
  double value_x = 3;
  double result;
  example.calculator(str, &result, value_x);
  EXPECT_EQ(result, 6);
}

TEST(SmartCalculator, Test8) {
  s21::ModelCalc example;
  std::string str = "log(1357-245)";
  double value_x = 0;
  double result;
  example.calculator(str, &result, value_x);
  EXPECT_EQ(result, log10(1357 - 245));
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}