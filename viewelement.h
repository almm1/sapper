#ifndef VIEWELEMENT_H
#define VIEWELEMENT_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "cell.h"


class viewElement : public QGraphicsView
{
public:
    viewElement();
private:
    cell myCell;
    QGraphicsScene scene;
    void initElements();
};

#endif // VIEWELEMENT_H
