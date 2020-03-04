include(generic_thermostat.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = generic_thermostat.h

SOURCES = generic_thermostat.cpp

TARGET = $$qtLibraryTarget(generic_thermostat)

DESTDIR = ../../plugins

EXAMPLE_FILES = generic_thermostat.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


