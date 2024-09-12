#include "s21_math.h"

int s21_abs(int x) { return (int)s21_fabs(x); }

long double s21_ceil(double x) {
  long double result = (long long int)x;
  if (S21_IS_NAN(x) || S21_IS_INF(x)) {
    result = x;
  } else if ((x > -1.) && (x < 0.0)) {
    result = -0.0;
  } else if ((x > 0.) && (x != result)) {
    result += 1;
  }
  return result;
}

long double s21_fabs(double x) {
  if (x < 0) {
    x = -x;
  }
  return (long double)x;
}

long double s21_floor(double x) {
  long double result = (long long int)x;
  if ((x < 0.) && (x != result)) {
    result -= 1;
  }
  return result;
}

long double s21_fmod(double x, double y) {
  int flag_minus_x = (x < 0 ? 1 : 0), flag_minus_y = (y < 0 ? 1 : 0);
  double buffer = y;
  x = s21_fabs(x);
  y = s21_fabs(y);
  if (y != 0) {
    while (y < x) {
      y += buffer;
    }
    y -= buffer;
    x = x - y;
  } else {
    x = S21_NAN;
  }
  x = (flag_minus_x == 1 ? -x : x);
  x = (flag_minus_y == 1 ? -x : x);
  return (long double)(x);
}

long double s21_asin(double x) {
  long double result = 0;
  if (S21_IS_NAN(x) || S21_IS_INF(x)) {
    result = S21_NAN;
  } else {
    if (x == 1.0)
      result = S21_PI / 2;
    else if (x == -1.0)
      result = -S21_PI / 2;
    else
      result = s21_atan((x) / s21_sqrt(1 - s21_pow(x, 2)));
  }
  return result;
}

long double s21_acos(double x) {
  long double result = S21_PI / 2;
  if (S21_IS_NAN(x) || S21_IS_INF(x)) {
    result = S21_NAN;
  } else {
    if (s21_fabs(x) > 1.0) {
      result = S21_NAN;
    } else if (x == 1.0) {
      result = 0;
    } else if (x == (-1.0)) {
      result = S21_PI;
    } else if (x > 0) {
      result = s21_atan(s21_sqrt(1 - s21_pow(x, 2)) / (x));
    } else if (x < 0) {
      result = S21_PI + s21_atan(s21_sqrt(1 - s21_pow(x, 2)) / (x));
    }
  }
  return result;
}

long double s21_atan(double x) {
  long double result = 0;
  long double argument = x;

  if (s21_fabs(x) > 1) {
    argument = 1 / x;
  }

  long double mono = argument;

  for (int i = 1; i < 10; i++) {
    result += mono;
    mono *= (-1) * argument * argument / (2 * i + 1) / (2 * i - 1);
  }

  if (s21_fabs(x) > 1) {
    result = S21_PI / 2 - result;
  }

  return result;
}

long double s21_cos(double x) {
  long double result = 1.0;
  int znak = -1;
  if (S21_IS_NAN(x) || S21_IS_INF(x)) {
    result = S21_NAN;
  } else {
    x = s21_fmod(x, S21_PI * 2.0);

    if ((x > (S21_PI / 2.0)) && (x <= S21_PI)) {
      x = S21_PI - x;
    } else if (x > S21_PI && x <= ((S21_PI * 3.0) / 2.0)) {
      x -= S21_PI;
    } else if (x > ((S21_PI * 3.0) / 2.0) && x <= (S21_PI * 2.0)) {
      x = (2.0 * S21_PI) - x;
      znak = 1;
    } else {
      znak = 1;
    }

    long double valueTailor = 1.0;
    for (int i = 1; i < 200; i++) {
      result += (valueTailor =
                     ((-valueTailor) * x * x) / ((2.0 * i - 1) * (2.0 * i)));
    }
    result *= znak;
  }
  return result;
}

long double s21_factorial(long long int x) {
  long double result = 1;
  result = ((x == 0) || (x == 1)) ? 1 : x * s21_factorial(x - 1);
  return result;
}

long double s21_exp(double x) {  // 1 + x + x^2 / 2! + x^3 / 3! + ...
  long double result = 0;
  if (x > 709) {
    result = S21_INF_POS;
  } else if ((x != S21_INF_NEG) && (x >= -20)) {
    result = 1 + x;
    long double mult_x = x;
    for (int i = 2; i < 97; i++) {
      mult_x *= x;
      result += mult_x / s21_factorial(i);
    }
  }
  return result;
}

long double s21_log(double x) {
  long double result = 0, compare = 0;
  int e_repeat = 0;
  if (x == S21_INF_POS) {
    result = x;
  } else if (x == 0) {
    result = S21_INF_NEG;
  } else if (x < 0) {
    result = S21_NAN;
  } else {
    for (; x >= S21_E; e_repeat++) {
      x /= S21_E;
    }
    for (int i = 0; i < 100; i++) {
      compare = result;
      result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    }
    result += e_repeat;
  }
  return result;
}

long double s21_pow(double x, double y) {
  long double result = 0;
  if ((y == 0.0) || (x == 1.0) || (S21_IS_INF(y) && (s21_fabs(x) == 1.0))) {
    result = 1.;
  } else if (((S21_IS_NAN(x)) && (S21_IS_NAN(y))) ||
             ((x < 0) && (s21_fabs(y) < 1))) {
    result = S21_NAN;
  } else if (((x == 0.0) && (y < 0.0)) ||
             (S21_IS_INF(y) && (s21_fabs(x) > 1.0) && (y > 0.0)) ||
             (S21_IS_INF(y) && (s21_fabs(x) < 1.0) && (y < 0.0))) {
    result = S21_INF_POS;
  } else if ((x == 0.0) ||
             (S21_IS_INF(y) && (s21_fabs(x) > 1.0) && (y < 0.0)) ||
             (S21_IS_INF(y) && (s21_fabs(x) < 1.0) && (y > 0.0))) {
    result = 0.0;
  } else {
    result = s21_exp(y * s21_log(s21_fabs(x)));
    if (x < 0.0 && s21_fmod(y, 2.0) != 0.0) {
      result *= -1;
    }
  }
  return result;
}

long double s21_sin(double x) {
  long double result = x;
  int znak = -1;
  if (S21_IS_NAN(x) || S21_IS_INF(x)) {
    result = S21_NAN;
  } else {
    x = s21_fmod(x, S21_PI * 2.0);

    if ((x > (S21_PI / 2.0)) && (x <= S21_PI)) {
      x = S21_PI - x;
      znak = 1;
    } else if (x > S21_PI && x <= ((S21_PI * 3.0) / 2.0))
      x -= S21_PI;
    else if (x > ((S21_PI * 3.0) / 2.0) && x <= (S21_PI * 2.0))
      x = (2.0 * S21_PI) - x;
    else
      znak = 1;

    result = (long double)x;
    long double valueTailor = (long double)x;
    for (int i = 1; s21_fabs(valueTailor / result) > 1e-100; i += 1) {
      result += (valueTailor =
                     ((-valueTailor) * x * x) / ((2.0 * i + 1) * (2.0 * i)));
    }
    result *= znak;
  }
  return result;
}

long double s21_sqrt(double x) { return s21_pow(x, 0.5); }

long double s21_tan(double x) {
  long double result = 0.0;
  if (S21_IS_NAN(x) || S21_IS_INF(x)) {
    result = S21_NAN;
  } else {
    result = s21_sin(x) / s21_cos(x);
  }
  return result;
}
