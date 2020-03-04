include(thingspeak.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = thingspeak.h

SOURCES = thingspeak.cpp

TARGET = $$qtLibraryTarget(thingspeak)

DESTDIR = ../../plugins

EXAMPLE_FILES = thingspeak.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


