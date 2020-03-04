include(lutron_caseta.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = lutron_caseta.h

SOURCES = lutron_caseta.cpp

TARGET = $$qtLibraryTarget(lutron_caseta)

DESTDIR = ../../plugins

EXAMPLE_FILES = lutron_caseta.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


