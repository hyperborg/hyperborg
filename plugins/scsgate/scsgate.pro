include(scsgate.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = scsgate.h

SOURCES = scsgate.cpp

TARGET = $$qtLibraryTarget(scsgate)

DESTDIR = ../../plugins

EXAMPLE_FILES = scsgate.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


