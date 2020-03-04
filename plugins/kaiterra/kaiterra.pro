include(kaiterra.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = kaiterra.h

SOURCES = kaiterra.cpp

TARGET = $$qtLibraryTarget(kaiterra)

DESTDIR = ../../plugins

EXAMPLE_FILES = kaiterra.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


