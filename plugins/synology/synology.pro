include(synology.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = synology.h

SOURCES = synology.cpp

TARGET = $$qtLibraryTarget(synology)

DESTDIR = ../../plugins

EXAMPLE_FILES = synology.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


