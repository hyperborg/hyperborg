include(trackr.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = trackr.h

SOURCES = trackr.cpp

TARGET = $$qtLibraryTarget(trackr)

DESTDIR = ../../plugins

EXAMPLE_FILES = trackr.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


