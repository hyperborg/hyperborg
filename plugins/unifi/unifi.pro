include(unifi.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = unifi.h

SOURCES = unifi.cpp

TARGET = $$qtLibraryTarget(unifi)

DESTDIR = ../../plugins

EXAMPLE_FILES = unifi.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


