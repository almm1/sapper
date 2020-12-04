#ifndef QDYNAMICBUTTON_H
#define QDYNAMICBUTTON_H

#include <QPushButton>
#include <qmypushbutton.h>

class QDynamicButton : public QMyPushButton
{
    Q_OBJECT
public:
    explicit QDynamicButton(QWidget *parent = 0);
    ~QDynamicButton();


    void setX(int x);
    int getX();

    void setY(int y);
    int getY();



    enum {BOMB, FLAG, MARK, NUMB, HOLE};
    int status;
    int bombAround;
private:

    int posX = 0;
    int posY = 0;
};

#endif // QDYNAMICBUTTON_H
