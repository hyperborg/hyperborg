include(group.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = group.h

SOURCES = group.cpp

TARGET = $$qtLibraryTarget(group)

DESTDIR = ../../plugins

EXAMPLE_FILES = group.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


