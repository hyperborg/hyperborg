include(delijn.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = delijn.h

SOURCES = delijn.cpp

TARGET = $$qtLibraryTarget(delijn)

DESTDIR = ../../plugins

EXAMPLE_FILES = delijn.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


