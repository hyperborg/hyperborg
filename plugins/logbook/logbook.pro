include(logbook.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = logbook.h

SOURCES = logbook.cpp

TARGET = $$qtLibraryTarget(logbook)

DESTDIR = ../../plugins

EXAMPLE_FILES = logbook.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


