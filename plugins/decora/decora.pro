include(decora.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = decora.h

SOURCES = decora.cpp

TARGET = $$qtLibraryTarget(decora)

DESTDIR = ../../plugins

EXAMPLE_FILES = decora.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


