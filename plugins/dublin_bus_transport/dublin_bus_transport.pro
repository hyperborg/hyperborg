include(dublin_bus_transport.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = dublin_bus_transport.h

SOURCES = dublin_bus_transport.cpp

TARGET = $$qtLibraryTarget(dublin_bus_transport)

DESTDIR = ../../plugins

EXAMPLE_FILES = dublin_bus_transport.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


