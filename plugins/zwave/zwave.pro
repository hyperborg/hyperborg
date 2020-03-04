include(zwave.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = zwave.h

SOURCES = zwave.cpp

TARGET = $$qtLibraryTarget(zwave)

DESTDIR = ../../plugins

EXAMPLE_FILES = zwave.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


