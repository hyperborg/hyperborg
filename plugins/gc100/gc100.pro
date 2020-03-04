include(gc100.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = gc100.h

SOURCES = gc100.cpp

TARGET = $$qtLibraryTarget(gc100)

DESTDIR = ../../plugins

EXAMPLE_FILES = gc100.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


