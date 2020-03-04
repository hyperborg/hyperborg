include(heos.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = heos.h

SOURCES = heos.cpp

TARGET = $$qtLibraryTarget(heos)

DESTDIR = ../../plugins

EXAMPLE_FILES = heos.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


