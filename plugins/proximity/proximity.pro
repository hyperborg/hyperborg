include(proximity.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = proximity.h

SOURCES = proximity.cpp

TARGET = $$qtLibraryTarget(proximity)

DESTDIR = ../../plugins

EXAMPLE_FILES = proximity.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


