#ifndef MUNDO2_H
#define MUNDO2_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include "carrito.h"
#include "enemigos.h"
#include "desplazamiento.h"
#include <QGraphicsItem>
#include "superman.h"

namespace Ui {
class mundo2;
}

class mundo2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit mundo2(QWidget *parent = 0);
    ~mundo2();
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
    Ui::mundo2 *ui;
    QTimer *timer, *Vidas;
    QGraphicsScene *scene;
    carrito *carro;
    QList<enemigos*>E2;
    QList<desplazamiento*>d2;
    int cont4,cont3,cont2,cont1,cont,cent,seg,min;
    qreal px,py;
    char flag;
    superman *super;
    //int izqu,derec;
};


#endif // MUNDO2_H
