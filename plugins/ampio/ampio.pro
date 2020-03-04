include(ampio.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ampio.h

SOURCES = ampio.cpp

TARGET = $$qtLibraryTarget(ampio)

DESTDIR = ../../plugins

EXAMPLE_FILES = ampio.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


