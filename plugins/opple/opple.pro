include(opple.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = opple.h

SOURCES = opple.cpp

TARGET = $$qtLibraryTarget(opple)

DESTDIR = ../../plugins

EXAMPLE_FILES = opple.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


