#-------------------------------------------------
#
# Project created by QtCreator 2018-07-12T22:25:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = simpleqt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        src/main.cpp \
        src/includes/calculator.cpp \
        src/includes/consoleview.cpp \
        src/includes/guicalcview.cpp \

HEADERS += \
        src/headers/guicalcview.h \
        src/headers/calculator.h \
        src/headers/consoleview.h \
        src/headers/iapplicationflowcontroller.h \
        src/headers/icalculatoriohandler.h

FORMS += \
        src/gui/guicalcview.ui

