#-------------------------------------------------
#
# Project created by QtCreator 2016-05-29T13:29:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chess-QT
TEMPLATE = app


SOURCES += main.cpp\
        chessboard.cpp \
    tile.cpp \
    game.cpp \
    theme.cpp \
    themedialog.cpp \
    aboutdialog.cpp \
    rulebook.cpp

HEADERS  += chessboard.h \
    tile.h \
    game.h \
    theme.h \
    themedialog.h \
    aboutdialog.h \
    rulebook.h

FORMS    += chessboard.ui \
    themedialog.ui \
    aboutdialog.ui \
    rulebook.ui
