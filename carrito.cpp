#include "carrito.h"

 carrito::carrito(){
     setPixmap(QPixmap(":/imagenes/cRojo.png"));

     px=-10;
     py=vx=vy=0;
 }

 void carrito::mover(int mx, int my)
 {
     px+=mx;
     py=my;
     if(px>-100 && px<80)//validacion Extremos carretera
     {

          setPos(px,125);
     }
}

 carrito::~carrito(){
 }

 int carrito::getX()
 {
     return px;
 }

 int carrito::getY()
 {
     return py;
 }
