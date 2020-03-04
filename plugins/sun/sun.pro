include(sun.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sun.h

SOURCES = sun.cpp

TARGET = $$qtLibraryTarget(sun)

DESTDIR = ../../plugins

EXAMPLE_FILES = sun.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


