include(pioneer.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = pioneer.h

SOURCES = pioneer.cpp

TARGET = $$qtLibraryTarget(pioneer)

DESTDIR = ../../plugins

EXAMPLE_FILES = pioneer.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


