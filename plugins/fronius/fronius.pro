include(fronius.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = fronius.h

SOURCES = fronius.cpp

TARGET = $$qtLibraryTarget(fronius)

DESTDIR = ../../plugins

EXAMPLE_FILES = fronius.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


