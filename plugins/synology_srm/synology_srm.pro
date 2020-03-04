include(synology_srm.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = synology_srm.h

SOURCES = synology_srm.cpp

TARGET = $$qtLibraryTarget(synology_srm)

DESTDIR = ../../plugins

EXAMPLE_FILES = synology_srm.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


