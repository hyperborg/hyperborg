include(dsmr.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = dsmr.h

SOURCES = dsmr.cpp

TARGET = $$qtLibraryTarget(dsmr)

DESTDIR = ../../plugins

EXAMPLE_FILES = dsmr.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


