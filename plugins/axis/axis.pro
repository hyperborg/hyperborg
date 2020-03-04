include(axis.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = axis.h

SOURCES = axis.cpp

TARGET = $$qtLibraryTarget(axis)

DESTDIR = ../../plugins

EXAMPLE_FILES = axis.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


