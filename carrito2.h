#ifndef CARRITO2_H
#define CARRITO2_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QDebug>

class carrito2: public QGraphicsPixmapItem
{
public:
    carrito2();
    ~carrito2();
    void mover(int mx, int my);
    int getX();
    int getY();

protected:
    int px;
    int py;
    int vx;
    int vy;



};

#endif // CARRITO2_H
