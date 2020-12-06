#ifndef CELL_H
#define CELL_H

#include <qmypushbutton.h>

class Cell : public QMyPushButton
{
    Q_OBJECT
public:
    explicit Cell(QWidget *parent = 0);
    ~Cell();


    void setX(int x);
    int getX();

    void setY(int y);
    int getY();

    int status;
    int bombAround;
    bool isFlag;
    bool isOpen;

private:

    int posX = 0;
    int posY = 0;
};

#endif // CELL_H
