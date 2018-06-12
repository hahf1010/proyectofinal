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
    int px;          //Posicion en x
    int py;          //Posicion en y
    int vx;          //Velocidad en x
    int vy;          //Velocidad en y



};

#endif // CARRITO2_H
