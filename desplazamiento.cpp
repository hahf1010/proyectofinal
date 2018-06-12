#include "desplazamiento.h"

desplazamiento::desplazamiento(){
    px=10;                          //Posicion de las lineas en x
    py=-100;                        //Posicion de las lineas en y

}

desplazamiento::~desplazamiento(){

}

void desplazamiento::lineas(){

    px=0;
    py+=5;
    setPos(px,py);
}

QRectF desplazamiento::boundingRect() const
{
    return QRect(-6,-6,7,55);           //Argumentos son:(posicion inicial x, posicion inicial y, ancho, alto)
}

void desplazamiento::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);        //Asigna el color a las líneas de la carretera
    painter->drawRect(boundingRect());
}

void desplazamiento::setposicion(int x,int y){

    px=x;
    py=y;
}
