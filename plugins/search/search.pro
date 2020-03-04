include(search.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = search.h

SOURCES = search.cpp

TARGET = $$qtLibraryTarget(search)

DESTDIR = ../../plugins

EXAMPLE_FILES = search.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


