#-------------------------------------------------
#
# Project created by QtCreator 2016-10-26T00:25:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ovv
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow1.cpp \
    first_window.cpp \
    login_window.cpp \
    voter_window.cpp \
    area.cpp

HEADERS  += mainwindow1.h \
    first_window.h \
    login_window.h \
    voter_window.h \
    area.h

FORMS    += mainwindow1.ui \
    first_window.ui \
    login_window.ui \
    voter_window.ui

RESOURCES += \
    src/files.qrc
