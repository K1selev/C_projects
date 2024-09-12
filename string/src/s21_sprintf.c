#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  flags f = {0};
  clean_flags(&f);  // инициализируем все флаги нулями
  unsigned int count = 0;  // тут будем считать количество напечатанных символов
  va_list args;
  va_start(args, format);
  while (format && *format) {  // пока форматированная строка не закончилась
    if (*format != '%') {  // если не наткнулись на символ процента
      *str = *format;
      str++;
      format++;
      count++;
    } else {        // если наткнулись на процент
      *str = '\0';  // зануляем текущий символ новой строки, чтобы можно было
                    // делать стркат
      format++;
      format = parse_param(
          format, &f);  // определяем все параметры, кроме спецификатора
      format = get_spec(format, &f);  // определяем спецификатор
      // в случае ошибки функции занулят форматированную строку
      if (format) {  // поэтому тут проверяем, что она ещё существует
        if (f.specificator == '%') {  // если спецификатор %
          *str = '%';
          str++;
          count++;  // то печатаем его и двигаемся дальше
        } else {  // иначе достаём аргумент и правильно печатаем его в строку
          str = work_with_arg(&args, f, &str, &format, &count);
        }
      }
      clean_flags(&f);  // чистим флаги перед работой со следующим аргументом
    }
  }
  *str = '\0';  // зануляем строку
  if (!format)
    count = -1;  // если строка была занулена, ставим возвращаемое значение для
                 // ошибки
  va_end(args);  // закончили работу с вариадической функцией
  return count;
}

void clean_flags(flags *f) {
  // зануляем флаги
  f->hash = 0;
  f->minus = 0;
  f->plus = 0;
  f->space = 0;
  f->zero = 0;
  f->accuracy = 0;
  f->is_accuracy = 0;
  f->length = 0;
  f->specificator = 0;
  f->width = 0;
  f->for_prerounding = 0;
}

const char *parse_param(const char *format, flags *f) {
  while (*format == '-' || *format == '+' || *format == '0' || *format == '#' ||
         *format == ' ') {  // если есть флаг
    if (*format == '-')
      f->minus = 1;
    else if (*format == '+')
      f->plus = 1;
    else if (*format == '#')
      f->hash = 1;
    else if (*format == '0')
      f->zero = 1;
    else
      f->space = 1;
    format++;
  }  // отмечаем его в структуре и двигаемся дальше
  if (*format == '*') {  // если ширина равна звёздочке
    f->width = -2;
    format++;  // отмечаем это на будущее и двигаемся дальше
  } else {
    while (*format >= '0' &&
           *format <= '9') {  // если ширина есть и задана числом
      f->width *= 10;  // цикл нужен, потому что ширина может быть задана
                       // многосимвольным числом
      f->width += *format - '0';
      format++;
    }  // то запишем это число в соответствующий элемент структуры
  }
  if (*format == '.') {  // если есть символ точки, значит задана точность
    format++;
    f->is_accuracy = 1;  // отмечаем это
    if (*format == '*') {  // если точность задана звёздочкой
      f->accuracy = -2;
      format++;  // отмечаем это на будущее и идём дальше
    } else {
      while (*format >= '0' && *format <= '9') {  // парсим аналогично ширине
        f->accuracy *= 10;
        f->accuracy += *format - '0';
        format++;
      }
    }
  }
  if (*format == 'h' || *format == 'l' ||
      *format == 'L') {  // если задана длина
    f->length = *format;
    format++;  // записываем её и двигаемся дальше
  }
  return format;  // возвращаем элемент форматированной строки, который стоит
                  // после флагов
}

const char *get_spec(const char *format, flags *f) {
  char *specs =
      "cdeEfgGinopsuxX%";  // спецификаторы, которые обрабатывает функция
  int found = 0;
  for (size_t i = 0; specs[i] && !found;
       i++) {  // если пока не нашли и не посмотрели все спецификаторы
    if (*format == specs[i]) {
      f->specificator = specs[i];  // записываем этот спецификатор
      found = 1;
      format++;  // отмечаем, что нашли, и сдвигаемся по форматированной строке
    }
  }
  if (!found) format = S21_NULL;  // если ни один спецификатор не подошёл
  return format;  // зануляем строку, чтобы отметить ошибку и возвращаем её
}

