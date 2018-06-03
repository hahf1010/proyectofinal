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
    carrito.cpp \
    enemigos.cpp \
    menu.cpp \
    instrucciones.cpp \
    licencia.cpp \
    desplazamiento.cpp \
    superman.cpp \
    mundo2.cpp \
    mundo1.cpp

HEADERS  += \
    carrito.h \
    enemigos.h \
    menu.h \
    instrucciones.h \
    licencia.h \
    desplazamiento.h \
    superman.h \
    mundo2.h \
    mundo1.h

FORMS    += \
    menu.ui \
    instrucciones.ui \
    licencia.ui \
    mundo2.ui \
    mundo1.ui

RESOURCES += \
    imag.qrc

OTHER_FILES +=
