include(bizkaibus.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = bizkaibus.h

SOURCES = bizkaibus.cpp

TARGET = $$qtLibraryTarget(bizkaibus)

DESTDIR = ../../plugins

EXAMPLE_FILES = bizkaibus.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


