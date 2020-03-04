include(input_select.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = input_select.h

SOURCES = input_select.cpp

TARGET = $$qtLibraryTarget(input_select)

DESTDIR = ../../plugins

EXAMPLE_FILES = input_select.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


