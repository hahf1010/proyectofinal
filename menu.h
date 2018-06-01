#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

namespace Ui {
class menu;
}

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = 0);
    ~menu();

private slots:
    void jugar();
    void instruccion();
    void creditos();
    void on_nivel2_clicked();

    void on_jugar_clicked();

private:
    Ui::menu *ui;
};

#endif // MENU_H
