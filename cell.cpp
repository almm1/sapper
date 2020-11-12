#include "cell.h"

cell::cell()
{

}
QRectF cell::boundingRect() const
{
    return QRectF(0, 0, width, height);
}
void cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(0, 0, width, height);
}
