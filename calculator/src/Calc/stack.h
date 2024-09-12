#ifndef SRC_STACK_H
#define SRC_STACK_H

/**
  @brief Реализация стека символов
  @param prior приоритет символа
  @param symb символ
  @param Node *next указатель на следующий элемент стека
*/
typedef struct Node {
  int prior;
  char symb;
  struct Node *next;
} node;

/**
  @brief Реализация стека чисел
  @param val число
  @param double_node *next указатель на следующий элемент стека
*/
typedef struct double_node {
  double val;
  struct double_node *next;
} double_node;

#include "s21_helper.h"

/**
  @brief Функция создания элемента связного списка возвращающая статус создания
  @param patr сама структура
  @param prior приоритет передаваемого символа
  @param symb передаваемый символ
  @param status статус выполнения
*/
int push_back(node **patr, int prior, char symb);
/**
  @brief Функция взятия верхнего элемента связного списка
  @param patr структура
  @param prior приоритет символа
  @param symb символ
*/
void pop_back(node **patr, int *prior, char *symb);

/**
  @brief Функция для очистки памяти выделенной под стека
  @param patr структура
*/
void free_node(node **patr);

// /**
//   @brief Вспомогательная функция для просмотра стека
//   @param patr структура
// */
// void print_list(node *patr);
/**
  @brief Вспомогательная функция для проверки на существование стека
  @param stack структура
*/
int check_stack(const node *stack);

/**
  @brief Функция проверки приоритета символа
  @param patr структура
  @param prior приоритет символа
*/
void pop_prior(const node *patr, int *prior);

/**
  @brief Функция для добавления оператора в стэк
  @param patr структура
  @param notation строка нотации
  @param jdx индекс строки нотации
  @param op оператор
*/
void add_stack(node **patr, char *notation, int *jdx, int op);

/**
  @brief Функция для добавления чисел в стэк
  @param patr структура для чисел
  @param data строка числа
*/
int push_back_dnode(double_node **patr, double data);

/**
  @brief Функция взятия верхнего элемента связного списка
  @param patr структура
  @param num число
*/
void pop_back_double(double_node **patr, double *num);

// /**
//   @brief Вспомогательная функция для просмотра стека чисел
//   @param patr структура
// */
// void print_double_list(double_node *patr);

#endif  // SRC_STACK_H