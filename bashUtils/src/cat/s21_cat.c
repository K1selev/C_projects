#include "s21_cat.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  opt flags = {0};  //  каждому значению в стуруктуре присваиваем значение 0
  parser(argc, argv, &flags);
  if (flags.b) {
    flags.n = 0;
  }
  reader(argc, argv, &flags);
  return 0;
}
void parser(int argc, char *argv[], opt *options) {
  int mode;  //  сюда будет записываться результат функции getopt_long
  int options_index;  //  для длинных аргументов
  static struct option long_options[] = {//  структура массивов
                                         {"number-nonblank", 0, 0, 'b'},
                                         {"number", 0, 0, 'n'},
                                         {"squeeze", 0, 0, 's'},
                                         {0, 0, 0, 0}};
  while ((mode = (getopt_long(argc, argv, "+benstvTE", long_options,
                              &options_index))) != -1) {
    switch (mode) {
      case 'b':
        options->b = 1;
        break;
      case 'e':
        options->e = 1;
        options->v = 1;
        break;
      case 'n':
        options->n = 1;
        break;
      case 's':
        options->s = 1;
        break;
      case 't':
        options->t = 1;
        options->v = 1;
        break;
      case 'v':
        options->v = 1;
        break;
      default:
        fprintf(stderr, "usage: -benstvTE");
        exit(1);
    }
  }
}
void reader(int argc, char *argv[], opt *options) {
  int opened_file = optind;
  for (; opened_file < argc; opened_file++) {
    FILE *f = fopen(argv[opened_file],
                    "r");  //  указатель на следующий argv - то есть на файл
    if (f) {
      int ok = 1;  //  переменная для печати символа (1 - печатаем; 0 - нет)
      int current = 0;    //  текущий символ
      int str_count = 1;  //  счетчик строк
      int endlS = 0;      //  счётчик \n
      int previous = -1;  //  буфферная переменная для предыдущего символа
      int firstN =
          -1;  //  для обработки случая с переносом строки в начале файла
      while ((current = fgetc(f)) != EOF) {
        //  первый символ
        if (previous == -1) {
          //  если пустая строка
          if (current == '\n') {
            if ((options->b) || (options->v) ||
                (options->t)) {  //  при b, v, t - печатаем
              ok = 1;
            }
            if (options->n) {  //  при n - печатаем с нумерацией
              if (options->s != 1) {
                printf("%6d\t", str_count);
                str_count++;
              }
              ok = 1;
            }
            if (options->e) {  //  при e - печатаем с $
              if (options->s != 1) {
                printf("$");
              }
              ok = 1;
            }
            if (options->s) {  // при s - не печатаем и ++
              endlS++;
              ok = 0;
            }
            //  если символ
          } else {
            if ((options->s) || (options->v) || (options->e) ||
                (options->t)) {  //  при s, v, e, t  - печатаем
              ok = 1;
            }
            if ((options->b) ||
                (options->n)) {  //  при b, n - печатаем с нумерацией
              printf("%6d\t", str_count);
              str_count++;
              ok = 1;
            }
          }
          //  если первый (стандартный) перенос после строки
        } else if ((current == '\n') && (previous != 10)) {
          if ((options->b) || (options->n) || (options->t) ||
              (options->v)) {  //  при b, n, t, v  - печатаем
            ok = 1;
          }
          if (options->s) {  // при s - печатаем и ++
            endlS++;
            ok = 1;
          }
          if (options->e) {  //  при e - печатаем с $
            printf("$");
            ok = 1;
          }
          //  если второй и более перенос (аномальный)
        } else if ((current == '\n') && (previous == 10)) {
          if ((options->b) || (options->v) ||
              (options->t)) {  //  при b, v, t - печатаем
            ok = 1;
          }
          if (options->n) {  //  при n - печатаем с нумерацией
            if (options->s != 1) {
              printf("%6d\t", str_count);
              str_count++;
            }
            ok = 1;
          }
          if (options->e) {  //  при e - печатаем с $
            if (options->s != 1) {
              printf("$");
            }
            ok = 1;
          }
          if (options->s) {  // при s - не печатаем и ++
            ok = 0;
            endlS++;
          }
          //  если символ после переноса
        } else if ((current != '\n') && (previous == 10)) {
          if ((options->e) || (options->v) ||
              (options->t)) {  //  при b, v, t - печатаем
            ok = 1;
          }
          if ((options->b) ||
              (options->n)) {  //  при b, n - печатаем с нумерацией
            if (options->s != 1) {
              printf("%6d\t", str_count);
              str_count++;
            }
            ok = 1;
          }
          if (options->s) {
            if (((endlS > 1) && (previous != -1)) ||
                ((endlS > 0) && (firstN == -1))) {
              firstN = 0;
              ok = 1;
              if (options->n) {  // при n
                printf("%6d\t", str_count);
                str_count++;
              }
              if (options->e) {
                printf("$");
              }
              printf("\n");
              if ((options->b) || (options->n)) {
                printf("%6d\t", str_count);
                str_count++;
              }
            } else {
              if ((options->b) || (options->n)) {
                printf("%6d\t", str_count);
                str_count++;
              }
              ok = 1;
            }
          }
          endlS = 0;
          //  если символ после символа
        } else if ((current != '\n') && (previous != 10)) {
          if ((options->s) || (options->b) || (options->n) || (options->v) ||
              (options->e) || (options->t)) {  // печатаем
            ok = 1;
          }
        }
        //  доп обработка флага v
        if ((options->v) && (ok == 1)) {
          if ((current < 32) && (current != 9) && (current != 10) &&
              (current != 127)) {
            ok = 0;
            printf("^%c", current + 64);
          } else if (current == 127) {
            ok = 0;
            printf("^?");
          }
        }
        //  доп обработка флага t
        if ((options->t) && (ok == 1) && (current == 9)) {
          ok = 0;
          printf("^I");
        }
        //  запись текущего символа в предыдущий
        previous = current;
        //  печать символа
        if (ok == 1) {
          printf("%c", current);
        }
      }
      //  если в конце было несколько пробелов и флаг s(+n,е)
      if ((options->s) && (endlS > 1)) {
        if (options->n) {
          printf("%6d\t", str_count);
          str_count++;
        }
        if (options->e) {
          printf("$");
        }
        printf("\n");
      }
      //  закрываем файл
      fclose(f);
    } else {
      fprintf(stderr, "No such file or directory\n");  //  если файл не открылся
    }
  }
}