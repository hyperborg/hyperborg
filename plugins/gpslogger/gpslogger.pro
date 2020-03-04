include(gpslogger.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = gpslogger.h

SOURCES = gpslogger.cpp

TARGET = $$qtLibraryTarget(gpslogger)

DESTDIR = ../../plugins

EXAMPLE_FILES = gpslogger.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


