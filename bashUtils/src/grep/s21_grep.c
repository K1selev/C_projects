#include "s21_grep.h"

int main(int argc, char *argv[]) {
  opt options = {0};  // обнуляем все переменные
  parser(argc, argv, &options);
  return 0;
}

void parser(int argc, char *argv[], opt *options) {
  int opt = 0;  //  сюда будет записываться результат функции getopt_long
  opterr = 0;  //  предотвращаем появление сообщения об ошибке
  char pattern[1024] = {'\0'};  // шаблон
  char temple_pat[1024] = {'\0'};  // буфферный шаблон для файла (f)
  char *filename = {NULL};  // переменная для файла
  int unknown = 0;  // флаг нахождения неизвестной опции

  while ((opt = getopt_long(argc, argv, "e:f:vclinhso", 0, NULL)) != -1) {
    switch (opt) {
      case 'e':
        options->e = 1;
        add_i_to_arr(optarg, pattern, options);  // записываем шаблон в массив
        break;
      case 'f':
        options->f = 1;
        create_f_pattern(optarg, temple_pat);  // копируем содержимое файла
        add_i_to_arr(
            temple_pat, pattern,
            options);  // записываем содержимое файла в массив для шаблонов
        break;
      case 'v':
        options->v = 1;
        break;
      case 'c':
        options->c = 1;
        break;
      case 'l':
        options->l = 1;
        break;
      case 'i':
        options->i = 1;
        break;
      case 'n':
        options->n = 1;
        break;
      case 'h':
        options->h = 1;
        break;
      case 's':
        options->s = 1;
        break;
      case 'o':
        options->o = 1;
        break;
      default:
        fprintf(stderr, "s21_grep: unknown option - %c. Try --help\n",
                optopt);  // если неизвестная опция
        unknown = 1;
    }
  }

  if (optind == 1) {  // если нет введённых аргументов
    print_input_error();
  } else if (!unknown) {  // если не найдено неизвестных опций
    if (!options->e) {
      if (!options->f) {
        strcpy(pattern, argv[optind]);  // копируем шаблон в массив для шаблонов
        pattern[strlen(pattern)] = '\0';  // ставим в конец терминальный ноль
        optind++;  // переход на следующий аргумент
      }
    }

    options->file_num = check_for_files(
        argc, optind, argv);  // записываем количество файлов для обработки
    FILE *file;
    while ((optind < argc) &&
           (unknown != 1)) {  // пока не прочитаны все аргументы на вход или
                              // пока не отработает флаг
      filename = argv[optind];  // записываем имя файла в переменную
      if ((file = fopen(filename, "r")) != NULL) {  // если файл открывается
        options->current_file++;                    // текущий файл
        fclose(file);  // закрываем файл
        use_grep(filename, pattern, options);
      } else {              // если файл не открылся
        if (!options->s) {  // если  не s (подавление сообщений об ошибках) -
                            // выводим ошибку
          fprintf(stderr, "s21_grep: %s: No such file or directory\n",
                  filename);
        }
        if (options->f) {  // если f - ставим флаг (нет файла = нет шаблона)
          unknown = 1;
        }
      }
      optind++;  // переход на следующий аргумент
    }
  }
}

// функция для вывода ошибки из-за неправильно введённой команды
void print_input_error() {
  fputs("Usage: grep [OPTION]... PATTERNS [FILE]...\n", stdout);
}

