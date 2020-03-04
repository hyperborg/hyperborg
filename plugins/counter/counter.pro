include(counter.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = counter.h

SOURCES = counter.cpp

TARGET = $$qtLibraryTarget(counter)

DESTDIR = ../../plugins

EXAMPLE_FILES = counter.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


