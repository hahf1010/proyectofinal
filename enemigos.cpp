#include "enemigos.h"

enemigos::enemigos(){
    vy=1;
    px=qrand()%150-100;
    py=-280;
    r=qrand()%3;

    switch(r){
    case 0: setPixmap(QPixmap(":/imagenes/cAzul.png"));
        break;
    case 1: setPixmap(QPixmap(":/imagenes/cMorado.png"));
        break;
    case 2: setPixmap(QPixmap(":/imagenes/camion.png"));
        break;
    default: break;
    }
}
enemigos::~enemigos(){

}

void enemigos::aleatorio(){
    px+=vx;
    py+=vy;

    setPos(px,py);
}

