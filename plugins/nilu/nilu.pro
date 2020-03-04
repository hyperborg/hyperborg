include(nilu.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = nilu.h

SOURCES = nilu.cpp

TARGET = $$qtLibraryTarget(nilu)

DESTDIR = ../../plugins

EXAMPLE_FILES = nilu.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


