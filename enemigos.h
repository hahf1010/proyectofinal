#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "carrito.h"

class enemigos: public carrito
{
    int r;
public:
    enemigos();
    ~enemigos();
    void aleatorio();                   //Cambia la posicion


};
#endif // ENEMIGOS_H
