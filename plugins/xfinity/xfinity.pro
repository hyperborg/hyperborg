include(xfinity.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = xfinity.h

SOURCES = xfinity.cpp

TARGET = $$qtLibraryTarget(xfinity)

DESTDIR = ../../plugins

EXAMPLE_FILES = xfinity.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


