#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->toolBar->addAction(QString::fromLocal8Bit("͹��"),this,SLOT(SlotConvexHullAction()));
  ui->toolBar->addAction(QString::fromLocal8Bit("����"),this,SLOT(SlotSortAction()));
  ui->toolBar->addAction(QString::fromLocal8Bit("��ŵ��"),this,SLOT(SlotHanioAction()));
  this->setWindowTitle(QString::fromLocal8Bit("h"));
}

MainWindow::~MainWindow()
{
  delete ui;
}
void MainWindow::SlotConvexHullAction() {
  ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::SlotSortAction() {
  ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::SlotHanioAction() {
  ui->stackedWidget->setCurrentIndex(2);
}



