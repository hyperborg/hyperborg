include(mpd.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mpd.h

SOURCES = mpd.cpp

TARGET = $$qtLibraryTarget(mpd)

DESTDIR = ../../plugins

EXAMPLE_FILES = mpd.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


