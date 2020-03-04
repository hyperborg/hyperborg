include(nut.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = nut.h

SOURCES = nut.cpp

TARGET = $$qtLibraryTarget(nut)

DESTDIR = ../../plugins

EXAMPLE_FILES = nut.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