char *work_with_arg(va_list *args, flags f, char **str, const char **format,
                    unsigned int *count) {
  if (f.width == -2) {  // если ширина была задана звёздочкой
    int wi = va_arg(*args, size_t);
    f.width = wi;
  }
  if (f.accuracy == -2) {  // аналогично ширине
    int ac = va_arg(*args, size_t);
    f.accuracy = ac;
  }
  // в зависимости от типа спецификатора, переходим в нужную функцию
  if (f.specificator == 'd' || f.specificator == 'i')
    *str = int_arg(str, f, args, count);
  else if (f.specificator == 'o' || f.specificator == 'u' ||
           f.specificator == 'x' || f.specificator == 'X')
    *str = uints_arg(str, f, args, count);
  else if (f.specificator == 'e' || f.specificator == 'E' ||
           f.specificator == 'f' || f.specificator == 'g' ||
           f.specificator == 'G')
    *str = double_arg(str, f, args, count);
  else if (f.specificator == 'c')
    *str = char_arg(str, f, args, format, count);
  else if (f.specificator == 's')
    *str = string_arg(str, f, args, format, count);
  else if (f.specificator == 'p')
    *str = ptr_arg(str, f, args, count);
  else if (f.specificator == 'n')
    *str = intptr_arg(str, args, *count);
  return *str;  // указатель на элемент строки, с которого надо продолжить
                // печать
}

char *int_arg(char **str, flags f, va_list *args, unsigned int *count) {
  long int x = va_arg(*args, long int);
  if (f.length == 'h')
    x = (short)x;
  else if (f.length == 0)
    x = (int)x;
  char *num = calloc(21, sizeof(char));
  char *all_num = num;  // аллоцируем память для массива с буферным результатом
  itoa(x, num, 10);     // переводим число в строку
  if (x == 0 && f.is_accuracy && !f.accuracy)
    num[0] = 0;  // особенность работы с нулём
  if (num[0] == '-') num++;  // пока не берём во внимание минус
  int i = 0;
  int size =
      (21 + 2) > (f.accuracy + 2 > f.width + 2 ? f.accuracy + 2 : f.width + 2)
          ? 21 + 2
          : (f.accuracy + 2 > f.width + 2 ? f.accuracy + 2 : f.width + 2);
  char *result =
      calloc(size, sizeof(char));  // аллоцируем память для записи результата
                                   // (числа с форматированием)
  filling(result, f, &i,
          s21_strlen(num));  // обрабатываем ширину если не флаг -
  put_sign(x < 0 ? 1 : 0, f, result, i);  // ставим знак, если нужен
  for (; (f.accuracy - (int)s21_strlen(num)) > 0; i++, f.accuracy--) {
    s21_strcat(result, "0");  // дополняем до нужной точности нулями
  }
  s21_strcat(result, num);  // записываем результат из буфера
  if (f.minus) {            // если есть флаг минус
    for (; (int)s21_strlen(result) < f.width;) s21_strcat(result, " ");
  }  // то пробелы для ширины надо вставлять уже после числа
  s21_strcat(*str, result);  // записываем результат в строку для печати
  unsigned int check =
      s21_strlen(result);  // считаем, сколько символов добавится
  *count += check;  // учитываем их в подсчёте напечатанных символов
  free(result);
  free(all_num);
  return *str + check;  // возвращаем элемент строки после того символа, где мы
                        // закончили печатать
}

void put_sign(int minus, flags f, char *result, int i) {
  int sign_place = 0;
  if (!(result[0] == '0' || i == 0)) sign_place = i - 1;
  if (minus)
    result[sign_place] = '-';
  else if (f.plus)
    result[sign_place] = '+';
  else if (f.space)
    result[sign_place] = ' ';
}

