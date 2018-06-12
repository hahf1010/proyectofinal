#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "carrito.h"

class enemigos: public carrito
{
    int r;                             //Variable tipo entero para se asignara el qrand en el .cpp
public:
    enemigos();
    ~enemigos();
    void aleatorio();                   //Cambia la posicion donde apareceran aleatoriamente


};
#endif // ENEMIGOS_H