void use_grep(char *filename, char *pattern, opt *options) {
  FILE *file;
  int match_num = 0;  // количество совпадений
  int inv_match_num = 0;  // количества инверсных совпадений
  int line_num = 1;  // счётчик строк
  char line[4096];
  if (options->h) {  // при опции h убираем спец флаг
    options->file_num = 1;
  }
  if ((file = fopen(filename, "r")) != NULL) {  // если файл открывается
    while (fgets(line, sizeof(line),
                 file)) {  //получаем из файла строки пока не закончатся
      int search_status;   // флаг наличия совпадений
      int compiled_value =
          compile_regex(line, pattern, &search_status, options);
      if (compiled_value ==
          0) {  // если компиляция рег выражения прошла успешно
        if ((search_status == 0) &&
            (!options->v)) {  // если были совпадения и !v
          match_num++;        // + совпадение
          if ((!options->c) && (!options->l) &&
              (!options->o)) {  // если опция, которая требует вывода совпадения
            print_output(filename, line, line_num, options);  // вывод строки
          } else if (options->o) {                            // если о
            if ((!options->c) && (!options->l)) {  // если !c и !l
              print_match(filename, line, pattern, line_num, options);
            }
          }
        } else if ((options->v) &&
                   (search_status == 1)) {  // если v и нет совпадений
          inv_match_num++;  // + инверсное совпадение
          if ((!options->c) && (!options->l) &&
              (!options->o)) {  // если опция, которая требует вывода совпадения
            print_output(filename, line, line_num, options);
          }
        }
      }
      line_num++;  // увеличиваем счётчик строк
    }
    file_flags_output(filename, match_num, inv_match_num, options);
    if ((options->current_file < options->file_num - 1) && (!options->l) &&
        (!options->c) && (!options->o)) {
      printf("\n");
    }
  } else {  // если файл не открывается
    fprintf(stderr, "s21_grep: %s: No such file or directory\n", filename);
  }
  fclose(file);  // закрываем файл
}

// функция для обработки вывода с разными флагами
void file_flags_output(char *filename, int match_num, int inv_match_num,
                       opt *options) {
  if ((options->l) || (options->c)) {
    if ((options->l) && (options->c) && (options->file_num > 1)) {
      if (options->v) {
        printf("%s:%d\n", filename, inv_match_num);
      } else if (!options->v) {
        printf("%s:%d\n", filename, match_num);
      }
    } else if ((options->l) && (options->c) && (options->file_num = 1)) {
      printf("1\n%s\n", filename);
    } else {
      if ((options->c) && (!options->v)) {
        printf("%d\n", match_num);
      }
      if ((options->c) && (options->v)) {
        printf("%d\n", inv_match_num);
      }
      if ((options->l) && ((match_num > 0) || (inv_match_num > 0))) {
        printf("%s\n", filename);
      }
    }
  }
}

// функция для вывода совпадающей строки
void print_output(char *filename, char *line, int line_num, opt *options) {
  if ((options->file_num > 1) && (!options->h)) {  // если несколько файлов и !h
    printf("%s:", filename);  // вывод названия файла
  }
  if (options->n) {           // если n
    printf("%d:", line_num);  // вывод номера строки
  }
  printf("%s", line);  // вывод строки
}

// функция для компиляции регулярных выражений и поиска совпадений
int compile_regex(char *line, char *pattern, int *search_status, opt *options) {
  regex_t regex;  // область хранения буфферного шаблона
  regmatch_t match;  // cтруктура с результатами сравнения строки с регулярным
                     // выражением
  int result;  // переменная для результата компиляции
  if (options->i) {
    result =
        regcomp(&regex, pattern,
                REG_ICASE | REG_EXTENDED);  // компиляция рег выражения с
                                            // игнорированием различия регистра
  } else {
    result =
        regcomp(&regex, pattern, REG_EXTENDED);  // компиляция рег выражения
  }
  if (result == 0) {  // если компиляция рег выражения прошла успешно
    *search_status =
        regexec(&regex, line, 1, &match, 0);  // поиск совпадений в строке
  }
  regfree(&regex);  // освобождение памяти после работы regcomp (regex)
  return result;
}

