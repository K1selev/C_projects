#include "credit_calc.h"

double calculate_annuitet(double tel_cred, double proc_cred, int month_cred) {
  double ans = 0.0;
  double PS = proc_cred / (100 * 12);
  ans = tel_cred * (PS / (1 - pow((1 + PS), -month_cred)));
  ans = floor(ans * 100.0 + 0.5) / 100.0;
  return ans;
}

double annuitet_percent(double tel_cred, double proc_cred, int month_cred) {
  double anu, ans;
  anu = calculate_annuitet(tel_cred, proc_cred, month_cred);
  ans = (anu * month_cred) - tel_cred;
  ans = floor(ans * 100.0 + 0.5) / 100.0;
  return ans;
}

double annuitet_dolg_proc(double tel_cred, double proc_cred, int month_cred) {
  double ans = 0.0, anu_perc;
  anu_perc = annuitet_percent(tel_cred, proc_cred, month_cred);
  ans = tel_cred + anu_perc;
  ans = floor(ans * 100.0 + 0.5) / 100.0;
  return ans;
}

double dif_month_min(double tel_cred, double proc_cred, int month_cred) {
  double ans = 0.0;
  ans = tel_cred / month_cred;
  double i = proc_cred / 100;
  ans = floor(ans * 100.0 + 0.5) / 100.0;
  ans = ans + (tel_cred - ans * 0) * i / 12;
  return ans;
}

double dif_month_max(double tel_cred, double proc_cred, int month_cred) {
  double ans = 0.0;
  ans = tel_cred / month_cred;
  double i = proc_cred / 100;
  ans = ans + (tel_cred - ans * (month_cred - 1)) * i / 12;
  return ans;
}

double dif_pereplat(double tel_cred, double proc_cred, int month_cred) {
  double ans = 0.0;
  double ep = tel_cred / month_cred;
  double i = proc_cred / 100;
  int idx;
  for (idx = 0; idx < month_cred; ++idx) {
    ans += (ep + (tel_cred - ep * (idx)) * i / 12);
  }
  ans = ans - tel_cred;
  return ans;
}

double dif_total(double tel_cred, double proc_cred, int month_cred) {
  double ans = 0.0;
  double ep = tel_cred / month_cred;
  double i = proc_cred / 100;
  int idx;
  for (idx = 0; idx < month_cred; ++idx) {
    ans += (ep + (tel_cred - ep * (idx)) * i / 12);
  }
  return ans;
}