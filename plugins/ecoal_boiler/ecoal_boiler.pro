include(ecoal_boiler.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ecoal_boiler.h

SOURCES = ecoal_boiler.cpp

TARGET = $$qtLibraryTarget(ecoal_boiler)

DESTDIR = ../../plugins

EXAMPLE_FILES = ecoal_boiler.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


