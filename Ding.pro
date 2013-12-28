#-------------------------------------------------
#
# Project created by QtCreator 2013-12-24T21:33:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ding
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ding.cpp

HEADERS  += mainwindow.h \
    ding.h

FORMS    += mainwindow.ui

ICON = bell.icns

OTHER_FILES += \
    bell.ico \
    media-playback-stop.png \
    media-playback-start.png \
    bell.wav

RESOURCES += \
    Resources.qrc
