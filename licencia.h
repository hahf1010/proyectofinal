#ifndef LICENCIA_H
#define LICENCIA_H

#include <QMainWindow>

namespace Ui {
class licencia;
}

class licencia : public QMainWindow
{
    Q_OBJECT

public:
    explicit licencia(QWidget *parent = 0);
    ~licencia();

private slots:
   void regresar();

private:
    Ui::licencia *ui;
};

#endif // LICENCIA_H
