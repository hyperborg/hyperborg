include(wemo.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = wemo.h

SOURCES = wemo.cpp

TARGET = $$qtLibraryTarget(wemo)

DESTDIR = ../../plugins

EXAMPLE_FILES = wemo.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


