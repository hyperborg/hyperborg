include(brottsplatskartan.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = brottsplatskartan.h

SOURCES = brottsplatskartan.cpp

TARGET = $$qtLibraryTarget(brottsplatskartan)

DESTDIR = ../../plugins

EXAMPLE_FILES = brottsplatskartan.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


