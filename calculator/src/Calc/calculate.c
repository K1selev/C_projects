#include "calculate.h"

double calculate(char *notation, double x) {
  double result = 0.0, answer;
  char *p;
  char double_number[MAXN] = {'\0'};
  double_node *numbers = {0};
  for (p = notation; *p; ++p) {
    if (is_digit(*p)) {
      if ('x' == *p) {
        push_back_dnode(&numbers, x);
      } else {
        result = take_number(&p);
        push_back_dnode(&numbers, result);
        memset(double_number, 0, sizeof(double_number));
      }
    } else if (is_operator(*p)) {
      if ('+' == *p) plus(&numbers);
      if ('-' == *p) minus(&numbers);
      if ('*' == *p) mul(&numbers);
      if ('/' == *p) divis(&numbers);
      if ('^' == *p) power(&numbers);
      if ('%' == *p) float_mod(&numbers);
    } else if (is_trig(*p)) {
      if ('s' == *p) doubl_sin(&numbers);
      if ('S' == *p) doubl_asin(&numbers);
      if ('c' == *p) doubl_cos(&numbers);
      if ('C' == *p) doubl_acos(&numbers);
      if ('t' == *p) doubl_tan(&numbers);
      if ('T' == *p) doubl_atan(&numbers);
      if ('l' == *p) doubl_ln(&numbers);
      if ('L' == *p) doubl_log(&numbers);
      if ('q' == *p) doubl_sqrt(&numbers);
    }
  }
  pop_back_double(&numbers, &answer);
  return answer;
}

double take_number(char **notation) {
  int i = 0;
  char double_number[MAXN] = {'\0'};
  while (is_digit(**notation)) {
    double_number[i] = **notation;
    ++i;
    ++*notation;
  }
  return atof(double_number);
}

int is_operator(char c) {
  int status = ERR;
  if ('+' == c || '-' == c || '*' == c || '/' == c || '^' == c || '%' == c) {
    status = OK;
  }
  return status;
}

int is_trig(char c) {
  int status = ERR;
  if ('s' == c || 'S' == c || 'c' == c || 'C' == c || 'l' == c || 'L' == c ||
      't' == c || 'T' == c || 'q' == c) {
    status = OK;
  }
  return status;
}

void plus(double_node **numbers) {
  double first, second, answer;
  pop_back_double(numbers, &second);
  pop_back_double(numbers, &first);
  answer = first + second;
  push_back_dnode(numbers, answer);
}

void minus(double_node **numbers) {
  double first, second, answer;
  pop_back_double(numbers, &second);
  pop_back_double(numbers, &first);
  answer = first - second;
  push_back_dnode(numbers, answer);
}

void mul(double_node **numbers) {
  double first, second, answer;
  pop_back_double(numbers, &second);
  pop_back_double(numbers, &first);
  answer = first * second;
  push_back_dnode(numbers, answer);
}

void divis(double_node **numbers) {
  double first, second, answer;
  pop_back_double(numbers, &second);
  pop_back_double(numbers, &first);
  answer = first / second;
  push_back_dnode(numbers, answer);
}

void power(double_node **numbers) {
  double first, second, answer;
  pop_back_double(numbers, &second);
  pop_back_double(numbers, &first);
  answer = pow(first, second);
  push_back_dnode(numbers, answer);
}

void float_mod(double_node **numbers) {
  double first, second, answer;
  pop_back_double(numbers, &second);
  pop_back_double(numbers, &first);
  answer = fmod(first, second);
  push_back_dnode(numbers, answer);
}

void doubl_sin(double_node **numbers) {
  double first, answer;
  pop_back_double(numbers, &first);
  answer = sin(first);
  push_back_dnode(numbers, answer);
}

void doubl_asin(double_node **numbers) {
  double first, answer;
  pop_back_double(numbers, &first);
  answer = asin(first);
  push_back_dnode(numbers, answer);
}

void doubl_cos(double_node **numbers) {
  double first, answer;
  pop_back_double(numbers, &first);
  answer = cos(first);
  push_back_dnode(numbers, answer);
}

void doubl_acos(double_node **numbers) {
  double first, answer;
  pop_back_double(numbers, &first);
  answer = acos(first);
  push_back_dnode(numbers, answer);
}

void doubl_tan(double_node **numbers) {
  double first, answer;
  pop_back_double(numbers, &first);
  answer = tan(first);
  push_back_dnode(numbers, answer);
}

void doubl_atan(double_node **numbers) {
  double first, answer;
  pop_back_double(numbers, &first);
  answer = atan(first);
  push_back_dnode(numbers, answer);
}

void doubl_ln(double_node **numbers) {
  double first, answer;
  pop_back_double(numbers, &first);
  answer = log(first);
  push_back_dnode(numbers, answer);
}

void doubl_log(double_node **numbers) {
  double first, answer;
  pop_back_double(numbers, &first);
  answer = log10(first);
  push_back_dnode(numbers, answer);
}

void doubl_sqrt(double_node **numbers) {
  double first, answer;
  pop_back_double(numbers, &first);
  answer = sqrt(first);
  push_back_dnode(numbers, answer);
}
