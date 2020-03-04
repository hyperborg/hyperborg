include(netdata.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = netdata.h

SOURCES = netdata.cpp

TARGET = $$qtLibraryTarget(netdata)

DESTDIR = ../../plugins

EXAMPLE_FILES = netdata.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


