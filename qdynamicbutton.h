#ifndef QDYNAMICBUTTON_H
#define QDYNAMICBUTTON_H

#include <QPushButton>


class QDynamicButton : public QPushButton
{
    Q_OBJECT
public:
    explicit QDynamicButton(QWidget *parent = 0);
    ~QDynamicButton();
    void setN(int number);
    int getN();
    void setM(int number);
    int getM();
    void setX(int x);
    int getX();
    void setY(int y);
    int getY();


private:
    int N = 0;
    int M = 0;
    int posX = 0;
    int posY = 0;
};

#endif // QDYNAMICBUTTON_H
