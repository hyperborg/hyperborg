include(vesync.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = vesync.h

SOURCES = vesync.cpp

TARGET = $$qtLibraryTarget(vesync)

DESTDIR = ../../plugins

EXAMPLE_FILES = vesync.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


