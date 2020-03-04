include(avri.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = avri.h

SOURCES = avri.cpp

TARGET = $$qtLibraryTarget(avri)

DESTDIR = ../../plugins

EXAMPLE_FILES = avri.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


