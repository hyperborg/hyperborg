include(trafikverket_weatherstation.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = trafikverket_weatherstation.h

SOURCES = trafikverket_weatherstation.cpp

TARGET = $$qtLibraryTarget(trafikverket_weatherstation)

DESTDIR = ../../plugins

EXAMPLE_FILES = trafikverket_weatherstation.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


