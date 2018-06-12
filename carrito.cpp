#include "carrito.h"

 carrito::carrito(){
     setPixmap(QPixmap(":/imagenes/cRojo.png"));

     px=-50;              //Posicion en x
     py=125;              //Posicion en y
     vx=0;                //Velocidad en x
     vy=0;                //Velocidad en y
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
