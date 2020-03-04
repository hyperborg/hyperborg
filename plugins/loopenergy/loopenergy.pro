include(loopenergy.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = loopenergy.h

SOURCES = loopenergy.cpp

TARGET = $$qtLibraryTarget(loopenergy)

DESTDIR = ../../plugins

EXAMPLE_FILES = loopenergy.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


