#ifndef GAME_H
#define GAME_H

//#include "mainwindow.h"
#include <QObject>
#include "map.h"
#include "cell.h"
#include <QTime>
#include <QMessageBox>

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
    void  gameLose();
    void restart();

    int pressLeftCnt;
    int n_s;
    int m_s;
signals:
    void signalCreate(QWidget *qwidget, int x, int y);
    void signalLabel(int n);
private:
    Map map;
    Cell **button;
};

#endif // GAME_H
