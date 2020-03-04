include(marytts.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = marytts.h

SOURCES = marytts.cpp

TARGET = $$qtLibraryTarget(marytts)

DESTDIR = ../../plugins

EXAMPLE_FILES = marytts.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


