#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "cell.h"
#include <QTime>
#include <QMessageBox>

class Game: public QObject
{
    Q_OBJECT
public:
     Game();
     ~Game();
    void CreateButton();
    void createBomb(int bomb, int x, int y);
    void slotGetButton();
    void slotRclick();
    void clearZone(int x, int y);
    int searchBomb(int x, int y);
    void setImageNumber(int x, int y, int num);
    void gameLose(int x, int y);
    void restart();
    int checkWin();
    void gameWin();

    void setBomb(int Bomb);
    int getBomb();

    void setN(int number);
    int getN();

    void setM(int number);
    int getM();

    enum {BOMB, NUMB, HOLE};

signals:
    void signalCreate(QWidget *qwidget, int x, int y);
    void signalLabel(int n);
    void exit();

private:
    Cell **button;

    int pressLeftCnt=0;
    int bombLeft;
    int N;
    int M;
    int bomb;
};

#endif // GAME_H
