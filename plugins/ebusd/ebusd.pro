include(ebusd.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ebusd.h

SOURCES = ebusd.cpp

TARGET = $$qtLibraryTarget(ebusd)

DESTDIR = ../../plugins

EXAMPLE_FILES = ebusd.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


