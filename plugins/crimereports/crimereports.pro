include(crimereports.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = crimereports.h

SOURCES = crimereports.cpp

TARGET = $$qtLibraryTarget(crimereports)

DESTDIR = ../../plugins

EXAMPLE_FILES = crimereports.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


