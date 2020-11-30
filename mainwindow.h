#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qdynamicbutton.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

void CreateButton(int N, int M);
void slotGetButton();
void slotRclick();

private:
    QDynamicButton qdynamicbutton;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
