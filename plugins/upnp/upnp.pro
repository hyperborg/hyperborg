include(upnp.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = upnp.h

SOURCES = upnp.cpp

TARGET = $$qtLibraryTarget(upnp)

DESTDIR = ../../plugins

EXAMPLE_FILES = upnp.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


