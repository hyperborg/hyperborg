include(epsonworkforce.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = epsonworkforce.h

SOURCES = epsonworkforce.cpp

TARGET = $$qtLibraryTarget(epsonworkforce)

DESTDIR = ../../plugins

EXAMPLE_FILES = epsonworkforce.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


