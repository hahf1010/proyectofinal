#-------------------------------------------------
#
# Project created by QtCreator 2018-05-22T15:06:08
#
#-------------------------------------------------

QT       += core gui



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Crazy_Road
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    carrito.cpp \
    enemigos.cpp \
    menu.cpp \
    instrucciones.cpp \
    licencia.cpp \
    desplazamiento.cpp \
    superman.cpp \
    mundo2.cpp

HEADERS  += mainwindow.h \
    carrito.h \
    enemigos.h \
    menu.h \
    instrucciones.h \
    licencia.h \
    desplazamiento.h \
    superman.h \
    mundo2.h

FORMS    += \
    mapa.ui \
    menu.ui \
    instrucciones.ui \
    licencia.ui \
    mundo2.ui

RESOURCES += \
    imag.qrc

OTHER_FILES +=
