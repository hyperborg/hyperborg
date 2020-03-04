include(map.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = map.h

SOURCES = map.cpp

TARGET = $$qtLibraryTarget(map)

DESTDIR = ../../plugins

EXAMPLE_FILES = map.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


