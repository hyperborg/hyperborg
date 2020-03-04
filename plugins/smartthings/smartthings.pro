include(smartthings.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = smartthings.h

SOURCES = smartthings.cpp

TARGET = $$qtLibraryTarget(smartthings)

DESTDIR = ../../plugins

EXAMPLE_FILES = smartthings.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


