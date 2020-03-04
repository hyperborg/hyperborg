include(edimax.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = edimax.h

SOURCES = edimax.cpp

TARGET = $$qtLibraryTarget(edimax)

DESTDIR = ../../plugins

EXAMPLE_FILES = edimax.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


