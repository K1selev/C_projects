#include "stack.h"

int push_back(node **patr, int prior, char symb) {
  int status = OK;
  node *new = (node *)malloc(sizeof(node));
  if (NULL == new) {
    status = ERR;
  } else {
    new->prior = prior;
    new->symb = symb;
    if (NULL == (*patr)) {
      new->next = NULL;
      (*patr) = new;
    } else {
      new->next = (*patr);
      (*patr) = new;
    }
  }
  return status;
}

void pop_back(node **patr, int *prior, char *symb) {
  if (NULL != (*patr)) {
    node *cur;
    cur = (*patr);
    *prior = cur->prior;
    *symb = cur->symb;
    (*patr) = (*patr)->next;
    free(cur);
  }
}

void pop_prior(const node *patr, int *prior) {
  if (NULL != patr) {
    *prior = patr->prior;
  }
}

int check_stack(const node *stack) {
  int status = ERR;
  if (NULL == stack) {
    status = OK;
  }
  return status;
}

void free_node(node **patr) {
  while (*patr) {
    node *curent = (*patr)->next;
    free(*patr);
    *patr = curent;
  }
}

void add_stack(node **patr, char *notation, int *jdx, int op) {
  int pr;
  char b;
  if (patr) {
    pop_prior(*patr, &pr);
    while (pr >= op && !check_stack(*patr)) {
      pop_back(patr, &pr, &b);
      add_notation(notation, jdx, b);
      pop_prior(*patr, &pr);
    }
  }
}

int push_back_dnode(double_node **patr, double data) {
  int status = OK;
  double_node *new = (double_node *)malloc(sizeof(double_node));
  if (NULL == new) {
    status = ERR;
  } else {
    new->val = data;
    if (NULL == (*patr)) {
      new->next = NULL;
      (*patr) = new;
    } else {
      new->next = (*patr);
      (*patr) = new;
    }
  }
  return status;
}

void pop_back_double(double_node **patr, double *num) {
  if (NULL != (*patr)) {
    double_node *cur;
    cur = (*patr);
    *num = cur->val;
    (*patr) = (*patr)->next;
    free(cur);
  }
}
