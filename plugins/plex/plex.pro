include(plex.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = plex.h

SOURCES = plex.cpp

TARGET = $$qtLibraryTarget(plex)

DESTDIR = ../../plugins

EXAMPLE_FILES = plex.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