char *itoa(int64_t value, char *result, int base) {
  char *symbol =
      "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz";
  symbol += 35;  // сдвигаемся в положение нуля
  int sign = value < 0 ? 1 : 0;  // сохраняем знак числа
  int i = 0;
  if (!value)  // если 0
    result[i] = '0';
  for (; value;
       i++) {  // пока число не 0, сдвигаемся для записи следующей цифры числа
    result[i] = symbol[value - ((value / base) *
                                base)];  // записываем последнюю цифру числа
    value /= base;  // делим число на базу
  }
  if (sign) result[i] = '-';  // если был знак, печатаем
  result[i + 1] = 0;          // терминирующий 0
  // мы получили число, написанное наоборот
  // разворачиваем число
  char temp = 0;
  for (unsigned int i = 0; i < s21_strlen(result) / 2; i++) {
    temp = result[i];
    result[i] = result[s21_strlen(result) - 1 - i];
    result[s21_strlen(result) - 1 - i] = temp;
  }
  return result;
}

void filling(char *result, flags f, int *i, int strlength) {
  // если нужно работать с шириной
  for (; !f.minus &&
         (f.width - (f.accuracy > strlength ? f.accuracy : strlength) > 0);
       (*i)++, f.width--) {
    if (!f.is_accuracy && f.zero)
      result[(*i)] = '0';
    else
      result[(*i)] = ' ';
  }
}

char *uints_arg(char **str, flags f, va_list *args, unsigned int *count) {
  unsigned long int x = va_arg(*args, unsigned long int);
  char num[21] = {0};

  if (f.length == 'h')
    x = (unsigned short)x;
  else if (f.length == 0)
    x = (unsigned int)x;

  if (f.specificator == 'o') {
    uitoa(x, num, 8);
  } else if (f.specificator == 'u') {
    uitoa(x, num, 10);
  } else {
    uitoa(x, num, 16);
  }
  if (f.specificator == 'X') to_upper(num);  // меняем регистр
  if (x == 0 && f.is_accuracy && !f.accuracy)
    num[0] = 0;  // так оригинал воспринимает 0

  int i = 0;
  int size =
      (24 + 2 > (f.accuracy + 2 > f.width + 2 ? f.accuracy + 2 : f.width + 2)
           ? 24 + 2
           : (f.accuracy + 2 > f.width + 2 ? f.accuracy + 2 : f.width + 2));
  char *result =
      calloc(size, sizeof(char));  // массив для форматированного числа

  filling(result, f, &i, s21_strlen(num));      // печатаем ширину
  print_base(f, x, result, &i, &(f.accuracy));  // печатаем базу

  for (; f.accuracy - (int)s21_strlen(num) > 0; i++, f.accuracy--) {
    result[i] = '0';  // если нужна точность - печатаем её
  }
  result[i] = '\0';
  s21_strcat(result, num);  // добавляем число в форматированную строку
  if (f.minus) {  // если ширину надо печатать после числа
    for (; (int)s21_strlen(result) < f.width;) s21_strcat(result, " ");
  }
  s21_strcat(*str, result);
  unsigned int check = s21_strlen(result);  // считаем новые символы
  *count += s21_strlen(result);  // увеличиваем счётчик напечатанных символов
  free(result);
  return *str + check;  // сдвигаемся по финальной строке
}

char *uitoa(long long unsigned value, char *result, int base) {
  // itoa с другим типом данных на входе,
  // тк  ui могут переполнить обычный int
  char *symbol =
      "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz";
  symbol += 35;
  char tmp_char = 0;

  int i = 0;
  if (!value) result[i] = '0';
  for (; value; i++) {
    result[i] = symbol[value - ((value / base) * base)];
    value /= base;
  }
  result[i + 1] = 0;

  for (unsigned int i = 0; i < s21_strlen(result) / 2; i++) {
    tmp_char = result[i];
    result[i] = result[s21_strlen(result) - 1 - i];
    result[s21_strlen(result) - 1 - i] = tmp_char;
  }
  return result;
}

void to_upper(char *x) {
  // приводит буквы к верхнему регистру
  for (int i = 0; x[i]; i++) {
    if (x[i] >= 'a' && x[i] <= 'z') x[i] -= 32;
  }
}

