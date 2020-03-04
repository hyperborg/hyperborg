include(lametric.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = lametric.h

SOURCES = lametric.cpp

TARGET = $$qtLibraryTarget(lametric)

DESTDIR = ../../plugins

EXAMPLE_FILES = lametric.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


