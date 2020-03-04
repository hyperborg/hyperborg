include(bloomsky.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = bloomsky.h

SOURCES = bloomsky.cpp

TARGET = $$qtLibraryTarget(bloomsky)

DESTDIR = ../../plugins

EXAMPLE_FILES = bloomsky.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