void print_base(flags f, unsigned long x, char *result, int *i, int *accuracy) {
  if (f.hash && x != 0) {  // если надо написать базу числа
    int base_place = 0;           // место для записи базы
    if (f.specificator == 'o') {  // если число 8-ное
      if ((*i) > 0 && result[(*i) - 1] == ' ')
        base_place = (*i) - 1;      // если база не в начале
      if (base_place == 0) (*i)++;  // сдвигаемся по строке
      result[base_place] = '0';  // записали базу в нужно место
      (*accuracy)--;  // у 8-ного числа база учитывается в точности
    } else if (f.specificator == 'x' ||
               f.specificator == 'X') {  // если 16-ричное
      if ((*i) > 1 &&
          result[(*i) - 1] == ' ') {  // если можем взять оба символа из ширины
        base_place = (*i) - 2;  // то запишем базу в счёт ширины
      } else if ((*i) == 1 &&
                 result[(*i) - 1] == ' ') {  //заберём один символ из ширины
        (*i)++;  // поэтому сдвиг для дальнейшей записи будет в один символ
      } else {  // если не сможем взять из ширины, оба символа базы запишутся с
                // текущей позиции
        (*i) += 2;  // поэтому сдвигаемся на 2
      }
      result[base_place] = '0';  // первый символ 16-ричной базы - 0
      result[base_place + 1] = f.specificator;  // второй - x или X
    }
  }
}

char *double_arg(char **str, flags f, va_list *args, unsigned int *count) {
  long double x, x1;
  int og = 0, i = 0, length = 0, inf_or_nan = 0;
  if (f.length == 'L')
    x1 = x = va_arg(*args, long double);
  else
    x1 = x = va_arg(*args, double);
  char num[500] = {0};   // массив для числа
  char *nu = &(num[1]);  // оставляем первую ячейку на случай удлинения числа
  int accuracy = f.is_accuracy ? f.accuracy : 6;  // по умолчанию - 6
  inf_or_nan = value_to_str(x, nu, x1, &length);  //  запишем число в строку
  if (!inf_or_nan) {  // если нормальное число
    g_treatment(&(f.specificator), &accuracy, nu, &og,
                x);  // предобработка для g/G
    if (f.specificator == 'e' || f.specificator == 'E') {
      e_arg(x, f, accuracy, &nu, og);  // обработаем и округлим как e/E
    } else {
      rounding_double(length, accuracy, nu, f);
      cut_zeros(nu, f, og);  // если нужно, отрежем нули после десятичной точки
    }
    if ((nu[s21_strlen(nu) - 1] == '.') && !(f.specificator == 'f' && f.hash))
      nu[s21_strlen(nu) - 1] = 0;
    // если последним символом стала точка и её не нужно оставлять - убираем
  }
  if (nu[-1]) nu = num;
  int size = ((unsigned int)(f.width + 2) > (s21_strlen(nu) + 2)
                  ? (unsigned int)(f.width + 2)
                  : (s21_strlen(nu) + 2));
  char *result =
      calloc(size + 1, sizeof(char));  // массив для отформатированного числа
  for (; !f.minus && (f.width - (int)s21_strlen(nu) > 0); i++, f.width--) {
    if (f.zero)
      result[i] = '0';  // заполняем ширину нулями
    else
      result[i] = ' ';  // или пробелами
  }
  if (!inf_or_nan) {
    put_sign(x < 0. ? 1 : 0, f, result, i);
  } else if (isinf(x) > 0 || isnan(x)) {
    put_sign(0, f, result, i);
  }
  if (f.specificator == 'E' || f.specificator == 'G') to_upper(nu);
  if (num[0] != 0)
    s21_strcat(result,
               num);  // копируем в финальную строку вместе с нулевой ячейкой
  else
    s21_strcat(result, nu);  // или без
  if (f.minus)
    for (; (int)s21_strlen(result) < f.width;)
      s21_strcat(result, " ");  // ширина
  int check = s21_strlen(result);
  s21_strcat(*str, result);
  *count += check;
  free(result);
  return *str + check;
}

int value_to_str(long double x, char *nu, long double x1, int *length) {
  int inf_or_nan = 0;
  if (isnan(x)) {           // если аргумент дал nan
    s21_strcat(nu, "nan");  // записываем его в строку
    inf_or_nan = 1;         // отмечаем его
  } else if (isinf(x)) {  // тоже самое с inf, но тут ещё есть знак
    if (isinf(x) > 0)
      s21_strcat(nu, "inf");
    else
      s21_strcat(nu, "-inf");
    inf_or_nan = 1;
  } else {  // если всё в порядке, записываем число в строку
    dtos(x, x1, nu, length);
  }
  return inf_or_nan;
}

