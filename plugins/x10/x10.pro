include(x10.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = x10.h

SOURCES = x10.cpp

TARGET = $$qtLibraryTarget(x10)

DESTDIR = ../../plugins

EXAMPLE_FILES = x10.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


