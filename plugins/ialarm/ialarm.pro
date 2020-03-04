include(ialarm.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ialarm.h

SOURCES = ialarm.cpp

TARGET = $$qtLibraryTarget(ialarm)

DESTDIR = ../../plugins

EXAMPLE_FILES = ialarm.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