void dtos(long double x, long double x1, char *nu, int *length) {
  if (x < 0) x *= -1;
  x1 = (x - fmodl(x, 1));
  char *kind_of_int = nu;

  if (x1 == 0) {
    nu[0] = '0';
  } else {
    recursive_long_int(x, 1, &kind_of_int);
  }
  s21_strcat(nu, ".");  // после печати целой части печатаем точку

  *length = s21_strlen(nu);  // отмечаем длину получившегося числа
  x1 = x =
      fabsl(fmodl(x, 1));  // берём дробную часть исходного числа (по модулю)
  char digit[2] = {'0', 0};  // строка для стркатов
  for (int z = 0; z < 50; z++) {  // максимально печатаемая точность 49
    x1 = x = x * 10;  // первое число после точки ставим перед точкой
    x1 -= fmodl(x1, 1);  // убираем дробную часть числа, так что останется
                         // только цифра перед точкой
    digit[0] = x1 + '0';  // записываем эту цифру в строку для стркатов
    s21_strcat(
        nu,
        digit);  // добавляем её в строку, в которую записываем исходное число
    x1 = x = fmodl(x, 1);  // записываем сюда десятичную часть исходного числа
    // после того, как забрали из неё ещё один символ
  }
}

void recursive_long_int(long double d_arg, int symbols, char **str) {
  long double divider = powl(10, symbols);
  int temp =
      (int)(fmodl(d_arg, divider) / (divider / 10.));  // берём нужную цифру
  if (d_arg / divider >= 1) {  // если число можно делить дальше
    symbols++;
    recursive_long_int(d_arg, symbols, str);
  } else if ((int)d_arg == 0) {
    temp = 0;  // где нужно, запишем 0
  }
  itoa_helper(temp, str);  //из инта в чар
}

void itoa_helper(int new_num, char **str) {
  **str = new_num + '0';  // записываем в строчку нужный чар
  (*str)++;               // сдвигаемся
  **str = '\0';
}

void g_treatment(int *specificator, int *accuracy, char *nu, int *og,
                 long double x) {
  if (*specificator == 'e' || *specificator == 'E' || *specificator == 'g' ||
      *specificator == 'G') {
    if (*specificator == 'g' || *specificator == 'G') *og = 1;
    int expo = 0, expo_help = 1;
    if ((x < 10 && x > -10) && fmodl(x, 1) == 0) expo_help = 0;
    if (expo_help) {  // если эксопнента больше нуля по модулю
      if (nu[0] > '0') {  // положительная экспонента
        for (; nu[expo] != '.'; expo++)
          ;  // будет равна номеру позиции десятичной точки -1
      } else {
        for (; nu[expo] == '0' || nu[expo] == '.'; expo++)
          ;  // будет равна позиции первого ненулевого символа -1
      }
      expo--;  // вычитаем единицу
      if (nu[0] == '0')
        expo *= -1;  // если экспонента должна быть отрицательной
    }
    if (*specificator == 'g' || *specificator == 'G') {
      if (*accuracy == 0) *accuracy = 1;
      if ((-4 <= expo && expo < *accuracy) ||
          !expo) {  // тогда g работает как f
        *accuracy = *accuracy - expo - 1;  // но меняет точность
      } else {
        *accuracy -= 1;  // меняет точность
        *specificator -= 2;  // меняем спецификатор с g/G на e/E
        *og = 1;  // отмечаем, что изначально это был g/G
      }
    }
    if (*accuracy < 0) *accuracy = 0;  // если точность стала отрицательной
  }
}

