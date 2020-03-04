include(zeroconf.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = zeroconf.h

SOURCES = zeroconf.cpp

TARGET = $$qtLibraryTarget(zeroconf)

DESTDIR = ../../plugins

EXAMPLE_FILES = zeroconf.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


