#include "carrito2.h"

carrito2::carrito2(){
     setPixmap(QPixmap(":/imagenes/racing.png"));

     px=40;
     py=125;
     vx=0;
     vy=0;
 }

 void carrito2::mover(int mx, int my)
 {
     px+=mx;
     py+=my;
     if(px>-100 && px<80)                //Validacion Extremos carretera, o hasta donde se mueve el carro horizontalmente


     {

          setPos(px,py);



     }
}

 carrito2::~carrito2(){
 }

 int carrito2::getX()
 {
     return px;
 }

 int carrito2::getY()
 {
     return py;
 }
