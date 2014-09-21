#-------------------------------------------------
#
# Project created by QtCreator 2014-09-16T05:56:04
#
#-------------------------------------------------

QT       += core

QT       -= gui
QT       += sql
QT       += network

TARGET = sewukuto
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    model/modelmodem.cpp \
    view/skywavenetwork.cpp \
    worker.cpp

HEADERS += \
    model/modelmodem.h \
    util/initdb.h \
    view/skywavenetwork.h \
    worker.h
