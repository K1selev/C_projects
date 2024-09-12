#ifndef SRC_S21_HELPER_H_
#define SRC_S21_HELPER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "math.h"
/**
  @brief коды ошибок
  @param status перечисляемый тип
  @param ERR статус ошибки 0
  @param ОК статус ок 1
*/
enum status { ERR, OK };
/**
  @brief коды приоритетов
  @param prior перечисляемый тип приоритетов
  @param BR статус скобок низший приоритет = 0
  @param P_M плюс или минус средний приоритет = 1
  @param M_D умножение или деление высокий приоритет = 2
  @param POW возведение в степень высший приоритет = 3
  @param SIN тригонометрические функции наивысший приоритет = 4
*/
enum prior { BR, P_M, M_D, POW, SIN };

#include "stack.h"
/**
  @brief вспомогательная функция проверки символа на число
  @param data символ
*/
int is_digit(char data);
/**
  @brief вспомогательная функция считающая длину строки
  @param data строка
*/
int len_data(const char *data);
// /**
//   @brief вспомогательная функция отображения польской нотации
//   @param data строка нотации
// */
// void print_notation(char *data);
/**
  @brief функция проверяет строку на тригонометрические функции и добавляетв
  стек их символы
  @param data входная строка
  @param stack стек операторов
  @param idx переменная которая запоминает на сколько сдвинуть строку до
  следующего символа
*/
int is_func(char *data, struct Node **stack, int *idx);
/**
  @brief функция проверяет парность скобок
  @param data входная строка
*/
int check_brackets(const char *data);
/**
  @brief функция достает из стека скобку
  @param stack_br стек
  @param top позиция в стеке
*/
void pop_br(char *stack_br, int *top);
/**
  @brief функция добавляет в стека скобку
  @param stack_br стек
  @param br скобка
  @param top позиция в стеке
*/
void push_br(char *stack_br, char br, int *top);

/**
  @brief функция проверки числа
  @param data строка данных
  @param notation строка нотации
  @param jdx индексная переменная
  @param idx индексная переменная
*/
int check_numbers(const char *data, char *notation, int *jdx, int *idx);
/**
  @brief функция добавления символа в нотацию
  @param notation строка нотации
  @param jdx индексная переменная
  @param sym символ который добавляем
*/
void add_notation(char *notation, int *jdx, char sym);
/**
  @brief функция добавления чисел в нотацию
  @param p строка данных
  @param notation строка нотации
  @param jdx индексная переменная
  @param idx индексная переменная
*/
int numbers(char *p, char *notation, int *jdx, int *idx);
/**
  @brief функция проверки скобок
  @param p строка данных
*/
int check_brakets(char *p);
/**
  @brief функция очищающая стек
  @param stack стек операторов
  @param notation строка нотации
  @param jdx индексная переменная
  @param pr приоритет
  @param b  символ
*/
void add_stack_last(node **stack, char *notation, int *jdx, int *pr, char *b);
/**
  @brief функция проверяет первый символ строки
  @param data строка данных
*/
int check_first(const char *data);
/**
  @brief функция проверки корректности строки
  @param data строка данных
*/
int check_correct_string(const char *data);
/**
  @brief функция проверяет корректность ввода операторов
  @param data строка данных
*/
int check_correct_oper(const char *data);
/**
  @brief функция проверяет корректность допустимых символов
  @param с символ
*/
int check_trig(char c);
/**
  @brief функция проверки корректности последнего символа
  @param data строка данных
*/
int check_last_sym(const char *data);
/**
  @brief функция проверяет корректность операторов
  @param с символ
*/
int cor_oper_num(char c);
/**
  @brief функция проверяет унарный плюс или минус
  @param data строка
*/
int check_unar(char c);
/**
  @brief функция добавления Нуля в нотацию
  @param notation строка нотации
  @param jdx индексная переменная
  @param sym символ который добавляем
*/
void add_zero_notation(char *notation, int *jdx);
/**
  @brief функция проверяет первый символ на плюс или минус
  @param data строка данных
*/
int check_plus_min(const char *data);

#endif  //  SRC_S21_HELPER_H_
