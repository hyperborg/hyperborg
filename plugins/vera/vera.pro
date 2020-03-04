include(vera.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = vera.h

SOURCES = vera.cpp

TARGET = $$qtLibraryTarget(vera)

DESTDIR = ../../plugins

EXAMPLE_FILES = vera.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


