#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cell.h>
#include <qmypushbutton.h>
#include <QTime>
#include "map.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setButton(QWidget *qwidget,int x, int y);
private:
      Ui::MainWindow *ui;
};

#endif  //MAINWINDOW_H
