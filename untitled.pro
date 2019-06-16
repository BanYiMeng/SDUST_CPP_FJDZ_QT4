#-------------------------------------------------
#
# Project created by QtCreator 2019-06-08T22:41:07
#
#-------------------------------------------------

QT       += core gui
#QT       += phonon
QT       += webkit
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    flyobjects.cpp

HEADERS  += mainwindow.h \
    flyobjects.h

FORMS    += mainwindow.ui

DISTFILES +=

RESOURCES += \
    resource.qrc

QMAKE_CXXFLAGS += -os -pipe -std=c++11
