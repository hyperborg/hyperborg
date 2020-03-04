include(aurora.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = aurora.h

SOURCES = aurora.cpp

TARGET = $$qtLibraryTarget(aurora)

DESTDIR = ../../plugins

EXAMPLE_FILES = aurora.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


