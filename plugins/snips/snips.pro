include(snips.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = snips.h

SOURCES = snips.cpp

TARGET = $$qtLibraryTarget(snips)

DESTDIR = ../../plugins

EXAMPLE_FILES = snips.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


