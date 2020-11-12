#ifndef CELL_H
#define CELL_H

#include <QGraphicsItem>
#include <QPainter>


class cell : public QGraphicsItem
{
public:
    cell();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    int width {100};
    int height {100};
};

#endif // CELL_H
