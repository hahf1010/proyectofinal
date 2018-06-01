#include "desplazamiento.h"

desplazamiento::desplazamiento(){
    px=10;
    py=-100;

}

desplazamiento::~desplazamiento(){

}

void desplazamiento::lineas(){

    px=0;
    py+=1;
    setPos(px,py);
}

QRectF desplazamiento::boundingRect() const
{
    return QRect(-6,-6,7,55);    //argumentos son:(posicion inicial x, posicion inicial y, ancho, alto)
}

void desplazamiento::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);        //asigna el color
    painter->drawRect(boundingRect());
}

void desplazamiento::setposicion(int x,int y){

    px=x;
    py=y;
}
