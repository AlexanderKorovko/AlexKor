#-------------------------------------------------
#
# Project created by QtCreator 2016-08-05T18:57:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Filter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myfilesystemodel.cpp \
    filter.cpp \
    final_window.cpp \


FORMS    += mainwindow.ui \
    myfilesystemodel.ui \
    final_window.ui

HEADERS += \
    filter.h \
    final_window.h \
    mainwindow.h \
    myfilesystemodel.h \


