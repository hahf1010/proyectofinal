#include "carrito.h"

 carrito::carrito(){
     setPixmap(QPixmap(":/imagenes/cRojo.png"));

     px=-10;
     py=125;
     vx=0;
     vy=0;
 }

 void carrito::mover(int mx, int my)
 {
     px+=mx;
     py+=my;
     if(px>-100 && px<80)                //Validacion Extremos carretera, o hasta donde se mueve el carro horizontalmente


     {

          setPos(px,py);



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
