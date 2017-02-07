#-------------------------------------------------
#
# Project created by QtCreator 2016-12-13T16:29:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tetris
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glass.cpp \
    figure.cpp \
    nextfigure.cpp

HEADERS  += mainwindow.h \
    glass.h \
    figure.h \
    nextfigure.h

FORMS    += mainwindow.ui

RESOURCES += \
    tetrisresourses.qrc
