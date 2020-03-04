include(rest.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = rest.h

SOURCES = rest.cpp

TARGET = $$qtLibraryTarget(rest)

DESTDIR = ../../plugins

EXAMPLE_FILES = rest.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


