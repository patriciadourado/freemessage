#-------------------------------------------------
#
# Project created by Patricia Dourado 2022-06-12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = freemessage
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    OtherWords.cpp

HEADERS  += mainwindow.h \
    OtherWords.h

FORMS    += mainwindow.ui

CONFIG += c++11

RESOURCES += \
    resources.qrc

RC_ICONS = favicon.ico
