include(syncthru.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = syncthru.h

SOURCES = syncthru.cpp

TARGET = $$qtLibraryTarget(syncthru)

DESTDIR = ../../plugins

EXAMPLE_FILES = syncthru.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


