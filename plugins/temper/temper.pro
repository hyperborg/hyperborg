include(temper.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = temper.h

SOURCES = temper.cpp

TARGET = $$qtLibraryTarget(temper)

DESTDIR = ../../plugins

EXAMPLE_FILES = temper.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


