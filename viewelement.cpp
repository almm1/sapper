#include "viewelement.h"

viewElement::viewElement()
{
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //отключение скролинга
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setWindowTitle("Sapper");//заголовок окна

    setScene(&scene);
    initElements();
}
void viewElement::initElements()
{
    //myCell.setPos(60, 60);
    scene.addItem(&myCell);
}
