include(bom.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = bom.h

SOURCES = bom.cpp

TARGET = $$qtLibraryTarget(bom)

DESTDIR = ../../plugins

EXAMPLE_FILES = bom.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


