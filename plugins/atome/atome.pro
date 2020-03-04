include(atome.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = atome.h

SOURCES = atome.cpp

TARGET = $$qtLibraryTarget(atome)

DESTDIR = ../../plugins

EXAMPLE_FILES = atome.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


