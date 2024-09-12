#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  setlocale(LC_NUMERIC, "C");
  ui->setupUi(this);
  setWindowTitle("Calculator");
  ui->parsed_x->setValidator(new QRegularExpressionValidator(
      QRegularExpression("^[0-9]{1,10}.[0-9]{1,7}"), this));
  ui->set_x->setValidator(new QRegularExpressionValidator(
      QRegularExpression("^[+-]?[0-9]{1,7}.[0-9]{1,7}"), this));
  ui->set_y->setValidator(new QRegularExpressionValidator(
      QRegularExpression("^[+-]?[0-9]{1,7}.[0-9]{1,7}"), this));
  ui->set_scale->setValidator(new QRegularExpressionValidator(
      QRegularExpression("^[+-]?[0-9]{1,7}.[0-9]{1,7}"), this));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_Del_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_Mul_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_button_tchk_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    ui->parsed_string->insert(button->text());
  }
}

void MainWindow::on_Minus_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_plus_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_C_clicked() {
  if (ui->parsed_string->text().contains("ERROR!")) {
    ui->parsed_string->clear();
  } else {
    ui->parsed_string->backspace();
  }
}

void MainWindow::on_percent_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    ui->parsed_string->insert(button->text());
  }
}

void MainWindow::on_AC_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    ui->parsed_string->clear();
  }
}

void MainWindow::on_button_0_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_button_00_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_button_1_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_button_2_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_button_3_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_button_4_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_button_5_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_button_6_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_button_7_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_button_8_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_buton_9_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_Sqrt_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert("sqrt(");
    } else {
      ui->parsed_string->insert("sqrt(");
    }
  }
}

void MainWindow::on_UnarPL_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      if (ui->parsed_string->text().endsWith("+")) {
        ui->parsed_string->backspace();
        ui->parsed_string->insert("-");
      } else if (ui->parsed_string->text().endsWith("-")) {
        ui->parsed_string->backspace();
        ui->parsed_string->insert(button->text());
      } else {
        ui->parsed_string->insert("+");
      }
    } else {
      if (ui->parsed_string->text().endsWith("+")) {
        ui->parsed_string->backspace();
        ui->parsed_string->insert("-");
      } else if (ui->parsed_string->text().endsWith("-")) {
        ui->parsed_string->backspace();
        ui->parsed_string->insert(button->text());
      } else {
        ui->parsed_string->insert("+");
      }
    }
  }
}

void MainWindow::on_L_BR_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_R_BR_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_sin_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert("sin(");
    } else {
      ui->parsed_string->insert("sin(");
    }
  }
}

void MainWindow::on_cos_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert("cos(");
    } else {
      ui->parsed_string->insert("cos(");
    }
  }
}

void MainWindow::on_tan_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert("tan(");
    } else {
      ui->parsed_string->insert("tan(");
    }
  }
}

void MainWindow::on_ln_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert("ln(");
    } else {
      ui->parsed_string->insert("ln(");
    }
  }
}

void MainWindow::on_log_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert("log(");
    } else {
      ui->parsed_string->insert("log(");
    }
  }
}

void MainWindow::on_atan_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert("atan(");
    } else {
      ui->parsed_string->insert("atan(");
    }
  }
}

void MainWindow::on_acos_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert("acos(");
    } else {
      ui->parsed_string->insert("acos(");
    }
  }
}

void MainWindow::on_asin_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert("asin(");
    } else {
      ui->parsed_string->insert("asin(");
    }
  }
}

void MainWindow::on_Mod_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_X_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_equal_clicked() {
  QString parsed = ui->parsed_string->text();
  std::string str = parsed.toStdString();
  char* data = (char*)calloc(sizeof(char), 255);
  char* polish = (char*)calloc(sizeof(char), 255);
  if (data) {
    strcpy(data, str.c_str());
  }
  int status = parse_string(data, polish);
  if (status) {
    double x;
    ui->parsed_string->clear();
    if (ui->parsed_x->text().isEmpty()) {
      x = 1.0;
    } else {
      x = ui->parsed_x->text().toDouble();
    }
    double res = calculate(polish, x);
    ui->parsed_string->insert(QString::number(res, 'g', 7));
  } else {
    ui->parsed_string->clear();
    ui->parsed_string->insert("ERROR!");
  }
}

