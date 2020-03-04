include(pandora.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = pandora.h

SOURCES = pandora.cpp

TARGET = $$qtLibraryTarget(pandora)

DESTDIR = ../../plugins

EXAMPLE_FILES = pandora.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


