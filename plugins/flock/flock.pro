include(flock.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = flock.h

SOURCES = flock.cpp

TARGET = $$qtLibraryTarget(flock)

DESTDIR = ../../plugins

EXAMPLE_FILES = flock.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


