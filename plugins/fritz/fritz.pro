include(fritz.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = fritz.h

SOURCES = fritz.cpp

TARGET = $$qtLibraryTarget(fritz)

DESTDIR = ../../plugins

EXAMPLE_FILES = fritz.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


