include(smarthab.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = smarthab.h

SOURCES = smarthab.cpp

TARGET = $$qtLibraryTarget(smarthab)

DESTDIR = ../../plugins

EXAMPLE_FILES = smarthab.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


