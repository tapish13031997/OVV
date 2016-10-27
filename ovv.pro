#-------------------------------------------------
#
# Project created by QtCreator 2016-10-26T00:25:47
#
#-------------------------------------------------

QT       += core gui
+=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ovv
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow1.cpp \
    first_window.cpp \
    login_window.cpp \
    voter_window.cpp \
    area.cpp \
    voter_form.cpp

HEADERS  += mainwindow1.h \
    first_window.h \
    login_window.h \
    voter_window.h \
    area.h \
    voter_form.h \
    initdb.h

FORMS    += mainwindow1.ui \
    first_window.ui \
    login_window.ui \
    voter_window.ui \
    voter_form.ui

RESOURCES += \
    src/files.qrc
