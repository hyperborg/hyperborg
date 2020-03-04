include(volumio.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = volumio.h

SOURCES = volumio.cpp

TARGET = $$qtLibraryTarget(volumio)

DESTDIR = ../../plugins

EXAMPLE_FILES = volumio.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


