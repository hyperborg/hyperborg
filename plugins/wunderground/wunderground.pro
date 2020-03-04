include(wunderground.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = wunderground.h

SOURCES = wunderground.cpp

TARGET = $$qtLibraryTarget(wunderground)

DESTDIR = ../../plugins

EXAMPLE_FILES = wunderground.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


