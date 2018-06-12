#ifndef CARRITO_H
#define CARRITO_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QDebug>

class carrito: public QGraphicsPixmapItem
{

public:
    carrito();
    ~carrito();
    void mover(int mx, int my);
    int getX();
    int getY();

protected:
    int px;                  //Posicion en x
    int py;                  //Posicion en y
    int vx;                  //Velocidad en x
    int vy;                  //Velocidad en y
};

#endif // CARRITO_H
