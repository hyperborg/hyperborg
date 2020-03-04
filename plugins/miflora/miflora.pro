include(miflora.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = miflora.h

SOURCES = miflora.cpp

TARGET = $$qtLibraryTarget(miflora)

DESTDIR = ../../plugins

EXAMPLE_FILES = miflora.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


