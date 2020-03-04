include(deluge.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = deluge.h

SOURCES = deluge.cpp

TARGET = $$qtLibraryTarget(deluge)

DESTDIR = ../../plugins

EXAMPLE_FILES = deluge.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