// функция для печати только совпадающих (непустых) частей совпавшей строки
void print_match(char *filename, char *line, char *pattern, int line_num,
                 opt *options) {
  regex_t regex;  // область хранения буфферного шаблон
  regmatch_t pmatch[1];  // cтруктура с результатами сравнения строки с
                         // регулярным выражением
  int first_match = 0;   // первое совпадение в строке
  char *ptr = line;      // указатель на строку
  int search_status;
  regoff_t len =
      1;  // тип для хранения количества символов в совпадающем участке строки
  if (options->i) {
    regcomp(&regex, pattern, REG_EXTENDED | REG_ICASE);
  } else {
    regcomp(&regex, pattern, REG_EXTENDED);
  }
  while ((search_status = regexec(&regex, ptr, 1, pmatch, 0)) ==
         0) {  // пока в строке есть совпадения
    len = pmatch[0].rm_eo -
          pmatch[0].rm_so;  // количество символов в совпадающем участке строки
    if ((options->file_num > 1) && (!options->h)) {
      printf("%s:", filename);
    }
    if ((options->n) &&
        (first_match == 0)) {  // если n и первое совпадение - нумеруем
      printf("%d:", line_num);
      first_match = 1;
    }
    printf("%.*s\n", (int)len,
           ptr + pmatch[0].rm_so);  // вывод только участка строки с совпадением
    ptr += pmatch[0].rm_eo;  // передвигаем указатель
  }
  regfree(&regex);
}

// функция для создания шаблона из входного файла
void create_f_pattern(char *f_filename, char *array) {
  char *ptr = array;
  FILE *file;
  if ((file = fopen(f_filename, "r")) != NULL) {  // проверяем файл на открытие
    while (
        (!feof(file) && !ferror(file))) {  // пока не конец файла или не ошибка
      int tmp = getc(file);  // считываем символ в буфферную переменную
      if (tmp == '\n') {
        *ptr = '|';  // ставим разделитель
        ptr++;       // передвигаем указатель
      } else if (tmp != EOF) {
        *ptr = (char)tmp;  // записываем символ
        ptr++;             // передвигаем указатель
      }
    }
    *ptr = '\0';
    fclose(file);  // закрываем файл
  } else {
    fprintf(stderr, "s21_grep: %s: No such file or directory\n",
            f_filename);  // если файл не открылся
  }
}

// функция для записи шаблона
void add_i_to_arr(char *optarg, char *array, opt *options) {
  char *from_ptr =
      optarg;  // ставим указатель на начало массива, откуда копируем
  char *to_ptr = array;  // ставим указатель на начало массива, куда копируем
  int offset;  // количество символов в массиве с шаблонами (чтобы избежать
               // потери данных при записи новых шаблонов)
  if (options->first_iter) {
    offset = 0;
  } else {
    offset = strlen(array);
  }
  to_ptr += offset;  // передвигаем указатель
  if (offset != 0) {  // если в массиве с шаблонами что-то есть
    *to_ptr = '|';  // разделитель
    // передвигаем указатели
    to_ptr++;
    offset++;
  }
  while (*from_ptr) {  // пока есть что копировать
    offset++;  // увеличиваем счётчик количества элементов в массиве
    *to_ptr = *from_ptr;  // копируем символ
    // передвигаем указатели
    to_ptr++;
    from_ptr++;
  }
  array[offset] = '\0';  // ставим в конец терминальный ноль
  options->first_iter = 0;  // убираем флаг первой итерации
}

// функция для определения количества заданных на обработку файлов
int check_for_files(int argc, int optind, char *argv[]) {
  int count_files = 0;     // счётчик количества файлов
  while (optind < argc) {  // пока индекс след элемента строки меньше количества
                           // введённых аргументов
    char *filename;
    FILE *file;
    filename = argv[optind];  // записываем имя файла из строки в переменную
    if ((file = fopen(filename, "r")) !=
        NULL) {  // проверяем, открывается ли файл
      count_files++;  // увеличиваем счётчик количества файлов
      fclose(file);  // закрываем файл
    }
    optind++;  // переход на следующий индекс аргумента строки
  }
  return count_files;  // возвращаем количество файлов
}
