include(netgear_lte.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = netgear_lte.h

SOURCES = netgear_lte.cpp

TARGET = $$qtLibraryTarget(netgear_lte)

DESTDIR = ../../plugins

EXAMPLE_FILES = netgear_lte.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


