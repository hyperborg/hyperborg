include(ihc.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ihc.h

SOURCES = ihc.cpp

TARGET = $$qtLibraryTarget(ihc)

DESTDIR = ../../plugins

EXAMPLE_FILES = ihc.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


