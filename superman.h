#ifndef SUPERMAN_H
#define SUPERMAN_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "carrito.h"

class superman: public carrito
{

public:
    superman();
    ~superman();
    void advance(int phase);
protected:
    int px;
    int py;
    int vx;
    int vy;

};
#endif // SUPERMAN_H
