include(radiotherm.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = radiotherm.h

SOURCES = radiotherm.cpp

TARGET = $$qtLibraryTarget(radiotherm)

DESTDIR = ../../plugins

EXAMPLE_FILES = radiotherm.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


