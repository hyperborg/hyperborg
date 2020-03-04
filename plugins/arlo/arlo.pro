include(arlo.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = arlo.h

SOURCES = arlo.cpp

TARGET = $$qtLibraryTarget(arlo)

DESTDIR = ../../plugins

EXAMPLE_FILES = arlo.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


