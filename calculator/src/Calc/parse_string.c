#include "parse_string.h"

int parse_string(char *data, char *notation) {
  int status = ERR;
  if (data && check_correct_string(data)) {
    struct Node *stack = NULL;
    int jdx = 0, idx, pr;
    char b, *p = data;
    if (check_unar(p[0])) {
      add_zero_notation(notation, &jdx);
    }
    for (; *p; ++idx, ++p) {
      if (is_digit(*p) || *p == '.' || *p == 'x') {
        int k = 0;
        if (!numbers(p, notation, &jdx, &k)) {
          status = ERR;
          break;
        } else {
          for (; 1 < k; --k, ++p) {
          }
        }
      } else if ('(' == *p) {
        push_back(&stack, BR, *p);
        ++p;
        if (check_unar(*p)) {
          add_zero_notation(notation, &jdx);
        }
        --p;
        status = OK;
      } else if ('+' == *p || '-' == *p) {
        add_stack(&stack, notation, &jdx, P_M);
        push_back(&stack, P_M, *p);
        status = OK;
      } else if ('*' == *p || '/' == *p || '%' == *p) {
        add_stack(&stack, notation, &jdx, M_D);
        push_back(&stack, M_D, *p);
        status = OK;
      } else if ('^' == *p) {
        add_stack(&stack, notation, &jdx, POW);
        push_back(&stack, POW, *p);
        status = OK;
      } else if ('s' == *p || 'c' == *p || 'a' == *p || 't' == *p ||
                 'l' == *p) {
        if (is_func(p, &stack, &idx)) {
          for (; 1 < idx; --idx, ++p) {
          }
          status = OK;
        } else {
          status = ERR;
          break;
        }
      } else if (')' == *p) {
        if (!check_brakets(p)) {
          status = ERR;
          break;
        }
        pop_back(&stack, &pr, &b);
        if ('(' != b) {
          add_notation(notation, &jdx, b);
          while ('(' != b) {
            pop_back(&stack, &pr, &b);
            if (b != '(') {
              add_notation(notation, &jdx, b);
            }
          }
        }
        status = OK;
      }
      idx = 0;
    }
    if (status == OK) {
      add_stack_last(&stack, notation, &jdx, &pr, &b);
    }
    free_node(&stack);
  }
  return status;
}