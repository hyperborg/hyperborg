include(noaa_tides.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = noaa_tides.h

SOURCES = noaa_tides.cpp

TARGET = $$qtLibraryTarget(noaa_tides)

DESTDIR = ../../plugins

EXAMPLE_FILES = noaa_tides.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


