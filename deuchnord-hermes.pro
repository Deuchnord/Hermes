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
ICON = hermes.icns


SOURCES += main.cpp\
        mainwindow.cpp \
    produititem.cpp \
    infosproduitdialog.cpp \
    aboutdialog.cpp \
    scannerdialog.cpp \
    settingsdialog.cpp \
    manufacturersmanager.cpp

HEADERS  += mainwindow.h \
    produititem.h \
    infosproduitdialog.h \
    aboutdialog.h \
    scannerdialog.h \
    settingsdialog.h \
    manufacturersmanager.h

FORMS    += mainwindow.ui \
    produititem.ui \
    infosproduitdialog.ui \
    aboutdialog.ui \
    scannerdialog.ui \
    settingsdialog.ui

TRANSLATIONS =  strings.ts

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    resources.rc

RC_FILE = resources.rc
