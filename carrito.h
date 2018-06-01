#ifndef CARRITO_H
#define CARRITO_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QDebug>

class carrito: public QGraphicsPixmapItem   //hereda de QGraphicsItem
{

public:
    carrito();
    ~carrito();
    void mover(int mx, int my);
    int getX();
    int getY();

protected:
    int px;
    int py;
    int vx;
    int vy;
};

#endif // CARRITO_H
