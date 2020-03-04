include(deutsche_bahn.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = deutsche_bahn.h

SOURCES = deutsche_bahn.cpp

TARGET = $$qtLibraryTarget(deutsche_bahn)

DESTDIR = ../../plugins

EXAMPLE_FILES = deutsche_bahn.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


