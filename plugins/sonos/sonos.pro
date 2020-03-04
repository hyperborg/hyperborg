include(sonos.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sonos.h

SOURCES = sonos.cpp

TARGET = $$qtLibraryTarget(sonos)

DESTDIR = ../../plugins

EXAMPLE_FILES = sonos.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


