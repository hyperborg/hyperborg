include(script.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = script.h

SOURCES = script.cpp

TARGET = $$qtLibraryTarget(script)

DESTDIR = ../../plugins

EXAMPLE_FILES = script.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


