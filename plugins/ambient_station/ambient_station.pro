include(ambient_station.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ambient_station.h

SOURCES = ambient_station.cpp

TARGET = $$qtLibraryTarget(ambient_station)

DESTDIR = ../../plugins

EXAMPLE_FILES = ambient_station.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


