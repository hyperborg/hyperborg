include(swisscom.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = swisscom.h

SOURCES = swisscom.cpp

TARGET = $$qtLibraryTarget(swisscom)

DESTDIR = ../../plugins

EXAMPLE_FILES = swisscom.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


