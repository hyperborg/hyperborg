include(generic.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = generic.h

SOURCES = generic.cpp

TARGET = $$qtLibraryTarget(generic)

DESTDIR = ../../plugins

EXAMPLE_FILES = generic.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


