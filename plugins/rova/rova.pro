include(rova.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = rova.h

SOURCES = rova.cpp

TARGET = $$qtLibraryTarget(rova)

DESTDIR = ../../plugins

EXAMPLE_FILES = rova.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


