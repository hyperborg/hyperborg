include(lannouncer.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = lannouncer.h

SOURCES = lannouncer.cpp

TARGET = $$qtLibraryTarget(lannouncer)

DESTDIR = ../../plugins

EXAMPLE_FILES = lannouncer.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


