include(tod.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = tod.h

SOURCES = tod.cpp

TARGET = $$qtLibraryTarget(tod)

DESTDIR = ../../plugins

EXAMPLE_FILES = tod.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


