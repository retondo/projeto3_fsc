TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    listas.c \
    calcularCaminho.c

HEADERS += \
    dadosLista.h \
    listas.h \
    calcularCaminho.h
