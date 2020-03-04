include(nest.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = nest.h

SOURCES = nest.cpp

TARGET = $$qtLibraryTarget(nest)

DESTDIR = ../../plugins

EXAMPLE_FILES = nest.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


