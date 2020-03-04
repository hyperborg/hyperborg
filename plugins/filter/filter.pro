include(filter.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = filter.h

SOURCES = filter.cpp

TARGET = $$qtLibraryTarget(filter)

DESTDIR = ../../plugins

EXAMPLE_FILES = filter.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


