#include "cell.h"

Cell::Cell(QWidget *parent) :
    QMyPushButton(parent)
{
    this->setFixedSize(30,30);//фиксированый размер кнопки
    isOpen=false;
    bombAround=0;
    isFlag=false;
}

Cell::~Cell(){}

void Cell::setX(int x){posX = x;}

int Cell::getX(){return posX;}

void Cell::setY(int y){posY = y;}

int Cell::getY(){return posY;}
