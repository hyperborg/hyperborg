include(input_text.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = input_text.h

SOURCES = input_text.cpp

TARGET = $$qtLibraryTarget(input_text)

DESTDIR = ../../plugins

EXAMPLE_FILES = input_text.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


