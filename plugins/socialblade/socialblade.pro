include(socialblade.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = socialblade.h

SOURCES = socialblade.cpp

TARGET = $$qtLibraryTarget(socialblade)

DESTDIR = ../../plugins

EXAMPLE_FILES = socialblade.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


