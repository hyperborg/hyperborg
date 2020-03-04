include(transport_nsw.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = transport_nsw.h

SOURCES = transport_nsw.cpp

TARGET = $$qtLibraryTarget(transport_nsw)

DESTDIR = ../../plugins

EXAMPLE_FILES = transport_nsw.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