void e_arg(long double x, flags f, int accuracy, char **nu, int og) {
  char *nu1 = *nu;
  int i = 0;
  char *all_nu = calloc(s21_strlen(nu1), sizeof(char));
  e_to_str(x, nu1, all_nu, f, &i,
           accuracy);  // правильно записываем мантиссу в строку
  if (og && !f.hash) {  // если g и нужно отрезать нули
    for (int s = s21_strlen(nu1) - 1; s > 0 && nu1[s] == '0'; s--) nu1[s] = 0;
  }  // то отрезаем нули
  if (x != 0) {  // записываем значение экспоненты в строку
    if (i - 1 < 10) {  // если экспонента меньше 10
      s21_strcat(all_nu, "0");  // первой цифрой экспоненты надо записать 0
      itoa(i - 1, &(all_nu[3]),
           10);  // вставляем значение экспоненты после "e+0" или "e-0"
    } else {  // если экспонента больше 10 по модулю, 0 в начале не нужен
      itoa(i - 1, &(all_nu[2]), 10);
    }
  }
  if (nu1[s21_strlen(nu1) - 1] == '.' && !f.hash)
    nu1[s21_strlen(nu1) - 1] = 0;  // убираем точку, если она не нужна
  s21_strcat(nu1, all_nu);  // к строчке с мантиссой добавляем строчку, в
                            // которой записали экспоненту
  free(all_nu);
}

void e_to_str(long double x, char *nu1, char *all_nu, flags f, int *i,
              int accuracy) {
  if (nu1[0] > '0') {  // в этом случае экспонента будет положительной
    for (; nu1[(*i)] != '.'; (*i)++)
      ;  // и мы ищем её значение по положению точки
    for (int j = *i; j > 1; j--) nu1[j] = nu1[j - 1];  // сдвигаем число
    nu1[1] = '.';  // чтобы была одна цифра до десятичной точки
    s21_strcat(all_nu,
               "e+");  // строчка, в которую будем писать значение экспоненты
    rounding_double(2, accuracy, nu1,
                    f);  // округляем мантиссу до нужной точности
    if (nu1[-1] != 0) {  // если после округления число стало длинее
      nu1[0] = '.';  // смещаем точку на один символ влево
      s21_memmove(
          &nu1[1], &nu1[2],
          accuracy + 1);  // смещаем оставшееся число к новому положению точки
      for (int y = accuracy + 1; y < 80; y++)
        nu1[y] = 0;  // чистим ненужную часть строки
      (*i)++;  // инкрементируем значение экспоненты, потому что сдвинули точку
    }
  } else if (x == 0) {  // если исходное число равно нулю
    s21_strcat(all_nu, "e+00");
    rounding_double(2, accuracy, nu1, f);  // округляем число до нужной точности
  } else {  // иначе экспонента будет отрицательной
    for (; nu1[(*i)] == '0' || nu1[(*i)] == '.'; (*i)++)
      ;  // и равной положению первого ненулевой цифры
    nu1[0] = nu1[(*i)];
    s21_memmove(&nu1[2], &nu1[(*i) + 1],
                accuracy + 1);  // смещаем к точке нужное количество символов
    rounding_double(2, accuracy, nu1, f);  // округляем до нужной точности
    if (nu1[-1] == '1') {  // если после округления число стало длиннее
      nu1[0] = '.';  // смещаем точку влево
      s21_memmove(&nu1[1], &nu1[2],
                  accuracy + 1);  // смещаем оставшуюся часть числа к точке
      (*i)--;  // увеличиваем отрицательную экспоненту из-за смещения точки
    }
    // при увеличении отрицательная экспонента могла стать равной нулю
    if ((*i) - 1 == 0)
      s21_strcat(all_nu, "e+");  // с нулевой экспонентой
    else
      s21_strcat(all_nu, "e-");  // иначе пишем "e-"
  }
}

