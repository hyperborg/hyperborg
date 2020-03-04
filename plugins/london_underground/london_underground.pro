include(london_underground.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = london_underground.h

SOURCES = london_underground.cpp

TARGET = $$qtLibraryTarget(london_underground)

DESTDIR = ../../plugins

EXAMPLE_FILES = london_underground.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


