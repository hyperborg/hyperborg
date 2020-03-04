include(insteon.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = insteon.h

SOURCES = insteon.cpp

TARGET = $$qtLibraryTarget(insteon)

DESTDIR = ../../plugins

EXAMPLE_FILES = insteon.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


