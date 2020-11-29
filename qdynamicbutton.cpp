#include "qdynamicbutton.h"

QDynamicButton::QDynamicButton(QWidget *parent) :
    QPushButton(parent)
{
    setN(16);
    setM(30);
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
