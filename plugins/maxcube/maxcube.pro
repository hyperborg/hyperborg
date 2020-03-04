include(maxcube.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = maxcube.h

SOURCES = maxcube.cpp

TARGET = $$qtLibraryTarget(maxcube)

DESTDIR = ../../plugins

EXAMPLE_FILES = maxcube.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


