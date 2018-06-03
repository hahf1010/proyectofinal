#ifndef DESPLAZAMIENTO_H
#define DESPLAZAMIENTO_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class desplazamiento: public QGraphicsItem    //hereda de QGraphicsItem
{

public:
    desplazamiento();
    ~desplazamiento();
    void lineas();                  //Cambia la posicion
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto
    void setposicion(int x, int y);
protected:
    int px;
    int py;
    int vx;
    int vy;
};

#endif // DESPLAZAMIENTO_H
