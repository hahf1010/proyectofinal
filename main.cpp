#include "mundo1.h"
#include "menu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menu w;                        //Muestra el menu
    w.show();

    return a.exec();
}
