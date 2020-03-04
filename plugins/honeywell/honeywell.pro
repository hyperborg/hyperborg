include(honeywell.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = honeywell.h

SOURCES = honeywell.cpp

TARGET = $$qtLibraryTarget(honeywell)

DESTDIR = ../../plugins

EXAMPLE_FILES = honeywell.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