void rounding_double(int length, int accuracy, char *nu1, flags f) {
  // округляем десятичную дробь в соотвествии с нужной точностью
  unsigned int strlength = s21_strlen(nu1);  // длина строки
  if ((unsigned int)(length + accuracy) <
      s21_strlen(nu1)) {  // если строка должна быть короче
    int s = 1;
    int dot = 0;
    if (nu1[length + accuracy] >= '5') {  // если предыдущую цифру нужно менять
      while (nu1[length + accuracy - s] == '9' ||
             nu1[length + accuracy - s] == '.') {
        // пока встречаем 9-ки или точку
        if (nu1[length + accuracy - s] == '.')
          dot = 1;  // отмечаем точку
        else
          nu1[length + accuracy - s] = '0';  // зануляем число
        s++;  // двигаемся дальше влево
      }
      // если мы оказались в позиции, где числа раньше не было
      if (nu1[length + accuracy - s] == 0)
        nu1[length + accuracy - s] = '1';  // печатаем туда единицу
      else
        nu1[length + accuracy - s] +=
            1;  // иначе число станет больше на единицу
    }
    if (accuracy == 0)
      dot = 1;  // если нужна нулевая точность, тоже отметим точку
    if (!dot) {
      nu1[length + accuracy] =
          0;  // если точки не было, терминирующий 0 после числа
    } else {  // если dot = 1, то цифры числа после точки надо отрезать
      int dot_place = 0;
      for (; nu1[dot_place] != '.'; dot_place++)
        ;  // находим точку
      if (!f.hash && accuracy == 0)
        nu1[dot_place] = 0;  // если её надо оставить - оставляем
      else
        nu1[dot_place + accuracy + 1] =
            0;  // если нет - отрезаем вместе с остатком числа
    }
    for (unsigned int sl = s21_strlen(nu1); sl < strlength; sl++)
      nu1[sl] = 0;  // чистим остаток строки
  }
}

void cut_zeros(char *nu, flags f, int og) {
  if (og && !f.hash) {  // если изначально это было g/G
    int is_dot = 0;
    // ищем точку и отрезаем нули в конце
    for (unsigned int s = 0; s < s21_strlen(nu); s++)
      if (nu[s] == '.') is_dot = 1;
    for (int s = s21_strlen(nu) - 1; is_dot && s > 0 && nu[s] == '0'; s--)
      nu[s] = 0;
  }
}

char *char_arg(char **str, flags f, va_list *args, const char **format,
               unsigned int *count) {
  wint_t x = va_arg(*args, wint_t);
  if (f.length != 'l') x = (char)x;
  if (f.length == 'l' && x > 127) {
    (**str) = '\0';  // так делает оригинальный спринтф
    *format =
        0;  // он вернёт код ошибки, поэтому зануляем форматированную строку
  } else {  // иначе, если нужно допечатать ширину пробелами
    for (; !f.minus && (f.width - 1 > 0); (*str)++, f.width--, (*count)++) {
      (**str) = ' ';
    }
    (**str) = x;  // и пишем символ
    (*str)++;
    (*count)++;
    if (f.minus) {
      for (; (f.width - 1 > 0); (*str)++, f.width--, (*count)++) {
        (**str) = ' ';
      }  // то делаем ширину после символа
    }
    **str = '\0';
  }
  return *str;
}

char *string_arg(char **str, flags f, va_list *ptr, const char **format,
                 unsigned int *count) {
  if (f.length == 'l') {
    wstring_arg(str, f, ptr, format, count);
  } else {
    char *x = va_arg(*ptr, char *);
    int i = 0;
    int length = x == 0 ? 6 : (int)s21_strlen(x);
    if (f.is_accuracy && f.accuracy < length) length = f.accuracy;
    if (f.is_accuracy && x == 0 && f.accuracy < 6) length = 0;
    int size = (length > f.width ? length : f.width) + 2;
    char *result = calloc(size, sizeof(char));  // массив нужной длины
    for (; !f.minus && (f.width - length > 0); i++, f.width--) {
      result[i] = ' ';  // заполняем ширину
    }
    if (x != 0) {  // если не нулевой указатель
      for (int r = 0; r < length; r++, i++) {
        result[i] = x[r];  // копируем строку
      }
    } else if (length != 0) {  // если указатель нулевой и длины хватит
      char *string = "(null)";
      for (int t = 0; t < 7; t++, i++) result[i] = string[t];
    }
    result[i] = '\0';
    if (f.minus) {
      for (; (int)s21_strlen(result) < f.width;) s21_strcat(result, " ");
    }  // дополняем ширину при необходимости
    s21_strcat(*str, result);  // копируем нашу строку в финальную строку
    *str +=
        s21_strlen(result);  // сдвигаемся на количество напечатанных символов
    *count += s21_strlen(result);  // и учитываем их в счётчике
    free(result);
  }
  return *str;
}

