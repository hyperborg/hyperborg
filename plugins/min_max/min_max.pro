include(min_max.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = min_max.h

SOURCES = min_max.cpp

TARGET = $$qtLibraryTarget(min_max)

DESTDIR = ../../plugins

EXAMPLE_FILES = min_max.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


