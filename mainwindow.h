#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qdynamicbutton.h>
#include <QTime>


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
void createBomb(int N, int M, int bomb);
void slotGetButton();
void slotRclick();

private:

    QDynamicButton qdynamicbutton;
    QDynamicButton **button;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
