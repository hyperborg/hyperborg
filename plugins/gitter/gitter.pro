include(gitter.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = gitter.h

SOURCES = gitter.cpp

TARGET = $$qtLibraryTarget(gitter)

DESTDIR = ../../plugins

EXAMPLE_FILES = gitter.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


