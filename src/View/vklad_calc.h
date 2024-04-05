#ifndef VKLAD_CALC_H
#define VKLAD_CALC_H

#include <QInputDialog>
#include <QWidget>

#include "../Controller/s21_Controller.h"
#include "QPushButton"

namespace Ui {
class vklad_calc;
}

class vklad_calc : public QDialog {
  Q_OBJECT

 public:
  explicit vklad_calc(QWidget *parent = nullptr);
  ~vklad_calc();

 private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

 private:
  Ui::vklad_calc *ui;
};

#endif  // VKLAD_CALC_H
