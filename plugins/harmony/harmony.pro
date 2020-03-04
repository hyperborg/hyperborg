include(harmony.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = harmony.h

SOURCES = harmony.cpp

TARGET = $$qtLibraryTarget(harmony)

DESTDIR = ../../plugins

EXAMPLE_FILES = harmony.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


