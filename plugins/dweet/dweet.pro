include(dweet.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = dweet.h

SOURCES = dweet.cpp

TARGET = $$qtLibraryTarget(dweet)

DESTDIR = ../../plugins

EXAMPLE_FILES = dweet.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


