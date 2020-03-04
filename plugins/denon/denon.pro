include(denon.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = denon.h

SOURCES = denon.cpp

TARGET = $$qtLibraryTarget(denon)

DESTDIR = ../../plugins

EXAMPLE_FILES = denon.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


