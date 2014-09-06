#-------------------------------------------------
#
# Project created by QtCreator 2014-05-27T22:10:10
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QuadCopter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    serial.cpp

HEADERS  += mainwindow.h \
    serial.h

FORMS    += mainwindow.ui

CONFIG   += c++11
