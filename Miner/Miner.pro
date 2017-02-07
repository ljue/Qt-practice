#-------------------------------------------------
#
# Project created by QtCreator 2017-01-20T12:05:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Miner
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    field.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    field.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += \
    myimages.qrc
