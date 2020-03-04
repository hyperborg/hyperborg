include(hydrawise.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = hydrawise.h

SOURCES = hydrawise.cpp

TARGET = $$qtLibraryTarget(hydrawise)

DESTDIR = ../../plugins

EXAMPLE_FILES = hydrawise.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


