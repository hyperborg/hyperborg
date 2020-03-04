include(tile.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = tile.h

SOURCES = tile.cpp

TARGET = $$qtLibraryTarget(tile)

DESTDIR = ../../plugins

EXAMPLE_FILES = tile.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


