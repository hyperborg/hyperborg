include(iota.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = iota.h

SOURCES = iota.cpp

TARGET = $$qtLibraryTarget(iota)

DESTDIR = ../../plugins

EXAMPLE_FILES = iota.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


