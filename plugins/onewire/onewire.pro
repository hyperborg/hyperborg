include(onewire.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = onewire.h

SOURCES = onewire.cpp

TARGET = $$qtLibraryTarget(onewire)

DESTDIR = ../../plugins

EXAMPLE_FILES = onewire.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


