include(spotify.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = spotify.h

SOURCES = spotify.cpp

TARGET = $$qtLibraryTarget(spotify)

DESTDIR = ../../plugins

EXAMPLE_FILES = spotify.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


