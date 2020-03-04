include(epson.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = epson.h

SOURCES = epson.cpp

TARGET = $$qtLibraryTarget(epson)

DESTDIR = ../../plugins

EXAMPLE_FILES = epson.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


