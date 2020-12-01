#include "qdynamicbutton.h"

QDynamicButton::QDynamicButton(QWidget *parent) :
    QMyPushButton(parent)
{
    setN(9);
    setM(9);
    setBomb(10);
    this->setFixedSize(25,25);//фиксированый размер кнопки
}

QDynamicButton::~QDynamicButton()
{

}

void QDynamicButton::setN(int number){N = number;}

int QDynamicButton::getN(){return N;}

void QDynamicButton::setM(int number){M = number;}

int QDynamicButton::getM(){return M;}

void QDynamicButton::setX(int x){posX = x;}

int QDynamicButton::getX(){return posX;}

void QDynamicButton::setY(int y){posY = y;}

int QDynamicButton::getY(){return posY;}

void QDynamicButton::setBomb(int Bomb){bomb = Bomb;}

int QDynamicButton::getBomb(){return bomb;}
