#-------------------------------------------------
#
# Project created by QtCreator 2022-02-26T15:03:39
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = udp-socket
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    socket.cpp

HEADERS  += mainwindow.h \
    socket.h

FORMS    += mainwindow.ui
