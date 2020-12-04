#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qdynamicbutton.h>
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

void CreateButton(int N, int M);
void createBomb(int N, int M, int bomb, int x, int y);
void slotGetButton();
void slotRclick();
void clearZone(int x, int y, int N, int M);
int searchBomb(int x, int y, int N, int M);
void setImageNumber(int x, int y, int num);


int pressLeftCnt;

private:
    Map map;
    QDynamicButton *bu;
    QDynamicButton qdynamicbutton;
    QDynamicButton **button;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
