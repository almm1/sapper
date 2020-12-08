#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qmypushbutton.h>
#include "game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(int n=0, int m=0, int b=0, QWidget *parent = 0);
    ~MainWindow();

    void setButton(QWidget *qwidget,int x, int y);
    void setLabel(int n);
    void close();

signals:
    void showMenu();
private slots:
    void on_pushButton_clicked();

private:
      Game game;
      Ui::MainWindow *ui;
};

#endif  //MAINWINDOW_H
