#include "carrito2.h"

carrito2::carrito2(){
     setPixmap(QPixmap(":/imagenes/racing.png"));

     px=40;                 //Posicion en x
     py=125;                //Posicion en y
     vx=0;                  //Velocidad en x
     vy=0;                  //Velocidad en y
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
