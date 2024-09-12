#ifndef SRC_CALCULATE_H_
#define SRC_CALCULATE_H_

#include "math.h"
#include "parse_string.h"
#define MAXN 256

/**
  @brief функция вычисления
  @param notation строка польской нотации
 */
double calculate(char *notation, double x);
/**
  @brief функция получения числа
  @param notation строка польской нотации
*/
double take_number(char **notation);
/**
  @brief функция проверки оператора
  @param с символ
*/
int is_operator(char c);
/**
  @brief функция проверки на тригонометрическую функцию
  @param с символ
*/
int is_trig(char c);
/**
  @brief функция сложения
  @param numbers стек чисел
*/
void plus(double_node **numbers);
/**
  @brief функция вычитания
  @param numbers стек чисел
*/
void minus(double_node **numbers);
/**
  @brief функция умножения
  @param numbers стек чисел
*/
void mul(double_node **numbers);
/**
  @brief функция деления
  @param numbers стек чисел
*/
void divis(double_node **numbers);
/**
  @brief функция возведения в степень
  @param numbers стек чисел
*/
void power(double_node **numbers);
/**
  @brief функция остаток от деления
  @param numbers стек чисел
*/
void float_mod(double_node **numbers);
/**
  @brief функция sinus
  @param numbers стек чисел
*/
void doubl_sin(double_node **numbers);
/**
  @brief функция asinus
  @param numbers стек чисел
*/
void doubl_asin(double_node **numbers);
/**
  @brief функция cosinus
  @param numbers стек чисел
*/
void doubl_cos(double_node **numbers);
/**
  @brief функция acosinus
  @param numbers стек чисел
*/
void doubl_acos(double_node **numbers);
/**
  @brief функция tan
  @param numbers стек чисел
*/
void doubl_tan(double_node **numbers);
/**
  @brief функция atan
  @param numbers стек чисел
*/
void doubl_atan(double_node **numbers);
/**
  @brief функция натурального логарифма
  @param numbers стек чисел
*/
void doubl_ln(double_node **numbers);
/**
  @brief функция десятичный логарифм
  @param numbers стек чисел
*/
void doubl_log(double_node **numbers);
/**
  @brief функция квадратного корня
  @param numbers стек чисел
*/
void doubl_sqrt(double_node **numbers);

#endif  // SRC_CALCULATE_H
