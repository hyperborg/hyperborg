include(flume.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = flume.h

SOURCES = flume.cpp

TARGET = $$qtLibraryTarget(flume)

DESTDIR = ../../plugins

EXAMPLE_FILES = flume.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


