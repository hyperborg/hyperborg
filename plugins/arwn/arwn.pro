include(arwn.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = arwn.h

SOURCES = arwn.cpp

TARGET = $$qtLibraryTarget(arwn)

DESTDIR = ../../plugins

EXAMPLE_FILES = arwn.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


