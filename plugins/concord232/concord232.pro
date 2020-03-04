include(concord232.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = concord232.h

SOURCES = concord232.cpp

TARGET = $$qtLibraryTarget(concord232)

DESTDIR = ../../plugins

EXAMPLE_FILES = concord232.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


