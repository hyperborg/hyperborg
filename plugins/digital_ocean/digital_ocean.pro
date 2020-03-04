include(digital_ocean.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = digital_ocean.h

SOURCES = digital_ocean.cpp

TARGET = $$qtLibraryTarget(digital_ocean)

DESTDIR = ../../plugins

EXAMPLE_FILES = digital_ocean.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


