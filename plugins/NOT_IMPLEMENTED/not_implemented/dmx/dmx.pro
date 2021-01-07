include(dmx.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = dmx.h

SOURCES = dmx.cpp

TARGET = $$qtLibraryTarget(dmx)

DESTDIR = ../../plugins

EXAMPLE_FILES = dmx.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


