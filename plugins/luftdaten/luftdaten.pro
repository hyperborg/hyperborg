include(luftdaten.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = luftdaten.h

SOURCES = luftdaten.cpp

TARGET = $$qtLibraryTarget(luftdaten)

DESTDIR = ../../plugins

EXAMPLE_FILES = luftdaten.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


