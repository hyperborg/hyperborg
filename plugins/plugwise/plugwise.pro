include(plugwise.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = plugwise.h

SOURCES = plugwise.cpp

TARGET = $$qtLibraryTarget(plugwise)

DESTDIR = ../../plugins

EXAMPLE_FILES = plugwise.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


