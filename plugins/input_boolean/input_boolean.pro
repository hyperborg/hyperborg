include(input_boolean.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = input_boolean.h

SOURCES = input_boolean.cpp

TARGET = $$qtLibraryTarget(input_boolean)

DESTDIR = ../../plugins

EXAMPLE_FILES = input_boolean.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


