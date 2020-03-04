include(fortios.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = fortios.h

SOURCES = fortios.cpp

TARGET = $$qtLibraryTarget(fortios)

DESTDIR = ../../plugins

EXAMPLE_FILES = fortios.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


