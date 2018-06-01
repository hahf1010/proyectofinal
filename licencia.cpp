#include "licencia.h"
#include "ui_licencia.h"
#include "menu.h"

licencia::licencia(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::licencia)
{
    ui->setupUi(this);
    connect(ui->regresar,SIGNAL(clicked()),this,SLOT(regresar()));

}

licencia::~licencia()
{
    delete ui;
}

void licencia::regresar()
{
    close();
    menu *activo=new menu();
    activo->show();

}
