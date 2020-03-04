include(gpsd.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = gpsd.h

SOURCES = gpsd.cpp

TARGET = $$qtLibraryTarget(gpsd)

DESTDIR = ../../plugins

EXAMPLE_FILES = gpsd.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


