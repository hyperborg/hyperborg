include(systemmonitor.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = systemmonitor.h

SOURCES = systemmonitor.cpp

TARGET = $$qtLibraryTarget(systemmonitor)

DESTDIR = ../../plugins

EXAMPLE_FILES = systemmonitor.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


