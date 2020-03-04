include(kwb.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = kwb.h

SOURCES = kwb.cpp

TARGET = $$qtLibraryTarget(kwb)

DESTDIR = ../../plugins

EXAMPLE_FILES = kwb.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


