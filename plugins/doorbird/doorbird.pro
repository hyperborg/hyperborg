include(doorbird.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = doorbird.h

SOURCES = doorbird.cpp

TARGET = $$qtLibraryTarget(doorbird)

DESTDIR = ../../plugins

EXAMPLE_FILES = doorbird.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


