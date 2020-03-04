include(nuki.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = nuki.h

SOURCES = nuki.cpp

TARGET = $$qtLibraryTarget(nuki)

DESTDIR = ../../plugins

EXAMPLE_FILES = nuki.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


