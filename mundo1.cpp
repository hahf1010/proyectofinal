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

    for(int i=0;i<15;i++){
        d1.append(new desplazamiento);
          d1.last()->setposicion(0,-280+200*i);
        scene->addItem(d1.at(i));
   }

    cont=cont1=cont2=cent=seg=min=0;
    vida=3;
    vidas();
    ui->escena->setScene(scene);
    scene->setSceneRect(-140, -140, 280, 280);

    c1= new carrito;
    c1->setPos(-10,125);
    c1->setFlag(QGraphicsItem::ItemIsFocusable);
    c1->setFocus();
    scene->addItem(c1);

    timer->stop();
    connect(timer,SIGNAL(timeout()),this,SLOT(mvto()));
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    connect(timer,SIGNAL(timeout()),this,SLOT(tiempo()));
    connect(ui->iniciar,SIGNAL(clicked()),this,SLOT(tiempo()));
    connect(ui->atras,SIGNAL(clicked()),this,SLOT(atras()));

    flag=0;


    //Musica de fondo para este nivel.


    //music= new QMediaPlayer();
    //music->setMedia(QUrl("C:/Users/Harrison/Documents/GitHub/proyectofinal/imagenes/Musica.mp3"));
    //music->play();
}

void MainWindow::mvto(){
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
void MainWindow::advance()
{
    if(px==-178 && py==200){
        super->advance(-3);
        super->setPos(px,py);
    }
}

void MainWindow::actualizar(){
    if(cont1==0){
        cont++;
        if(cont==250){
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


    //Colision
    if(c1->collidesWithItem(c2.at(i))){
       choque=true;
}
}
    if (choque==true && flag==0){
        c1->setPos(-10,125);
        vida--;
        vidas();
        flag++;
        ManejoVida();
        cont1=200;
    }
    else if(choque==false && flag==1){
        flag--;
    }
    choque =false;

}
llegada();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_iniciar_clicked()
{
    timer->start(10);
}

void MainWindow::tiempo()
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

void MainWindow::atras()
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
void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_D){
        c1->mover(5,125);
  }
    if(e->key() == Qt::Key_A){
        c1->mover(-5,215);
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
    if (cont2==4500){

        super= new superman;
        scene->addItem(super);
        super->setPos(-178,220);
        if(super->y()>280){
        scene->removeItem(super);

    }
    }

    else if (cont2==5900){
        qDebug()<<"meta";
        QMessageBox msgBox;
        msgBox.setText("GANASTE!!!");
        msgBox.exec();
        ui->meta->setPixmap(QPixmap(":/imagenes/meta.jpg"));
        timer->stop();
    }

}




