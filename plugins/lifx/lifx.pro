include(lifx.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = lifx.h

SOURCES = lifx.cpp

TARGET = $$qtLibraryTarget(lifx)

DESTDIR = ../../plugins

EXAMPLE_FILES = lifx.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


