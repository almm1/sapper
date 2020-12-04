#include "qdynamicbutton.h"

QDynamicButton::QDynamicButton(QWidget *parent) :
    QMyPushButton(parent)
{

    this->setFixedSize(25,25);//фиксированый размер кнопки
}

QDynamicButton::~QDynamicButton()
{

}



void QDynamicButton::setX(int x){posX = x;}

int QDynamicButton::getX(){return posX;}

void QDynamicButton::setY(int y){posY = y;}

int QDynamicButton::getY(){return posY;}


