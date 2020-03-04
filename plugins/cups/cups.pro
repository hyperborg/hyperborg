include(cups.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = cups.h

SOURCES = cups.cpp

TARGET = $$qtLibraryTarget(cups)

DESTDIR = ../../plugins

EXAMPLE_FILES = cups.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


