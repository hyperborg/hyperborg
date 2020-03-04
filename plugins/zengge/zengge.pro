include(zengge.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = zengge.h

SOURCES = zengge.cpp

TARGET = $$qtLibraryTarget(zengge)

DESTDIR = ../../plugins

EXAMPLE_FILES = zengge.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


