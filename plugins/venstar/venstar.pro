include(venstar.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = venstar.h

SOURCES = venstar.cpp

TARGET = $$qtLibraryTarget(venstar)

DESTDIR = ../../plugins

EXAMPLE_FILES = venstar.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


