include(logentries.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = logentries.h

SOURCES = logentries.cpp

TARGET = $$qtLibraryTarget(logentries)

DESTDIR = ../../plugins

EXAMPLE_FILES = logentries.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


