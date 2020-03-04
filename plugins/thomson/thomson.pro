include(thomson.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = thomson.h

SOURCES = thomson.cpp

TARGET = $$qtLibraryTarget(thomson)

DESTDIR = ../../plugins

EXAMPLE_FILES = thomson.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


