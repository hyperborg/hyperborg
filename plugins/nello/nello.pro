include(nello.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = nello.h

SOURCES = nello.cpp

TARGET = $$qtLibraryTarget(nello)

DESTDIR = ../../plugins

EXAMPLE_FILES = nello.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


