include(iglo.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = iglo.h

SOURCES = iglo.cpp

TARGET = $$qtLibraryTarget(iglo)

DESTDIR = ../../plugins

EXAMPLE_FILES = iglo.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


