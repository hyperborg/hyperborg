include(geizhals.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = geizhals.h

SOURCES = geizhals.cpp

TARGET = $$qtLibraryTarget(geizhals)

DESTDIR = ../../plugins

EXAMPLE_FILES = geizhals.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


