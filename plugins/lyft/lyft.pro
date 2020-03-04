include(lyft.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = lyft.h

SOURCES = lyft.cpp

TARGET = $$qtLibraryTarget(lyft)

DESTDIR = ../../plugins

EXAMPLE_FILES = lyft.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


