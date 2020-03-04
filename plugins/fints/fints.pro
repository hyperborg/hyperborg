include(fints.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = fints.h

SOURCES = fints.cpp

TARGET = $$qtLibraryTarget(fints)

DESTDIR = ../../plugins

EXAMPLE_FILES = fints.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


