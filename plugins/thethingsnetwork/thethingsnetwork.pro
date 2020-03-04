include(thethingsnetwork.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = thethingsnetwork.h

SOURCES = thethingsnetwork.cpp

TARGET = $$qtLibraryTarget(thethingsnetwork)

DESTDIR = ../../plugins

EXAMPLE_FILES = thethingsnetwork.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


