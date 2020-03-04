include(geonetnz_quakes.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = geonetnz_quakes.h

SOURCES = geonetnz_quakes.cpp

TARGET = $$qtLibraryTarget(geonetnz_quakes)

DESTDIR = ../../plugins

EXAMPLE_FILES = geonetnz_quakes.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


