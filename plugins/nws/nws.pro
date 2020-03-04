include(nws.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = nws.h

SOURCES = nws.cpp

TARGET = $$qtLibraryTarget(nws)

DESTDIR = ../../plugins

EXAMPLE_FILES = nws.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


