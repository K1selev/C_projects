#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCoreApplication>
#include <QMainWindow>
#include <QRegularExpressionValidator>
#include <QString>

extern "C" {
#include <locale.h>

#include "calculate.h"
#include "credit_calc.h"
#include "parse_string.h"
#include "s21_helper.h"
#include "stack.h"
}

#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:

  void on_Del_clicked();

  void on_Mul_clicked();

  void on_button_tchk_clicked();

  void on_Minus_clicked();

  void on_plus_clicked();

  void on_C_clicked();

  void on_percent_clicked();

  void on_AC_clicked();

  void on_button_0_clicked();

  void on_button_00_clicked();

  void on_button_1_clicked();

  void on_button_2_clicked();

  void on_button_3_clicked();

  void on_button_4_clicked();

  void on_button_5_clicked();

  void on_button_6_clicked();

  void on_button_7_clicked();

  void on_button_8_clicked();

  void on_buton_9_clicked();

  void on_Sqrt_clicked();

  void on_UnarPL_clicked();

  void on_L_BR_clicked();

  void on_R_BR_clicked();

  void on_sin_clicked();

  void on_cos_clicked();

  void on_tan_clicked();

  void on_ln_clicked();

  void on_log_clicked();

  void on_atan_clicked();

  void on_acos_clicked();

  void on_asin_clicked();

  void on_Mod_clicked();

  void on_X_clicked();

  void on_equal_clicked();

  void check_param_scale(double *a, double *b, double *h);

  void on_pushButton_clicked();

  void on_calc_credit_clicked();

  void on_time_credit_textChanged(const QString &arg1);

 private:
  Ui::MainWindow *ui;
  QCustomPlot *customPlot;
  QCPGraph *graphic;
};
#endif  // MAINWINDOW_H
