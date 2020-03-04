include(bitcoin.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = bitcoin.h

SOURCES = bitcoin.cpp

TARGET = $$qtLibraryTarget(bitcoin)

DESTDIR = ../../plugins

EXAMPLE_FILES = bitcoin.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


