include(mopar.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mopar.h

SOURCES = mopar.cpp

TARGET = $$qtLibraryTarget(mopar)

DESTDIR = ../../plugins

EXAMPLE_FILES = mopar.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


