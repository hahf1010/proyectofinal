#include "mundo1.h"
#include "ui_mapa.h"
#include <QDebug>
#include <QString>
#include "menu.h"
#include <QKeyEvent>
#include<QGraphicsItem>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsObject>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer= new QTimer(this);
    scene= new QGraphicsScene(this);

    // crear lineas limitadas para que el no pasen por el carro

    for(int i=0;i<15;i++){                        //Mover las lineas y desaparecer la inicial
        d1.append(new desplazamiento);
          d1.last()->setposicion(0,-280+150*i);   //Frecuencia con las que salen las líneas
        scene->addItem(d1.at(i));
   }

    cont=cont1=cont2=cent=seg=min=0;
    vida=6;
    //puntos =0;
    vidas();
    ui->escena->setScene(scene);
    scene->setSceneRect(-140, -140, 280, 280);     //Posicion donde inician el carro y las lineas

    c1= new carrito;
    c1->setPos(-50,125);
    c1->setFlag(QGraphicsItem::ItemIsFocusable);
    c1->setFocus();
    scene->addItem(c1);


    c3= new carrito2;
    c3->setPos(40,125);
    c3->setFlag(QGraphicsItem::ItemIsFocusable);
    c3->setFocus();
    scene->addItem(c3);

    timer->stop();
    connect(timer,SIGNAL(timeout()),this,SLOT(mvto()));
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    connect(timer,SIGNAL(timeout()),this,SLOT(tiempo()));
    connect(ui->iniciar,SIGNAL(clicked()),this,SLOT(tiempo()));
    connect(ui->atras,SIGNAL(clicked()),this,SLOT(atras()));


    flag=0;



}

void MainWindow::mvto(){                //Funcion para las lineas de la carretera
if(cont1==0){
    for(int i=0;i<15;i++){
        d1.at(i)->lineas();
        if(d1.at(i)->y()>280){
            d1.at(i)->setposicion(0,-280);
        }

    }
}
else
    cont1--;

}
void MainWindow::advance()         //Funcion para el superman
{
    if(px==-178 && py==200){
        super->advance(-3);
        super->setPos(px,py);
    }
}

void MainWindow::actualizar(){     //Funcion para los enemigos
    if(cont1==0){
        cont++;
        if(cont==150){              //Frecuencia con la que aparecen los enemigos
        c2.append(new enemigos);    //Agregar enemigos
        scene->addItem(c2.last());
        cont=0;




    }
    for(int i=0;i<c2.size();i++){
        c2.at(i)->aleatorio();

    if(c2.size()>0){
    if(c2.first()->y()>200){
       scene->removeItem(c2.first());
       c2.removeAt(0);
    }
    }


    //Colision Carro Principal
    if(c1->collidesWithItem(c2.at(i))){                   // Condicion para la colision
       choque=true;
}   
}

    if (choque==true && flag==0){
        c1->setPixmap(QPixmap(":/imagenes/explo.png"));    //Cambio de imagen en la colision
        timer->start();
        vida--;
        vidas();
        flag++;
        ManejoVida();
        cont1=200;
    }
        else if(choque==false && flag>0){
        c1->setPixmap(QPixmap(":/imagenes/cRojo.png"));    //El carro vuelve a su imagen inicial luego de colisionar

        flag--;
    }
    choque =false;





//    for(int j=0;i<c2.size();j++){
//        c2.at(j)->aleatorio();

//    if(c2.size()>0){
//    if(c2.first()->y()>200){
//       scene->removeItem(c2.first());
//       c2.removeAt(0);
//    }
//    }

//    //Colision Carro 2
//    if(c3->collidesWithItem(c2.at(j))){                 // Condicion para la colision del carro 2
//       choque=true;
//}
//}

//    if (choque==true && flag==0){
//        c3->setPixmap(QPixmap(":/imagenes/explo.png"));   //Cambio de imagen en la colision
//        timer->start();
//        vida--;
//        vidas();
//        flag++;
//        ManejoVida();
//        cont1=200;
//    }
//        else if(choque==false && flag>0){
//        c1->setPixmap(QPixmap(":/imagenes/racing.png"));

//        flag--;
//    }
//    choque =false;


}
llegada();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_iniciar_clicked()
{
    timer->start(10);                        //Tiempo que tarda en iniciar luego de darle click

}



void MainWindow::tiempo()                    //Funcion para el tiempo, centesimas, segundos, minutos
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

void MainWindow::atras()                  //Funcion boton "atras"
{
    timer->stop();
    close();
    menu *j=new menu();
    j->show();
}

void MainWindow::vidas()
{

    ui->vidas->display(vida);


}
void MainWindow::keyPressEvent(QKeyEvent *e)    //Teclas con las que cambiaremos de posicion al carro principal
{
    if(e->key() == Qt::Key_D){
        c1->mover(20,py);
  }
    if(e->key() == Qt::Key_A){
        c1->mover(-20,py);
  }
    if(e->key() == Qt::Key_W){
        c1->mover(px,-20);
  }
    if(e->key() == Qt::Key_S){
        c1->mover(px,20);
  }
    if(e->key() == Qt::Key_Q){
        c1->mover(px-5,py-5);
  }
    if(e->key() == Qt::Key_E){
        c1->mover(px+5,py-5);
  }
    if(e->key() == Qt::Key_Z){
        c1->mover(px-5,py+5);
  }
    if(e->key() == Qt::Key_C){
        c1->mover(px+5,py+5);
  }
    if(e->key() == Qt::Key_L){        //Teclas con las que cambiaremos de posicion al carro principal
        c3->mover(20,py);
  }
    if(e->key() == Qt::Key_J){
        c3->mover(-20,py);
  }
    if(e->key() == Qt::Key_I){
        c3->mover(px,-20);
  }
    if(e->key() == Qt::Key_K){
        c3->mover(px,20);
  }


}

void MainWindow::ManejoVida(){
    if (vida==0){
        timer->stop();
       // music->stop();
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

void MainWindow::llegada()
{
    cont2++;
    if (cont2==2500){                 //Tiempo en el que aparece superman

        super= new superman;
        scene->addItem(super);
        super->setPos(-178,220);      //Posicion en la que aparece superman
        if(super->y()>280){
        scene->removeItem(super);

    }
    }

    else if (cont2==5900){            //Tiempo que dura la parida para ganar
        qDebug()<<"meta";
        QMessageBox msgBox;
        msgBox.setText("GANASTE!!!");
        msgBox.exec();
        ui->meta->setPixmap(QPixmap(":/imagenes/meta.jpg"));
        timer->stop();
    }

}




