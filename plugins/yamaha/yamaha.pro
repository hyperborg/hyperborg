include(yamaha.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = yamaha.h

SOURCES = yamaha.cpp

TARGET = $$qtLibraryTarget(yamaha)

DESTDIR = ../../plugins

EXAMPLE_FILES = yamaha.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


