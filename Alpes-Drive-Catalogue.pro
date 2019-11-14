#-------------------------------------------------
#
# Project created by QtCreator 2019-11-07T15:40:57
#
#-------------------------------------------------

QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Alpes-Drive-Catalogue
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    variete.cpp \
    produit.cpp \
    categorie.cpp \
    vente.cpp \
    passerelle.cpp \
    pdf.cpp \
    unite.cpp \
    producteur.cpp \
    client.cpp

HEADERS  += mainwindow.h \
    variete.h \
    produit.h \
    categorie.h \
    vente.h \
    passerelle.h \
    pdf.h \
    unite.h \
    producteur.h \
    client.h

FORMS    += mainwindow.ui
