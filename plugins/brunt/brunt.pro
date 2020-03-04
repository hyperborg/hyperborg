include(brunt.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = brunt.h

SOURCES = brunt.cpp

TARGET = $$qtLibraryTarget(brunt)

DESTDIR = ../../plugins

EXAMPLE_FILES = brunt.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


