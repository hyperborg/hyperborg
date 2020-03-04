include(doods.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = doods.h

SOURCES = doods.cpp

TARGET = $$qtLibraryTarget(doods)

DESTDIR = ../../plugins

EXAMPLE_FILES = doods.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


