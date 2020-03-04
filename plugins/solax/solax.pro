include(solax.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = solax.h

SOURCES = solax.cpp

TARGET = $$qtLibraryTarget(solax)

DESTDIR = ../../plugins

EXAMPLE_FILES = solax.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


