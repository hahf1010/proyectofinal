#include "instrucciones.h"
#include "ui_instrucciones.h"
#include "menu.h"

instrucciones::instrucciones(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::instrucciones)
{
    ui->setupUi(this);
    connect(ui->atras,SIGNAL(clicked()),this,SLOT(atras()));

}

instrucciones::~instrucciones()
{
    delete ui;
}



void instrucciones::atras()
{
    close();
    menu *activo=new menu();
    activo->show();
}
