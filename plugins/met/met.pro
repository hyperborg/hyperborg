include(met.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = met.h

SOURCES = met.cpp

TARGET = $$qtLibraryTarget(met)

DESTDIR = ../../plugins

EXAMPLE_FILES = met.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


