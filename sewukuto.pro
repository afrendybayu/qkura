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

OBJECTS_DIR = compile
MOC_DIR = compile

SOURCES += main.cpp \
    model/modelmodem.cpp \
    view/skywavenetwork.cpp \
    util/util_skyw.cpp \
    controller/worker.cpp

HEADERS += \
    model/modelmodem.h \
    util/initdb.h \
    view/skywavenetwork.h \
    util/util_skyw.h \
    controller/worker.h
