#-------------------------------------------------
#
# Project created by QtCreator 2016-10-26T00:25:47
#
#-------------------------------------------------

QT       += core gui
QT +=sql
QT +=widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ovv
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow1.cpp \
    first_window.cpp \
    login_window.cpp \
    voter_window.cpp \
    candidate.cpp \
    area.cpp \
    voter.cpp \
    voter_form.cpp \
    admin.cpp \
    manage_voter.cpp \
    select_area.cpp \
    manage_candidate.cpp \
    add_candidate.cpp \
    modify_candidate.cpp

    voter_form.cpp

HEADERS  += mainwindow1.h \
    first_window.h \
    login_window.h \
    voter_window.h \
    voter_form.h \
    area.h \
    candidate.h \
    initdb.h \
    voter.h \
    admin.h \
    manage_voter.h \
    select_area.h \
    manage_candidate.h \
    add_candidate.h \
    modify_candidate.h

FORMS    += mainwindow1.ui \
    first_window.ui \
    login_window.ui \
    voter_window.ui \
    voter_form.ui \
    admin.ui \
    manage_voter.ui \
    select_area.ui \
    manage_candidate.ui \
    add_candidate.ui \
    modify_candidate.ui

RESOURCES += \
    src/files.qrc
