include(freedns.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = freedns.h

SOURCES = freedns.cpp

TARGET = $$qtLibraryTarget(freedns)

DESTDIR = ../../plugins

EXAMPLE_FILES = freedns.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


