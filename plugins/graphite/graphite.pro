include(graphite.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = graphite.h

SOURCES = graphite.cpp

TARGET = $$qtLibraryTarget(graphite)

DESTDIR = ../../plugins

EXAMPLE_FILES = graphite.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


