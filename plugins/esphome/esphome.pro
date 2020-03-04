include(esphome.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = esphome.h

SOURCES = esphome.cpp

TARGET = $$qtLibraryTarget(esphome)

DESTDIR = ../../plugins

EXAMPLE_FILES = esphome.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


