include(zha.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = zha.h

SOURCES = zha.cpp

TARGET = $$qtLibraryTarget(zha)

DESTDIR = ../../plugins

EXAMPLE_FILES = zha.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


