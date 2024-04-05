#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  creditcalc = new credit_calc();
  vklad = new vklad_calc();
  connect(ui->Btn_zero, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->Btn_seven, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->Btn_toc, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_1, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_2, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_3, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_4, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_5, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_6, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_8, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_9, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button__mul, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_acos, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_asin, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_x, SIGNAL(clicked()), this, SLOT(GetXValue()));
  connect(ui->button_x, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_tan, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_sqrt, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_sin, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_scob2, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_scob1, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_pow, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_plus, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_atan, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_ln, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_log, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_div, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_mood, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_cos, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->button_minus, SIGNAL(clicked()), this, SLOT(Obrabotchik()));
  connect(ui->Btn_eq, SIGNAL(clicked()), this, SLOT(Endoffunc()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::Obrabotchik() {
  QPushButton *current_button = (QPushButton *)sender();
  ui->Expressions->setText(ui->Expressions->text() + current_button->text());
  QString Current_text = current_button->text();
  if (Current_text == "sin") {
    ui->Expressions->setText(ui->Expressions->text() + "(");
  }
  if (Current_text == "cos") {
    ui->Expressions->setText(ui->Expressions->text() + "(");
  }
  if (Current_text == "asin") {
    ui->Expressions->setText(ui->Expressions->text() + "(");
  }
  if (Current_text == "acos") {
    ui->Expressions->setText(ui->Expressions->text() + "(");
  }
  if (Current_text == "ln") {
    ui->Expressions->setText(ui->Expressions->text() + "(");
  }
  if (Current_text == "log") {
    ui->Expressions->setText(ui->Expressions->text() + "(");
  }
  if (Current_text == "tan") {
    ui->Expressions->setText(ui->Expressions->text() + "(");
  }
  if (Current_text == "atan") {
    ui->Expressions->setText(ui->Expressions->text() + "(");
  }
  if (Current_text == "sqrt") {
    ui->Expressions->setText(ui->Expressions->text() + "(");
  }
}

void MainWindow::Endoffunc() {
  QString str = ui->Expressions->text();
  s21::Controller controllers;
  double result = 0;
  //  QByteArray str1 = str.toLocal8Bit();
  //  char *str2 = str1.data();
  try {
    controllers.calculator_controller(str.toStdString(), &result, x);
    ui->Expressions->setText(QString::number(result));
    x = INFINITY;
    show_graph(QString(str), -5, 5);
  } catch (const std::invalid_argument &error) {
    // создать окошка окошко
    QMessageBox msgBox;
    msgBox.setText(QString("Logical errors"));
    msgBox.setStandardButtons(QMessageBox::Cancel);
    msgBox.exec();
  }
}

void MainWindow::show_graph(QString prefix_str, int minX,
                            int maxX) {  // поменял тут было char *
  double a = ui->MinX->value();
  double b = ui->MaxX->value();
  s21::Controller controllers;
  if (a < b) {
    double h = 0.01;
    int N = (b - a) / h + 2;
    QVector<double> x(N), y(N);
    double result = 0;
    int i = 0;
    for (double X = a; X <= b; X += h) {
      if (X < 0.01 && X > 0) {
        X = 0;
      }
      try {
        controllers.calculator_controller(prefix_str.toStdString(), &result, X);
        x[i] = X;
        y[i] = result;
      } catch (const std::invalid_argument &error) {
        // создать окошка окошко
        QMessageBox msgBox;
        msgBox.setText("Logical errors.");
        msgBox.exec();
      }
      i++;
    }
    x[i] = b;
    controllers.calculator_controller(prefix_str.toStdString(), &result, b);
    y[i] = result;
    // y[i] = calculator(prefix_str, &result, b);
    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");

    double minY = y[0], maxY = y[0];
    for (int i = 1; i < N; i++) {
      if (y[i] < minY) minY = y[i];
      if (y[i] > maxY) maxY = y[i];
    }
    ui->widget->yAxis->setRange(minY, maxY);  // Для оси Oy
    ui->widget->xAxis->setRange(a, b);
    ui->widget->replot();
  }
}

void MainWindow::GetXValue() {
  bool ok = false;
  if (x == INFINITY) {
    x = QInputDialog::getDouble(this, " ", "Введите значение X", 0, -214783647,
                                214783647, 10, &ok, Qt::WindowFlags(), 1);
  }
}

void MainWindow::on_button_obnyl_clicked() { ui->Expressions->clear(); }

void MainWindow::on_button_credit_clicked() {
  this->close();
  creditcalc->show();
}

void MainWindow::on_pushButton_clicked() {
  this->close();
  vklad->show();
}
