#-------------------------------------------------
#
# Project created by QtCreator 2015-08-22T21:15:47
#
#-------------------------------------------------

QT       += core gui network sql webkit webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = enQuiz
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    appicon.qrc

mac {
ICON = enquiz.icns
}

