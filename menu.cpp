#include "menu.h"
#include "ui_menu.h"
#include "mainwindow.h"
#include "licencia.h"
#include "instrucciones.h"
#include "mundo2.h"

menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    connect(ui->jugar,SIGNAL(clicked()),this,SLOT(jugar()));
    connect(ui->instrucciones,SIGNAL(clicked()),this,SLOT(instruccion()));
    connect(ui->licencia,SIGNAL(clicked()),this,SLOT(creditos()));


}


menu::~menu()
{
    delete ui;
}

void menu::jugar()
{
    MainWindow *mapa=new MainWindow();
    mapa->show();
    close();
    
}

void menu::instruccion()
{
    instrucciones *instruc=new instrucciones();
    instruc->show();
    close();
    
}


void menu::creditos()
{
    licencia *lic= new licencia();
    lic->show();
    close();
    
}


void menu::on_nivel2_clicked()
{
    mundo2 *nivel2=new mundo2();
    nivel2->show();
    close();
}

void menu::on_jugar_clicked()
{

}
