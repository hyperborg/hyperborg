include(rainbird.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = rainbird.h

SOURCES = rainbird.cpp

TARGET = $$qtLibraryTarget(rainbird)

DESTDIR = ../../plugins

EXAMPLE_FILES = rainbird.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


