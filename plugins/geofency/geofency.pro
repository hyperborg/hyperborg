include(geofency.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = geofency.h

SOURCES = geofency.cpp

TARGET = $$qtLibraryTarget(geofency)

DESTDIR = ../../plugins

EXAMPLE_FILES = geofency.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


