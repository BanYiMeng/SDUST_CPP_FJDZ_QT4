#-------------------------------------------------
#
# Project created by QtCreator 2019-06-08T22:41:07
#
#-------------------------------------------------

QT       += core gui
QT       += phonon
QT       += webkit
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    flyobjects.cpp \
    playwindow.cpp \
    supply.cpp \
    background.cpp \
    special.cpp \
    boss.cpp \
    chapter.cpp \
    planefatory.cpp \
    e_bullet.cpp \
    f_bullet.cpp \
    strike.cpp \
    bulletfactory.cpp \
    enemy.cpp \
    flyer.cpp \
    bullet.cpp

HEADERS  += mainwindow.h \
    flyobjects.h \
    playwindow.h \
    supply.h \
    background.h \
    special.h \
    boss.h \
    chapter.h \
    planefatory.h \
    e_bullet.h \
    f_bullet.h \
    strike.h \
    bulletfactory.h \
    enemy.h \
    flyer.h \
    bullet.h

FORMS    += mainwindow.ui \
    playwindow.ui

DISTFILES +=

RESOURCES += \
    resource.qrc

QMAKE_CXXFLAGS += -os -pipe -std=c++11
