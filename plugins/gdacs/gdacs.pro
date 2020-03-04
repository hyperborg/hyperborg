include(gdacs.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = gdacs.h

SOURCES = gdacs.cpp

TARGET = $$qtLibraryTarget(gdacs)

DESTDIR = ../../plugins

EXAMPLE_FILES = gdacs.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