char *wstring_arg(char **str, flags f, va_list *args, const char **format,
                  unsigned int *count) {
  // почти тоже самое, что для строки обычных символов
  // но если строка ненулевая
  // и там правда есть широкий символ, выходящий за рамки ASCII
  // то функция поставит терминирующий 0 в финальную строку и вернёт ошибку
  int d = 0;
  wchar_t *x = va_arg(*args, wchar_t *);
  if (x != 0) {
    for (; d >= 0 && x[d]; d++)
      if (x[d] > 127) d = -2;
  }

  if (d < 0) {
    **str = 0;
    *format = 0;  //отмечаем, что случилась ошибка
  } else {        // дальше как в обычной строке
    int i = 0;
    int length = x == 0 ? 6 : d;
    if (f.is_accuracy && f.accuracy < length) length = f.accuracy;
    if (f.is_accuracy && x == 0 && f.accuracy < 6) length = 0;
    int size = (length > f.width ? length : f.width) + 2;
    char *result = calloc(size, sizeof(char));

    for (; !f.minus && (f.width - length > 0); i++, f.width--) {
      result[i] = ' ';
    }
    if (x != 0) {
      for (int q = 0; q < length; q++, i++) {
        result[i] = x[q];
      }
    } else if (length != 0) {
      char *string = "(null)";
      for (int rt = 0; rt < 7; rt++, i++) result[i] = string[rt];
    }
    result[i] = '\0';
    if (f.minus) {
      for (; (int)s21_strlen(result) < f.width;) s21_strcat(result, " ");
    }
    s21_strcat(*str, result);
    *str += s21_strlen(result);
    *count += s21_strlen(result);
    free(result);
  }
  return *str;
}

char *ptr_arg(char **str, flags f, va_list *args, unsigned int *count) {
  uint64_t x = va_arg(*args, uint64_t);
  char num[20] = {
      0};  // сюда будем записывать значение указателя без форматирования
  if (x == 0)
    s21_strcat(num, "(nil)");  // если нулевой указатель
  else
    itoa(x, num, 16);  // записываем значение указателя
  int size =
      (20 + 4 > (f.accuracy + 4 > f.width + 2 ? f.accuracy + 4 : f.width + 2)
           ? 20 + 4
           : (f.accuracy + 4 > f.width + 2 ? f.accuracy + 4 : f.width + 2));
  char *result =
      calloc(size, sizeof(char));  // массив для записи с форматированием
  // 0x в начале числа учитывается в ширине, но не в точности, поэтому в одном
  // месте +2, в другом +4
  int i = 0;
  for (; !f.minus && (f.width -
                          ((f.accuracy * (x != 0)) > (int)s21_strlen(num)
                               ? (f.accuracy * (x != 0))
                               : (int)s21_strlen(num)) -
                          2 * (x != 0) >
                      0);
       i++, f.width--) {
    result[i] = ' ';  // если нужно печатать ширину - печатаем
  }
  if (x != 0) {  // если не нулевой указатель
    if (f.plus == 1 || f.space == 1) {  // и нужно напечатать + или пробел
      if (i != 0) {
        result[i - 1] = f.plus ? '+' : ' ';  // печатаем за счёт ширины
      } else {                           // если ширины не было
        result[i] = f.plus ? '+' : ' ';  // печатаем первым символом
        i++;  // и сдвигаемся по строке
      }
    }
    result[i] = '0';  // печатаем базу 16-ричного числа
    result[i + 1] = 'x';
    i += 2;  // и сдвигаеся для дальнейшей печати
  }

  for (; x != 0 && f.accuracy - (int)s21_strlen(num) > 0; i++, f.accuracy--) {
    result[i] = '0';  // если нужно дополнить нулями
  }
  result[i] = '\0';
  s21_strcat(result,
             num);  // записываем значение указателя в форматированную строчку
  if (f.minus) {  // если шириной нужно дополнять после
    for (; (int)s21_strlen(result) < f.width;) s21_strcat(result, " ");
  }
  unsigned int check = s21_strlen(result);
  s21_strcat(*str, result);
  *count += check;
  free(result);
  return *str + check;
}

char *intptr_arg(char **str, va_list *args, unsigned int count) {
  // этот флаг ничего не дописывает в строку
  int *x = va_arg(*args, int *);  // берёт место, в которое записать инт
  *x = count;  // записывает количество напечатанных к данному моменту символов
  return *str;
}