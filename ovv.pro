#-------------------------------------------------
#
# Project created by QtCreator 2016-10-26T00:25:47
#
#-------------------------------------------------

QT       += core gui
QT +=sql
QT +=widgets
QT +=core
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ovv
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow1.cpp \
    first_window.cpp \
    login_window.cpp \
    candidate.cpp \
    area.cpp \
    voter.cpp \
    voter_form.cpp \
    admin.cpp \
    manage_voter.cpp \
    select_area.cpp \
    manage_candidate.cpp \
    add_candidate.cpp \
    modify_candidate.cpp \
    voter_welcome_window.cpp \
    voter_window.cpp \
    add_area.cpp \
    add_party.cpp \
    manage_parties.cpp \
    manage_area.cpp

    voter_form.cpp

HEADERS  += mainwindow1.h \
    first_window.h \
    login_window.h \
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
    modify_candidate.h \
    voter_welcome_window.h \
    voter_window.h \
    add_area.h \
    add_party.h \
    manage_parties.h \
    party.h \
    manage_area.h

FORMS    += mainwindow1.ui \
    first_window.ui \
    login_window.ui \
    voter_form.ui \
    admin.ui \
    manage_voter.ui \
    select_area.ui \
    manage_candidate.ui \
    add_candidate.ui \
    modify_candidate.ui \
    voter_welcome_window.ui \
    voter_window.ui \
    add_area.ui \
    add_party.ui \
    manage_parties.ui \
    manage_area.ui

RESOURCES += \
    src/files.qrc
