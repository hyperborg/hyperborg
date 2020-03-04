include(clementine.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = clementine.h

SOURCES = clementine.cpp

TARGET = $$qtLibraryTarget(clementine)

DESTDIR = ../../plugins

EXAMPLE_FILES = clementine.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


