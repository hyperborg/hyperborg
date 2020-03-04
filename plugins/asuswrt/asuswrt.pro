include(asuswrt.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = asuswrt.h

SOURCES = asuswrt.cpp

TARGET = $$qtLibraryTarget(asuswrt)

DESTDIR = ../../plugins

EXAMPLE_FILES = asuswrt.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


