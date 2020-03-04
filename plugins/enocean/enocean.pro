include(enocean.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = enocean.h

SOURCES = enocean.cpp

TARGET = $$qtLibraryTarget(enocean)

DESTDIR = ../../plugins

EXAMPLE_FILES = enocean.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


