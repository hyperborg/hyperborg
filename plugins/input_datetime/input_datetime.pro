include(input_datetime.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = input_datetime.h

SOURCES = input_datetime.cpp

TARGET = $$qtLibraryTarget(input_datetime)

DESTDIR = ../../plugins

EXAMPLE_FILES = input_datetime.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


