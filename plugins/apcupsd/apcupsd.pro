include(apcupsd.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = apcupsd.h

SOURCES = apcupsd.cpp

TARGET = $$qtLibraryTarget(apcupsd)

DESTDIR = ../../plugins

EXAMPLE_FILES = apcupsd.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


