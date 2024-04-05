#ifndef CREDIT_CALC_H
#define CREDIT_CALC_H

#include <QInputDialog>
#include <QWidget>

#include "../Controller/s21_Controller.h"
#include "QPushButton"

namespace Ui {
class credit_calc;
}

class credit_calc : public QWidget {
  Q_OBJECT

 public:
  explicit credit_calc(QWidget *parent = nullptr);
  ~credit_calc();

 private:
  Ui::credit_calc *ui;

 private slots:
  void calculate();
  void on_pushButton_2_clicked();
};

#endif  // CREDIT_CALC_H
