include(dominos.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = dominos.h

SOURCES = dominos.cpp

TARGET = $$qtLibraryTarget(dominos)

DESTDIR = ../../plugins

EXAMPLE_FILES = dominos.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


