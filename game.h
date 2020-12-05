#ifndef GAME_H
#define GAME_H

//#include "mainwindow.h"
#include <QObject>
#include "map.h"
#include "cell.h"
#include <QTime>

class Game: public QObject
{
    Q_OBJECT
public:
     Game();
    void CreateButton();
    void createBomb(int bomb, int x, int y);
    void slotGetButton();
    void slotRclick();
    void clearZone(int x, int y);
    int searchBomb(int x, int y);
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
