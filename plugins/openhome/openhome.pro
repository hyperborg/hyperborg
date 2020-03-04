include(openhome.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = openhome.h

SOURCES = openhome.cpp

TARGET = $$qtLibraryTarget(openhome)

DESTDIR = ../../plugins

EXAMPLE_FILES = openhome.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


