include(dlna_dmr.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = dlna_dmr.h

SOURCES = dlna_dmr.cpp

TARGET = $$qtLibraryTarget(dlna_dmr)

DESTDIR = ../../plugins

EXAMPLE_FILES = dlna_dmr.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


