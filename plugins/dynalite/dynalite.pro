include(dynalite.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = dynalite.h

SOURCES = dynalite.cpp

TARGET = $$qtLibraryTarget(dynalite)

DESTDIR = ../../plugins

EXAMPLE_FILES = dynalite.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


