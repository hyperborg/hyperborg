include(gearbest.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = gearbest.h

SOURCES = gearbest.cpp

TARGET = $$qtLibraryTarget(gearbest)

DESTDIR = ../../plugins

EXAMPLE_FILES = gearbest.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


