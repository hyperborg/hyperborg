include(xs1.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = xs1.h

SOURCES = xs1.cpp

TARGET = $$qtLibraryTarget(xs1)

DESTDIR = ../../plugins

EXAMPLE_FILES = xs1.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


