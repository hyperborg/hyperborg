include(spc.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = spc.h

SOURCES = spc.cpp

TARGET = $$qtLibraryTarget(spc)

DESTDIR = ../../plugins

EXAMPLE_FILES = spc.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


