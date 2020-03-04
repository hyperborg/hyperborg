include(geo_location.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = geo_location.h

SOURCES = geo_location.cpp

TARGET = $$qtLibraryTarget(geo_location)

DESTDIR = ../../plugins

EXAMPLE_FILES = geo_location.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


