include(zestimate.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = zestimate.h

SOURCES = zestimate.cpp

TARGET = $$qtLibraryTarget(zestimate)

DESTDIR = ../../plugins

EXAMPLE_FILES = zestimate.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


