include(everlights.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = everlights.h

SOURCES = everlights.cpp

TARGET = $$qtLibraryTarget(everlights)

DESTDIR = ../../plugins

EXAMPLE_FILES = everlights.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


