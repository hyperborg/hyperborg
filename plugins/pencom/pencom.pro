include(pencom.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = pencom.h

SOURCES = pencom.cpp

TARGET = $$qtLibraryTarget(pencom)

DESTDIR = ../../plugins

EXAMPLE_FILES = pencom.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


