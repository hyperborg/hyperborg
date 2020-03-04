include(aten_pe.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = aten_pe.h

SOURCES = aten_pe.cpp

TARGET = $$qtLibraryTarget(aten_pe)

DESTDIR = ../../plugins

EXAMPLE_FILES = aten_pe.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


