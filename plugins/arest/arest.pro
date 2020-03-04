include(arest.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = arest.h

SOURCES = arest.cpp

TARGET = $$qtLibraryTarget(arest)

DESTDIR = ../../plugins

EXAMPLE_FILES = arest.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


