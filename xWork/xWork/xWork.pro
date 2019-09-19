#-------------------------------------------------
#
# Project created by QtCreator 2019-07-31T16:42:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = xWork
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    painterwidget.cpp \
    paramswidget.cpp

HEADERS  += mainwindow.h \
    painterwidget.h \
    paramswidget.h

FORMS    += mainwindow.ui

RESOURCES += \
    image.qrc \
    drawtype.qrc
