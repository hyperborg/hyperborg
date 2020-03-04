include(transmission.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = transmission.h

SOURCES = transmission.cpp

TARGET = $$qtLibraryTarget(transmission)

DESTDIR = ../../plugins

EXAMPLE_FILES = transmission.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


