#include "mundo2.h"
#include "ui_mundo2.h"
#include <QDebug>
#include <QString>
#include "menu.h"
#include <QKeyEvent>
#include<QGraphicsItem>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsObject>
#include <QMessageBox>

mundo2::mundo2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mundo2)
{
    ui->setupUi(this);
    timer= new QTimer(this);
    scene= new QGraphicsScene(this);


    // crear lineas limitadas para que el no pasen por el carro

    for(int i=0;i<15;i++){                        //Mover las lineas y desaparecer la inicial
        d2.append(new desplazamiento);
          d2.last()->setposicion(0,-280+150*i);   //Frecuencia con las que salen las líneas
        scene->addItem(d2.at(i));
   }

    cont=cont1=cont2=cent=seg=min=0;
    vida=3;
    vidas();
    ui->mundo->setScene(scene);
    scene->setSceneRect(-140, -140, 280, 280);   //Posicion donde inician el carro y las lineas

    carro = new carrito;
    carro->setPos(-10,125);
    carro->setFlag(QGraphicsItem::ItemIsFocusable);
    carro->setFocus();
    scene->addItem(carro);

    timer->stop();
    connect(timer,SIGNAL(timeout()),this,SLOT(mvto()));
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    connect(timer,SIGNAL(timeout()),this,SLOT(tiempo()));
    connect(ui->iniciar,SIGNAL(clicked()),this,SLOT(tiempo()));
    connect(ui->atras,SIGNAL(clicked()),this,SLOT(atras()));

    flag=0;

}

mundo2::~mundo2()
{
    delete ui;
}


void mundo2::mvto(){                       //Funcion para las lineas de la carretera
if(cont1==0){
    for(int i=0;i<15;i++){
        d2.at(i)->lineas();
        if(d2.at(i)->y()>280){
            d2.at(i)->setposicion(0,-280);
        }

    }
}
else
    cont1--;

}
void mundo2::advance()                     //Funcion para el superman
{
    if(px==-178 && py==200){
        super->advance(-3);
        super->setPos(px,py);
    }
}

void mundo2::actualizar(){                //Funcion para los enemigos
    if(cont1==0){
        cont++;
        if(cont==80){                  //Frecuencia con la que aparecen los enemigos
        E2.append(new enemigos);       //Agregar enemigos
        scene->addItem(E2.last());
        cont=0;
    }
    for(int i=0;i<E2.size();i++){
        E2.at(i)->aleatorio();

    if(E2.size()>0){
    if(E2.first()->y()>200){
       scene->removeItem(E2.first());
       E2.removeAt(0);
    }
    }

    //Colision
    if(carro->collidesWithItem(E2.at(i))){          // Condicion para la colision
       choque=true;
}
}

    if (choque==true && flag==0){
        carro->setPixmap(QPixmap(":/imagenes/explo.png"));   //Cambio de imagen en la colision
        timer->start();
        vida--;
        vidas();
        flag++;
        ManejoVida();
        cont1=200;
    }
        else if(choque==false && flag>0){
        carro->setPixmap(QPixmap(":/imagenes/cRojo.png"));

        flag--;
    }
    choque =false;

}
llegada();
}

void mundo2::on_iniciar_clicked()
{
    timer->start(10);
}

void mundo2::tiempo()             //Funcion para el tiempo, centesimas, segundos, minutos
{
     QString t;
     cent++;
     if (cent==99){
         seg++;
         cent=0;
             if(seg==59){
                 min++;
                 seg=0;
             }
            }
        t=QString("%1:%2").arg(min).arg(seg);
        ui->tiempo->display(t);

}

void mundo2::atras()
{
    timer->stop();
    close();
    menu *j=new menu();
    j->show();
}

void mundo2::vidas()
{

    ui->vidas->display(vida);


}
void mundo2::keyPressEvent(QKeyEvent *e)      //Teclas con las que cambiaremos de posicion al carro principal
{
    if(e->key() == Qt::Key_D){
        carro->mover(20,py);
  }
    if(e->key() == Qt::Key_A){
        carro->mover(-20,py);
  }
    if(e->key() == Qt::Key_W){
        carro->mover(px,-20);
  }
    if(e->key() == Qt::Key_S){
        carro->mover(px,20);
  }
    if(e->key() == Qt::Key_Q){
        carro->mover(px-5,py-5);
  }
    if(e->key() == Qt::Key_E){
        carro->mover(px+5,py-5);
  }
    if(e->key() == Qt::Key_Z){
        carro->mover(px-5,py+5);
  }
    if(e->key() == Qt::Key_C){
        carro->mover(px+5,py+5);
  }

}
void mundo2::ManejoVida(){
    if (vida==0){
        timer->stop();
        //music->stop();
        ui->Boom->setPixmap(QPixmap(":/imagenes/Accidente.png"));
        this->setCentralWidget(ui->Boom);
        QMessageBox msgBox;
        msgBox.setText("GAME OVER!!");
        msgBox.exec();
        msgBox.setInformativeText("Desea intentarlo de nuevo?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        int ret = msgBox.exec();
        switch (ret)
        {
           case QMessageBox::Yes:

             show();
             atras();
                 break;

           case QMessageBox::No:
            show();
            close();
                break;
            default:
                break;
         }
    }


}

void mundo2::llegada()
{
    cont2++;
    if (cont2==2500){             //Tiempo en el que aparece superman

        super= new superman;
        scene->addItem(super);
        super->setPos(-178,220);
        if(super->y()>280){
        scene->removeItem(super);

    }
    }

    else if (cont2==5900){         //Tiempo que dura la parida para ganar
        //qDebug()<<"meta";
        QMessageBox msgBox;
        msgBox.setText("GANASTE!!!");
        msgBox.exec();
        ui->meta->setPixmap(QPixmap(":/imagenes/meta.jpg"));
        timer->stop();
    }

}


