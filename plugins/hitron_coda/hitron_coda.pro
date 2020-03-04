include(hitron_coda.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = hitron_coda.h

SOURCES = hitron_coda.cpp

TARGET = $$qtLibraryTarget(hitron_coda)

DESTDIR = ../../plugins

EXAMPLE_FILES = hitron_coda.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


