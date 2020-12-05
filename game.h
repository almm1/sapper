#ifndef GAME_H
#define GAME_H

#include "mainwindow.h"

class Game: public QObject
{
    Q_OBJECT
public:
     Game();
    void CreateButton(int N, int M);
    void createBomb(int N, int M, int bomb, int x, int y);
    void slotGetButton();
    void slotRclick();
    void clearZone(int x, int y, int N, int M);
    int searchBomb(int x, int y, int N, int M);
    void setImageNumber(int x, int y, int num);

    int pressLeftCnt;
    int n_s;
    int m_s;
signals:
    void signal(QWidget *qwidget, int x, int y);
private:
    Map map;
   // Cell cell;
    Cell **button;
};

#endif // GAME_H
