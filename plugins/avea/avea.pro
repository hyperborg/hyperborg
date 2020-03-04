include(avea.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = avea.h

SOURCES = avea.cpp

TARGET = $$qtLibraryTarget(avea)

DESTDIR = ../../plugins

EXAMPLE_FILES = avea.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


