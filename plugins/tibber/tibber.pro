include(tibber.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = tibber.h

SOURCES = tibber.cpp

TARGET = $$qtLibraryTarget(tibber)

DESTDIR = ../../plugins

EXAMPLE_FILES = tibber.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


