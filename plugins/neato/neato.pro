include(neato.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = neato.h

SOURCES = neato.cpp

TARGET = $$qtLibraryTarget(neato)

DESTDIR = ../../plugins

EXAMPLE_FILES = neato.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


