#-------------------------------------------------
#
# Project created by QtCreator 2014-05-07T19:11:58
#
#-------------------------------------------------

CONFIG   += c++11

QT       += core gui
QT       += xml network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = deuchnord-hermes
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    produititem.cpp \
    infosproduitdialog.cpp \
    gestionmagasinsdialog.cpp \
    aboutdialog.cpp

HEADERS  += mainwindow.h \
    produititem.h \
    infosproduitdialog.h \
    gestionmagasinsdialog.h \
    aboutdialog.h

FORMS    += mainwindow.ui \
    produititem.ui \
    infosproduitdialog.ui \
    gestionmagasinsdialog.ui \
    aboutdialog.ui

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    resources.rc

RC_FILE = resources.rc
