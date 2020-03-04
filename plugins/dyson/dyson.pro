include(dyson.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = dyson.h

SOURCES = dyson.cpp

TARGET = $$qtLibraryTarget(dyson)

DESTDIR = ../../plugins

EXAMPLE_FILES = dyson.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


