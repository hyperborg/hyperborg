include(flic.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = flic.h

SOURCES = flic.cpp

TARGET = $$qtLibraryTarget(flic)

DESTDIR = ../../plugins

EXAMPLE_FILES = flic.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


