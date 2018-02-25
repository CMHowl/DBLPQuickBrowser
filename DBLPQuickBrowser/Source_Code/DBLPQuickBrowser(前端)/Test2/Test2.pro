#-------------------------------------------------
#
# Project created by QtCreator 2017-03-24T14:08:48
#
#-------------------------------------------------

QT       += core gui
QT +=  axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Test2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    analysedialog.cpp \
    allauthordialog.cpp \
    netmapdialog.cpp

HEADERS  += mainwindow.h \
    commonhelper.h \
    analysedialog.h \
    allauthordialog.h \
    netmapdialog.h

FORMS    += mainwindow.ui \
    analysedialog.ui \
    allauthordialog.ui \
    netmapdialog.ui

RESOURCES += \
    authorcountryicon.qrc

DISTFILES +=
