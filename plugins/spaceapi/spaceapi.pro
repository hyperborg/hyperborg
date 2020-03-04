include(spaceapi.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = spaceapi.h

SOURCES = spaceapi.cpp

TARGET = $$qtLibraryTarget(spaceapi)

DESTDIR = ../../plugins

EXAMPLE_FILES = spaceapi.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


