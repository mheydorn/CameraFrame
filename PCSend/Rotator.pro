#-------------------------------------------------
#
# Project created by QtCreator 2015-05-05T16:04:27
#
#-------------------------------------------------
include(qextserialport/src/qextserialport.pri)
DEFINES += QEXTSERIALPORT_USING_SHARED
QT       += core gui
#CONFIG += release staticlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RotatorGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc

OTHER_FILES +=
