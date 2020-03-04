include(ecobee.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ecobee.h

SOURCES = ecobee.cpp

TARGET = $$qtLibraryTarget(ecobee)

DESTDIR = ../../plugins

EXAMPLE_FILES = ecobee.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


