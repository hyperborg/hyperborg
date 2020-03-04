include(gios.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = gios.h

SOURCES = gios.cpp

TARGET = $$qtLibraryTarget(gios)

DESTDIR = ../../plugins

EXAMPLE_FILES = gios.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


