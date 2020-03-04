include(gtfs.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = gtfs.h

SOURCES = gtfs.cpp

TARGET = $$qtLibraryTarget(gtfs)

DESTDIR = ../../plugins

EXAMPLE_FILES = gtfs.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


