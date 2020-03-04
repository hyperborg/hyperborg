include(norway_air.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = norway_air.h

SOURCES = norway_air.cpp

TARGET = $$qtLibraryTarget(norway_air)

DESTDIR = ../../plugins

EXAMPLE_FILES = norway_air.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