void MainWindow::on_pushButton_clicked() {
  QString parsed = ui->parsed_string->text();
  std::string str = parsed.toStdString();
  char* data = (char*)calloc(sizeof(char), 255);
  char* polish = (char*)calloc(sizeof(char), 255);
  if (data) {
    strcpy(data, str.c_str());
  }
  int status = parse_string(data, polish);
  double x_str, a = -10, b = 10, h = 0.1;
  check_param_scale(&a, &b, &h);
  int N = (b - a) / h + 1;
  QVector<double> x(N), y(N);
  int i = 0;
  for (double X = a; X <= b; X = a + h * i) {
    double res = calculate(polish, X);
    x[i] = X;
    y[i] = res;
    ++i;
  }
  ui->widget->clearGraphs();
  ui->widget->addGraph();
  ui->widget->graph()->addData(x, y);
  ui->widget->graph()->setLineStyle(QCPGraph::lsNone);
  ui->widget->graph(0)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssDisc, 1));
  ui->widget->xAxis->setLabel("X");
  ui->widget->yAxis->setLabel("Y");
  ui->widget->xAxis->setRange(a, b);
  i = 0;
  while (isnan(y[i]) == true || isinf(y[i]) == true) i++;
  double minY = y[i], maxY = y[i];
  for (double k = i + 1; k < N; ++k) {
    if (isnan(y[k]) == false && isinf(y[k]) == false) {
      if (y[k] <= minY) minY = y[k];
      if (y[k] >= maxY) maxY = y[k];
    }
  }
  double sr = maxY - (maxY - minY) / 2;
  if (strstr(polish, "t") != NULL) {
    minY = sr - 30;
    maxY = sr + 30;
  }
  ui->widget->yAxis->setRange(minY - 0.2, maxY + 0.2);
  ui->widget->replot();
  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->setInteraction(QCP::iRangeDrag, true);
}

void MainWindow::check_param_scale(double* a, double* b, double* h) {
  if (!ui->set_x->text().isEmpty()) {
    *a = ui->set_x->text().toDouble();
  }
  if (!ui->set_x->text().isEmpty()) {
    *b = ui->set_y->text().toDouble();
  }
  if (!ui->set_scale->text().isEmpty()) {
    *h = ui->set_scale->text().toDouble();
  }
  if ((*a / *h) >= 10000000.0 || (*a / *h) <= -10000000.0) {
    QMessageBox errMsg;
    errMsg.about(
        this, "WARNING!!!",
        "Не корректный scale (программа не может отрисовать больше десяти "
        "миллионов точек). Введите пожалуйста корректные параметры!");
    *a = -10;
    *b = 10;
    *h = 0.1;
  }
  if (*a >= *b) {
    QMessageBox errMsg;
    errMsg.about(this, "WARNING!!!",
                 "x_min не может быть больше или равен x_max. Введите "
                 "пожалуйста корректные параметры!");
    *a = -10;
    *b = 10;
    *h = 0.1;
  }
  if ((*b - *a) <= *h) {
    QMessageBox errMsg;
    errMsg.about(this, "WARNING!!!",
                 "Не корректный scale (должен попадать в диапазон махимума и "
                 "минимума для корректной отрисовки графика). Введите "
                 "пожалуйста корректные параметры!");
    *a = -10;
    *b = 10;
    *h = 0.1;
  }
}

void MainWindow::on_calc_credit_clicked() {
  double tel_cred = ui->sum_credit->text().toDouble();
  double proc_cred = ui->percent_credit->text().toDouble();
  int month_cred;
  if (ui->year->currentText() == "месяцев") {
      month_cred = ui->time_credit->text().toInt();
  }
  if (ui->year->currentText() == "лет"){
      if (50 < ui->time_credit->text().toInt()) {
          QMessageBox errMsg;
          errMsg.about(this, "WARNING!!!",
                       "Срок не может превышать 50 лет!");
          ui->time_credit->setValue(50);
      } else {
          month_cred = ui->time_credit->text().toInt() * 12;
      }
  }
  if ( 0.0 >= tel_cred) {
      QMessageBox errMsg;
      errMsg.about(this, "Warning", "Сумма кредита не может быть меньше или равна нулю");
  } else if (0.0 >= proc_cred){
      QMessageBox errMsg;
      errMsg.about(this, "Warning", "Процентная ставка не может быть меньше или равна нулю");
  } else {
      if (ui->annuitet_button->isChecked()) {
        double ans_anu = calculate_annuitet(tel_cred, proc_cred, month_cred);
        double perc_anu = annuitet_percent(tel_cred, proc_cred, month_cred);
        double total_anu = annuitet_dolg_proc(tel_cred, proc_cred, month_cred);
        QString a;
        ui->month_pay->setText(a.setNum(ans_anu, 'f', 2));
        ui->credit_pay->setText(a.setNum(perc_anu, 'f', 2));
        ui->total_pay->setText(a.setNum(total_anu, 'f', 2));
      } else if (ui->diff_button->isChecked()){
        double dif_first = dif_month_min(tel_cred, proc_cred, month_cred);
        double dif_last = dif_month_max(tel_cred, proc_cred, month_cred);
        double dif_perc = dif_pereplat(tel_cred, proc_cred, month_cred);
        double dif_tot = dif_total(tel_cred, proc_cred, month_cred);
        QString a, b;
        a.setNum(dif_first, 'f', 2);
        b.setNum(dif_last, 'f', 2);
        a.append("...");
        a.append(b);
        ui->month_pay->setText(a);
        ui->credit_pay->setText(a.setNum(dif_perc, 'f', 2));
        ui->total_pay->setText(a.setNum(dif_tot, 'f', 2));
      }
  }
}

void MainWindow::on_time_credit_textChanged(const QString &arg1)
{
    if (ui->year->currentText() == "месяцев") {
        ui->time_credit->setRange(1, 600);
    }
    if (ui->year->currentText() == "лет"){
        ui->time_credit->setRange(1, 50);
    }
}
