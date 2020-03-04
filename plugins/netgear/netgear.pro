include(netgear.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = netgear.h

SOURCES = netgear.cpp

TARGET = $$qtLibraryTarget(netgear)

DESTDIR = ../../plugins

EXAMPLE_FILES = netgear.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


