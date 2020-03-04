include(air_quality.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = air_quality.h

SOURCES = air_quality.cpp

TARGET = $$qtLibraryTarget(air_quality)

DESTDIR = ../../plugins

EXAMPLE_FILES = air_quality.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


