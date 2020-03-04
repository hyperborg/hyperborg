include(ifttt.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ifttt.h

SOURCES = ifttt.cpp

TARGET = $$qtLibraryTarget(ifttt)

DESTDIR = ../../plugins

EXAMPLE_FILES = ifttt.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


