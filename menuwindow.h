#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();

    void ret();

private slots:
    void on_pushButton_clicked();
    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_3_clicked();

private:
    MainWindow *mw;
    Ui::MenuWindow *ui;
};

#endif // MENUWINDOW_H
