include(traccar.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = traccar.h

SOURCES = traccar.cpp

TARGET = $$qtLibraryTarget(traccar)

DESTDIR = ../../plugins

EXAMPLE_FILES = traccar.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


