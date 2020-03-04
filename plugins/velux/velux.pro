include(velux.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = velux.h

SOURCES = velux.cpp

TARGET = $$qtLibraryTarget(velux)

DESTDIR = ../../plugins

EXAMPLE_FILES = velux.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


