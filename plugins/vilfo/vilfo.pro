include(vilfo.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = vilfo.h

SOURCES = vilfo.cpp

TARGET = $$qtLibraryTarget(vilfo)

DESTDIR = ../../plugins

EXAMPLE_FILES = vilfo.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


