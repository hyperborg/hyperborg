include(meteo_france.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = meteo_france.h

SOURCES = meteo_france.cpp

TARGET = $$qtLibraryTarget(meteo_france)

DESTDIR = ../../plugins

EXAMPLE_FILES = meteo_france.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


