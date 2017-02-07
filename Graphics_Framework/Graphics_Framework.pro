#-------------------------------------------------
#
# Project created by QtCreator 2017-01-11T15:45:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Graphics_Framework
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myscene.cpp \
    dialog.cpp \
    pattern.cpp \
    myrect.cpp \
    mymodel.cpp \
    mydelegate.cpp

HEADERS  += mainwindow.h \
    myscene.h \
    dialog.h \
    pattern.h \
    myrect.h \
    mymodel.h \
    mydelegate.h

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += \
    myimages.qrc

QT += sql
