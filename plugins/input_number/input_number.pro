include(input_number.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = input_number.h

SOURCES = input_number.cpp

TARGET = $$qtLibraryTarget(input_number)

DESTDIR = ../../plugins

EXAMPLE_FILES = input_number.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


