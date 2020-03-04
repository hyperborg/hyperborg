include(derivative.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = derivative.h

SOURCES = derivative.cpp

TARGET = $$qtLibraryTarget(derivative)

DESTDIR = ../../plugins

EXAMPLE_FILES = derivative.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


