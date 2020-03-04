include(cover.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = cover.h

SOURCES = cover.cpp

TARGET = $$qtLibraryTarget(cover)

DESTDIR = ../../plugins

EXAMPLE_FILES = cover.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


