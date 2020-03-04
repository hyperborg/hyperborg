include(sense.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sense.h

SOURCES = sense.cpp

TARGET = $$qtLibraryTarget(sense)

DESTDIR = ../../plugins

EXAMPLE_FILES = sense.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


