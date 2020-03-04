include(w800rf32.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = w800rf32.h

SOURCES = w800rf32.cpp

TARGET = $$qtLibraryTarget(w800rf32)

DESTDIR = ../../plugins

EXAMPLE_FILES = w800rf32.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


