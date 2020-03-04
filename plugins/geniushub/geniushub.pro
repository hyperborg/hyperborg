include(geniushub.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = geniushub.h

SOURCES = geniushub.cpp

TARGET = $$qtLibraryTarget(geniushub)

DESTDIR = ../../plugins

EXAMPLE_FILES = geniushub.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


