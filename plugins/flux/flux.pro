include(flux.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = flux.h

SOURCES = flux.cpp

TARGET = $$qtLibraryTarget(flux)

DESTDIR = ../../plugins

EXAMPLE_FILES = flux.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


