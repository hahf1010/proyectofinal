#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include "carrito.h"
#include "enemigos.h"
#include "desplazamiento.h"
#include <QGraphicsItem>
#include "superman.h"
//#include <QtMultimedia/QMediaPlayer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool choque;
    int vida;
    void ManejoVida();
    void llegada();

    void advance();
protected:
    void keyPressEvent(QKeyEvent *e);

private slots:
    void actualizar();
    void on_iniciar_clicked();
    void tiempo();   
    void atras();
    void vidas();
    void mvto();


private:
    Ui::MainWindow *ui;
    QTimer *timer, *Vidas;
    QGraphicsScene *scene;
    carrito *c1;
    QList<enemigos*> c2;
    QList<desplazamiento*>d1;
    int cont4,cont3,cont2,cont1,cont,cent,seg,min;
    int puntos,mayorpuntaje;
    qreal px,py;
    char flag;
    superman *super;
    //QMediaPlayer *music;

};

#endif // MAINWINDOW_H
