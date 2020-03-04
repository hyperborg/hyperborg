include(opnsense.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = opnsense.h

SOURCES = opnsense.cpp

TARGET = $$qtLibraryTarget(opnsense)

DESTDIR = ../../plugins

EXAMPLE_FILES = opnsense.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


