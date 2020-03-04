include(canary.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = canary.h

SOURCES = canary.cpp

TARGET = $$qtLibraryTarget(canary)

DESTDIR = ../../plugins

EXAMPLE_FILES = canary.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


