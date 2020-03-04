include(verisure.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = verisure.h

SOURCES = verisure.cpp

TARGET = $$qtLibraryTarget(verisure)

DESTDIR = ../../plugins

EXAMPLE_FILES = verisure.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


