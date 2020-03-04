include(demo.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = demo.h

SOURCES = demo.cpp

TARGET = $$qtLibraryTarget(demo)

DESTDIR = ../../plugins

EXAMPLE_FILES = demo.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


