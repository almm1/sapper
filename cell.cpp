#include "cell.h"

Cell::Cell(QWidget *parent) :
    QMyPushButton(parent)
{
    this->setFixedSize(25,25);//фиксированый размер кнопки
}

Cell::~Cell()
{

}

void Cell::setX(int x){posX = x;}

int Cell::getX(){return posX;}

void Cell::setY(int y){posY = y;}

int Cell::getY(){return posY;}
