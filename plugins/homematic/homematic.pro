include(homematic.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = homematic.h

SOURCES = homematic.cpp

TARGET = $$qtLibraryTarget(homematic)

DESTDIR = ../../plugins

EXAMPLE_FILES = homematic.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


