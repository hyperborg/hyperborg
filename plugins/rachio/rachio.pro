include(rachio.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = rachio.h

SOURCES = rachio.cpp

TARGET = $$qtLibraryTarget(rachio)

DESTDIR = ../../plugins

EXAMPLE_FILES = rachio.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


