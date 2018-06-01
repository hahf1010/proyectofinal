#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H

#include <QMainWindow>

namespace Ui {
class instrucciones;
}

class instrucciones : public QMainWindow
{
    Q_OBJECT

public:
    explicit instrucciones(QWidget *parent = 0);
    ~instrucciones();

private slots:
     void atras();
private:
    Ui::instrucciones *ui;
};

#endif // INSTRUCCIONES_H
