include(eddystone_temperature.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = eddystone_temperature.h

SOURCES = eddystone_temperature.cpp

TARGET = $$qtLibraryTarget(eddystone_temperature)

DESTDIR = ../../plugins

EXAMPLE_FILES = eddystone_temperature.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


