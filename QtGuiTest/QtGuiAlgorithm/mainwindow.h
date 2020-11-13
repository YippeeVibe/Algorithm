#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//Ã»ÓÐÊ²Ã´
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
private slots:
 void SlotConvexHullAction();
 void SlotSortAction();
 void SlotHanioAction();
private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
