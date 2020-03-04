include(avion.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = avion.h

SOURCES = avion.cpp

TARGET = $$qtLibraryTarget(avion)

DESTDIR = ../../plugins

EXAMPLE_FILES = avion.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


