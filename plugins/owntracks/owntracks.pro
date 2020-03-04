include(owntracks.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = owntracks.h

SOURCES = owntracks.cpp

TARGET = $$qtLibraryTarget(owntracks)

DESTDIR = ../../plugins

EXAMPLE_FILES = owntracks.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


