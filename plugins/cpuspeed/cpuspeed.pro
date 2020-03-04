include(cpuspeed.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = cpuspeed.h

SOURCES = cpuspeed.cpp

TARGET = $$qtLibraryTarget(cpuspeed)

DESTDIR = ../../plugins

EXAMPLE_FILES = cpuspeed.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


