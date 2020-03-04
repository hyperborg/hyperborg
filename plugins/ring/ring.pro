include(ring.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ring.h

SOURCES = ring.cpp

TARGET = $$qtLibraryTarget(ring)

DESTDIR = ../../plugins

EXAMPLE_FILES = ring.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


