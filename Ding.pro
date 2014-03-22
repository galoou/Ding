QT           += core widgets multimedia

TARGET        = Ding

TEMPLATE      = app

SOURCES      += main.cpp mainwindow.cpp ding.cpp

HEADERS      += mainwindow.h ding.h

FORMS        += mainwindow.ui

macx:ICON     = bell.icns

win32:RC_FILE = bell.rc

OTHER_FILES  += bell.icns \
                bell.ico \
                bell.rc \
                bell.wav \
                media-playback-start.png \
                media-playback-stop.png

RESOURCES   += Resources.qrc
