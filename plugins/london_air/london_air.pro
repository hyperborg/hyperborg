include(london_air.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = london_air.h

SOURCES = london_air.cpp

TARGET = $$qtLibraryTarget(london_air)

DESTDIR = ../../plugins

EXAMPLE_FILES = london_air.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


