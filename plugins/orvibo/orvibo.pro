include(orvibo.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = orvibo.h

SOURCES = orvibo.cpp

TARGET = $$qtLibraryTarget(orvibo)

DESTDIR = ../../plugins

EXAMPLE_FILES = orvibo.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


