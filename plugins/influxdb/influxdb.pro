include(influxdb.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = influxdb.h

SOURCES = influxdb.cpp

TARGET = $$qtLibraryTarget(influxdb)

DESTDIR = ../../plugins

EXAMPLE_FILES = influxdb.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


